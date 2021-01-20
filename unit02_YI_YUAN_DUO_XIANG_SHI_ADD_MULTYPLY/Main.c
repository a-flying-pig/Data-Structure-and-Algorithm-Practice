/*
 * Main.c
 *
 *  Created on: 2020��4��21��
 *      Author: zhuhua
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define DBG false

typedef struct PolyNode* Polynomial;
struct PolyNode {
	int coef;
	int expon;
	Polynomial link;
};

Polynomial ReadPoly();
Polynomial Mult(Polynomial P1, Polynomial P2);
Polynomial Mult1(Polynomial P1, Polynomial P2);
Polynomial Add(Polynomial P1, Polynomial P2);
Polynomial MultOne(Polynomial one, Polynomial P, Polynomial* pP);
void Insert(int c, int e, Polynomial* pP);
void PrintPoly(Polynomial P);
void Attach(int c, int e, Polynomial *Rear);
void DeletePoly(Polynomial* P);
int main() {
	// �� 2 2 2 1 1
	// 2 1 1 1 0
	// ��֤
	setvbuf(stdout, NULL, _IONBF, 0);// �����������

	Polynomial P1, P2, PP, PS;
	// �������ʽ1
	P1 = ReadPoly();
	PrintPoly(P1);

	// �������ʽ2
	P2 = ReadPoly();
	PrintPoly(P2);

	// �ӷ����㲢���
	PS = Add(P1, P2);
	PrintPoly(PS);
	// �˷����㲢���
    PP = Mult1(P1, P2);
	PrintPoly(PP);

	return 0;
}

Polynomial ReadPoly() {
	int c, e, N;
	Polynomial Rear, P, Temp;
	Rear = (Polynomial) malloc(sizeof(struct PolyNode));
	Rear->coef = 0;
	Rear->expon = 0;
	Rear->link = NULL;

	P = Rear;

	scanf("%d", &N);
	if(DBG) printf("N is %d\n", N);

	while(N--) {
		scanf("%d %d", &c, &e);
		if(DBG) printf("%d %d\n", c, e);
		Attach(c, e, &Rear);
	}

	Temp = P; /* ɾ����ʱ���ɵ�ͷ��� */
	P = P->link;
	free(Temp);
	if(DBG) printf("ReadPoly finish\n");
	return P;
}

// ���˷�ת��Ϊ�ӷ�����P1�������P2��ÿ�Ȼ�����
Polynomial Mult(Polynomial P1, Polynomial P2) {
	Polynomial t1, t2, P, Temp;
	P = (Polynomial) malloc(sizeof(struct PolyNode));
	P->coef = 0;
	P->expon = 0;
	P->link = NULL;
	t1 = P1;
	t2 = P2;
	printf(" Mult start\n");
	// P1�е�һ�����P2�еĸ���
/*	while(t2) {
		Attach(t1->coef * t2->coef, t1->expon + t2->expon, &Rear); // ϵ����ˣ�ָ�����
		t2 = t2->link;
	}*/

	MultOne(t1, t2, &P);

	Temp = P;
	P = P->link; // ���P1��һ�����P2����Ľ�������ں������
	free(Temp);

	printf(" Get first \n");
	PrintPoly(P);

	t1 = t1->link; // ��P1�ڶ��ʼ
	while(t1) {
		printf(" start second \n");
		Polynomial Ptemp, Temp;
		Ptemp = (Polynomial) malloc (sizeof(struct PolyNode));
		t2 = P2;
/*
		while(t2) {
			Attach(t1->coef * t2->coef, t1->expon + t2->expon, &Rear); // ϵ����ˣ�ָ�����
			t2 = t2->link;
		}
*/
        MultOne(t1, t2, &Ptemp);

		Temp = P1;
		Ptemp = Ptemp->link;
		free(Temp);
		printf(" start add \n");
		P = Add(P, Ptemp); // ���µĶ���ʽ���
		printf("add end and start delete \n");
		DeletePoly(&Ptemp); // ɾ����ʱ�Ķ���ʽ��free�ڴ�

		t1 = t1->link;
	}

	return P;
}

// ÿ�������Ȼ�����
Polynomial Mult1(Polynomial P1, Polynomial P2) {
	printf("Mult1 start\n");
	if(!P1 || !P2) {
		printf("P1 :%p  P2 :%p, return", P1, P2);
		return NULL;
	}
	Polynomial P, Rear, t1, t2, Temp;

	P = (struct PolyNode*)malloc(sizeof(struct PolyNode));
	P->coef = -1;
	P->expon = -1;
	P->link = NULL;

	t1 = P1;
	t2 = P2;
	while(t1) {
		t2 = P2; // t2��Ҫ���¸��ƣ���Ϊ�Ѿ�ָ��ĩβ��
		while(t2) {
			Rear = P; // ÿ�δ���P����ΪRear�Ѿ����ı���
			Insert(t1->coef * t2->coef, t1->expon + t2->expon, &Rear);
			if(DBG) printf("Mult1 pint P after insert \n");
			if(DBG) PrintPoly(P->link);
			t2 = t2->link;
		}
		t1 = t1->link;
	}

	Temp = P;
	P = Temp->link;
	free(Temp);

	printf("Mult1 end\n");
	return P;
}

