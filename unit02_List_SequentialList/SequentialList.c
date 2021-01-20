/*
 * SequentialList.c
 *
 *  Created on: 2020��3��26��
 *      Author: zhuhua
 */
#include <stdio.h>
#include <stdbool.h>

/*
#define bool char; // �����ϵı�������Ҳ������ôд��������stdbool.h
#define true 1;
#define false 0;
*/


typedef int ElementType;
// const int MAXSIZE = 16; ��C��ֻ��ֻ���ģ��ǳ���������Ҳ�����޸���*(int*)&MAXSIZE = 8;��c++���ǳ��������ڶ�ջ�������λ��
//#define MAXSIZE 16; // ȱ����ƥ��Դ�������е�ƥ����ַ���������������滻
enum {
	MAXSIZE = 16
};
// ���Ҳ����
typedef int Position;
typedef struct LNode *List;
struct LNode {
	ElementType Data[MAXSIZE];
	Position Last;
};

List MakeEmpty();
Position Find(List L, ElementType X);
bool Insert(List L, ElementType X, Position P);
bool Delete(List L, Position P);
void PrintList(List L);

int main() {
	List mList = MakeEmpty();
	printf("after MakeEmpty ");
	Insert(mList, 5, 0);
	Insert(mList, 6, 0);
	Insert(mList, 7, 0);
	Insert(mList, 8, 0);
	PrintList(mList);
	printf("\n");
	printf("find 7, %d", Find(mList, 7));
	printf("\n");
	Insert(mList, 10, 1);
	PrintList(mList);
	printf("\n");
	Delete(mList, 0);
	PrintList(mList);
	printf("\n");
	return 0;
}

/* ��ʼ�� */
List MakeEmpty() {
	List L;
	L = (List) malloc(sizeof(struct LNode));
	//printf("%d\n", sizeof(struct LNode));
	//printf("%d\n", sizeof(LNode));����Ҫ��struct
	L->Last = -1;
	return L;
}

/* ���� */
#define ERROR -1
Position Find(List L, ElementType X) {
	Position i = 0;

	while (L->Data[i] != X && i <= L->Last) {
		i++;
	}
	if (i > L->Last) { // û���ҵ������ش�����Ϣ
		return ERROR;
	} else {
		return i; /* �ҵ��󷵻ص��Ǵ洢λ�� */
	}
}

/* ���� */
/* ע�� �� PΪ�洢�±�λ�ã����γ��е�PΪ����λ�ã���1��ʼ�������߲�1 */
bool Insert(List L, ElementType X, Position P) {
    /* ��L��ָ��λ��Pǰ����һ����Ԫ��X */
	if (L->Last == MAXSIZE - 1) { /* ��ռ��������ܲ��� */
		printf("����\n");
		return false;
	}
	if (P < 0 || P > L->Last + 1) { /* ������λ�õĺϷ��ԣ����ڷ�Χ�ڣ�λ�ô��� */
		printf("λ�ò��Ϸ�\n");
		return false;
	}
	Position i = L->Last;
	for(i = L->Last; i >= P; i--) {
		L->Data[i+1] = L->Data[i]; /* ��λ��P���Ժ��Ԫ��˳������ƶ� */
	}
	L->Data[P] = X; /* ��Ԫ�ز��� */
	L->Last++; /* Last��ָ�����Ԫ�� */
	return true;
}

/* ɾ�� */
bool Delete(List L, Position P) {
	/* ��L��ɾ��ָ��λ��P��Ԫ�� */
    if (P < 0 || P > L->Last) { /* ���ձ�ɾ��λ�õĺϷ��� */
    	printf("λ��%d������Ԫ��\n", P);
    	return false;
    }

	Position i;
	for (i = P + 1; i <= L->Last; i++) {
		L->Data[i - 1] = L->Data[i]; /* ��P+1���Ժ��Ԫ��˳����ǰ�ƶ�*/
	}
	L->Last--; /* Last��ָ�����Ԫ��*/
	return true;
}

/* ����Ԫ�� */
void PrintList(List L) {
	for(Position i = 0; i <= L->Last; i++) {
		printf("%d ", L->Data[i]);
	}
}

/*int main() {
	List mList = MakeEmpty();
	printf("after MakeEmpty ");
	Insert(mList, 5, 0);
	Insert(mList, 6, 0);
	Insert(mList, 7, 0);
	Insert(mList, 8, 0);
	PrintList(mList);
	printf("\n");
	printf("find 7, %d", Find(mList, 7));
	printf("\n");
	Insert(mList, 10, 1);
	PrintList(mList);
	printf("\n");
	Delete(mList, 0);
	PrintList(mList);
	printf("\n");
	return 0;
}*/
