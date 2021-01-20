/*
 * Main.c
 *
 *  Created on: 2020年4月21日
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
	// 用 2 2 2 1 1
	// 2 1 1 1 0
	// 验证
	setvbuf(stdout, NULL, _IONBF, 0);// 用于输出缓存

	Polynomial P1, P2, PP, PS;
	// 读入多项式1
	P1 = ReadPoly();
	PrintPoly(P1);

	// 读入多项式2
	P2 = ReadPoly();
	PrintPoly(P2);

	// 加法运算并输出
	PS = Add(P1, P2);
	PrintPoly(PS);
	// 乘法运算并输出
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

	Temp = P; /* 删除临时生成的头结点 */
	P = P->link;
	free(Temp);
	if(DBG) printf("ReadPoly finish\n");
	return P;
}

// 将乘法转化为加法，以P1的项乘以P2的每项，然后相加
Polynomial Mult(Polynomial P1, Polynomial P2) {
	Polynomial t1, t2, P, Temp;
	P = (Polynomial) malloc(sizeof(struct PolyNode));
	P->coef = 0;
	P->expon = 0;
	P->link = NULL;
	t1 = P1;
	t2 = P2;
	printf(" Mult start\n");
	// P1中的一项乘以P2中的各项
/*	while(t2) {
		Attach(t1->coef * t2->coef, t1->expon + t2->expon, &Rear); // 系数相乘，指数相加
		t2 = t2->link;
	}*/

	MultOne(t1, t2, &P);

	Temp = P;
	P = P->link; // 获得P1第一项乘以P2各项的结果，用于后续相加
	free(Temp);

	printf(" Get first \n");
	PrintPoly(P);

	t1 = t1->link; // 从P1第二项开始
	while(t1) {
		printf(" start second \n");
		Polynomial Ptemp, Temp;
		Ptemp = (Polynomial) malloc (sizeof(struct PolyNode));
		t2 = P2;
/*
		while(t2) {
			Attach(t1->coef * t2->coef, t1->expon + t2->expon, &Rear); // 系数相乘，指数相加
			t2 = t2->link;
		}
*/
        MultOne(t1, t2, &Ptemp);

		Temp = P1;
		Ptemp = Ptemp->link;
		free(Temp);
		printf(" start add \n");
		P = Add(P, Ptemp); // 将新的多项式相加
		printf("add end and start delete \n");
		DeletePoly(&Ptemp); // 删除临时的多项式，free内存

		t1 = t1->link;
	}

	return P;
}

// 每个项相乘然后插入
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
		t2 = P2; // t2需要重新复制，因为已经指到末尾了
		while(t2) {
			Rear = P; // 每次传入P，因为Rear已经被改变了
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
	while(((*pP)->link) && (*pP)->link->expon > e) { // 第一项是临时申请的，从第一项的下一个开始找，
		                                             // 找到插入点，(*pP)->link为插入节点
		(*pP) = (*pP)->link;
		if(DBG) printf("Insert (*pP)->expon:%d\n", (*pP)->expon);
	}

	if(!(*pP)->link) { // 在结尾添加节点
		if(DBG) printf("Insert Attach, (*pP)->expon:%d\n", (*pP)->expon);
		Attach(c, e, pP);
	} else { // 不在结尾，看后面的项expon是否相等
		if(DBG) printf("Insert before (*pP)->link->expon == e \n");
		if((*pP)->link->expon == e) { //相等
			printf("Insert (*pP)->link->expon == e \n");
			int coef = (*pP)->link->coef + c;
			if(coef == 0) { // 系数为0，删除项
				Polynomial Pdelete = (*pP)->link;
				(*pP)->link = Pdelete->link;
				free(Pdelete);
			} else { //// 系数不0，更改该项的系数
				(*pP)->link->coef = coef;
			}
		} else { // 插入该点 (肯定 (*pP)->link->expon < e, 因为上一项是 > e,下一项只能相等或者小于)
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

	// 指数相同，系数相加，并添加到新的多项式P中

	while (P1&& P1) {
		if (P1->expon == P2->expon) { // 指数相等
			if ((P1->coef + P2->coef) != 0) { // 系数不为0，系数相加
				Attach(P1->coef + P2->coef, P1->expon, &Rear);
			}
			P1 = P1->link;
			P2 = P2->link;
		} else if (P1->expon > P2->expon) { // P1 系数大
			Attach(P1->coef, P1->expon, &Rear);
			P1 = P1->link;
		} else if (P1->expon < P2->expon) { // P2 系数大
			Attach(P2->coef, P2->expon, &Rear);
			P2 = P2->link;
		}
	}

	// 剩下的一个多项式的后边的项添加到新的多项式中
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
	P->coef = c; /* 对新节点赋值 */
	P->expon = e;
	P->link = NULL;

	(*pRear)->link = P;
	(*pRear) = P; /* 修改pRrear值 */
}

// 1个项乘以1个多项式
Polynomial MultOne(Polynomial one, Polynomial P, Polynomial* pP) {
	Polynomial Rear;
	Rear = *pP;
	while(P) {
		Attach(one->coef * P->coef, one->expon + P->expon, &Rear); // 系数相乘，指数相加
		P = P->link;
	}

	return *pP;
}

// 删除多项式
void DeletePoly(Polynomial* P) {
	Polynomial temp;
	while(*P) {
		temp = *P;
		free(temp);
		*P = (*P)->link;
	}
}