void Insert(int c, int e, Polynomial* pP) {
	if(DBG) printf("Insert start\n");
	while(((*pP)->link) && (*pP)->link->expon > e) { // ��һ������ʱ����ģ��ӵ�һ�����һ����ʼ�ң�
		                                             // �ҵ�����㣬(*pP)->linkΪ����ڵ�
		(*pP) = (*pP)->link;
		if(DBG) printf("Insert (*pP)->expon:%d\n", (*pP)->expon);
	}

	if(!(*pP)->link) { // �ڽ�β��ӽڵ�
		if(DBG) printf("Insert Attach, (*pP)->expon:%d\n", (*pP)->expon);
		Attach(c, e, pP);
	} else { // ���ڽ�β�����������expon�Ƿ����
		if(DBG) printf("Insert before (*pP)->link->expon == e \n");
		if((*pP)->link->expon == e) { //���
			printf("Insert (*pP)->link->expon == e \n");
			int coef = (*pP)->link->coef + c;
			if(coef == 0) { // ϵ��Ϊ0��ɾ����
				Polynomial Pdelete = (*pP)->link;
				(*pP)->link = Pdelete->link;
				free(Pdelete);
			} else { //// ϵ����0�����ĸ����ϵ��
				(*pP)->link->coef = coef;
			}
		} else { // ����õ� (�϶� (*pP)->link->expon < e, ��Ϊ��һ���� > e,��һ��ֻ����Ȼ���С��)
			if(DBG) printf("Insert (*pP)->link->expon < e \n");
			Polynomial temp = (Polynomial) malloc(sizeof(struct PolyNode));
			temp->coef = c;
			temp->expon = e;
			temp->link = NULL;

			temp->link = (*pP)->link;
			(*pP)->link = temp;
		}
	}
}

Polynomial Add(Polynomial P1, Polynomial P2) {
	Polynomial P, Rear, Temp;
	P = (Polynomial) malloc(sizeof(struct PolyNode));
	P->coef = 0;
	P->expon = 0;
	P->link = NULL;
	Rear = P;

	// ָ����ͬ��ϵ����ӣ�����ӵ��µĶ���ʽP��

	while (P1&& P1) {
		if (P1->expon == P2->expon) { // ָ�����
			if ((P1->coef + P2->coef) != 0) { // ϵ����Ϊ0��ϵ�����
				Attach(P1->coef + P2->coef, P1->expon, &Rear);
			}
			P1 = P1->link;
			P2 = P2->link;
		} else if (P1->expon > P2->expon) { // P1 ϵ����
			Attach(P1->coef, P1->expon, &Rear);
			P1 = P1->link;
		} else if (P1->expon < P2->expon) { // P2 ϵ����
			Attach(P2->coef, P2->expon, &Rear);
			P2 = P2->link;
		}
	}

	// ʣ�µ�һ������ʽ�ĺ�ߵ�����ӵ��µĶ���ʽ��
	while(P1) {
		Attach(P1->coef, P1->expon, &Rear);
		P1 = P1->link;
	}
	while(P2) {
		Attach(P2->coef, P2->expon, &Rear);
		P2 = P2->link;
	}

	Temp = P;
	P = P->link;
	free(Temp);

	return P;
}

void PrintPoly(Polynomial P) {
	int flag = 0;
	while (P) {
		if(flag == 0) {
			flag = 1;
			printf("%d %d", P->coef, P->expon);
		} else {
			printf(" %d %d", P->coef, P->expon);
		}
		P = P->link;
	}
	printf("\n");
}

void Attach(int c, int e, Polynomial *pRear) {
	Polynomial P = (Polynomial) malloc(sizeof(struct PolyNode));
	P->coef = c; /* ���½ڵ㸳ֵ */
	P->expon = e;
	P->link = NULL;

	(*pRear)->link = P;
	(*pRear) = P; /* �޸�pRrearֵ */
}

// 1�������1������ʽ
Polynomial MultOne(Polynomial one, Polynomial P, Polynomial* pP) {
	Polynomial Rear;
	Rear = *pP;
	while(P) {
		Attach(one->coef * P->coef, one->expon + P->expon, &Rear); // ϵ����ˣ�ָ�����
		P = P->link;
	}

	return *pP;
}

// ɾ������ʽ
void DeletePoly(Polynomial* P) {
	Polynomial temp;
	while(*P) {
		temp = *P;
		free(temp);
		*P = (*P)->link;
	}
}

