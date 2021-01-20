/*
 * SequentialList.c
 *
 *  Created on: 2020年3月26日
 *      Author: zhuhua
 */
#include <stdio.h>
#include <stdbool.h>

/*
#define bool char; // 兼容老的编译器，也可以这么写，不引入stdbool.h
#define true 1;
#define false 0;
*/


typedef int ElementType;
// const int MAXSIZE = 16; 在C中只是只读的，非常量，而且也可以修改用*(int*)&MAXSIZE = 8;在c++中是常量，存在堆栈的特殊的位置
//#define MAXSIZE 16; // 缺点是匹配源码中所有的匹配的字符串，容易造成误替换
enum {
	MAXSIZE = 16
};
// 这个也可以
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

/* 初始化 */
List MakeEmpty() {
	List L;
	L = (List) malloc(sizeof(struct LNode));
	//printf("%d\n", sizeof(struct LNode));
	//printf("%d\n", sizeof(LNode));必须要有struct
	L->Last = -1;
	return L;
}

/* 查找 */
#define ERROR -1
Position Find(List L, ElementType X) {
	Position i = 0;

	while (L->Data[i] != X && i <= L->Last) {
		i++;
	}
	if (i > L->Last) { // 没有找到，返回错误信息
		return ERROR;
	} else {
		return i; /* 找到后返回的是存储位置 */
	}
}

/* 插入 */
/* 注意 ： P为存储下标位置，而课程中的P为序列位置（从1开始），两者差1 */
bool Insert(List L, ElementType X, Position P) {
    /* 在L的指定位置P前插入一个新元素X */
	if (L->Last == MAXSIZE - 1) { /* 表空间满，不能插入 */
		printf("表满\n");
		return false;
	}
	if (P < 0 || P > L->Last + 1) { /* 检查插入位置的合法性，不在范围内，位置错误 */
		printf("位置不合法\n");
		return false;
	}
	Position i = L->Last;
	for(i = L->Last; i >= P; i--) {
		L->Data[i+1] = L->Data[i]; /* 将位置P及以后的元素顺序向后移动 */
	}
	L->Data[P] = X; /* 新元素插入 */
	L->Last++; /* Last仍指向最后元素 */
	return true;
}

/* 删除 */
bool Delete(List L, Position P) {
	/* 从L中删除指定位置P的元素 */
    if (P < 0 || P > L->Last) { /* 检查空表及删除位置的合法性 */
    	printf("位置%d不存在元素\n", P);
    	return false;
    }

	Position i;
	for (i = P + 1; i <= L->Last; i++) {
		L->Data[i - 1] = L->Data[i]; /* 将P+1及以后的元素顺序向前移动*/
	}
	L->Last--; /* Last仍指向最后元素*/
	return true;
}

/* 访问元素 */
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
