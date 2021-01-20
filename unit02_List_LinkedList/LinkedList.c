#include<stdio.h>
#include<malloc.h>

#define bool char;
#define true 1;
#define false 0;

typedef int ElementType;

typedef struct LNode* PtrToLNode;

struct LNode {
	ElementType Data;
	PtrToLNode next;
};

typedef PtrToLNode Position;
typedef PtrToLNode List;


Position FindPositionPre(List L, Position P, Position* pre);

/* find */
#define ERROR NULL
Position Find(List L, ElementType X) {
	Position tmp = L; /* p指向L的第1个结点 */
	//printf("before while circle\n");
	while((tmp != NULL) && (tmp->Data != X)) {
		tmp = tmp->next;
		//printf("in while circle\n");
	}
	//printf("after while circle\n");
	/*下列语句可用 return tmp; 替换 */
	if(tmp != NULL) {
		printf("find element : %d\n", tmp->Data);
		return tmp;
	} else {
		printf("can't find element return null\n");
		return ERROR;
	}

}

/* 带头结点的插入 */
/* 注意：在插入位置参数P上与课程视频有所不同，课程视频中是序列位序（从1开始），这里P是链表结点指针，在P之前插入新结点 */
bool Insert(List* Pl, ElementType X, Position P) {
	Position tmp, pre; /* 这里默认L有头结点 */
	// 如果插入的P为头结点的位置，此为特殊情况，此时P没有前一个结点,直接将P插入到前边
	if (*Pl == P) {
		PtrToLNode tmp = (PtrToLNode) malloc(sizeof(struct LNode));
		tmp->Data = X;
		tmp->next = *Pl;
		*Pl = tmp; /* 将头结点换为新插入节点 */
	    return true;
	}

	//for(pre = *Pl; (pre != NULL) && pre->next != P; pre = pre->next); /* 查找P的前一个结点 */
	pre = *Pl;
	FindPositionPre(*Pl, P, &pre); /* 查找P的前一个结点 */
	if(pre == NULL){ /* P所指的结点不在L中 */
		printf("位置错误\n");
		return false;
	} else { /* 找到了P的前一个结点pre */
		/* 在P前插入新结点 */
		PtrToLNode tmp = (PtrToLNode) malloc(sizeof(struct LNode));
		tmp->Data = X;
		tmp->next = pre->next;
		pre->next = tmp;
	    return true;
	}
}

/* 带头结点的删除 */
/* 注意：在删除位置参数P上与课程视频有所不同，课程视频中i是序列位序（从1开始），这里P是拟删除结点指针 */
bool Delete(List L, Position P) {
    Position pre;
    pre = L;
    FindPositionPre(L, P, &pre);
	/*for(pre = L; (pre != NULL) && pre->next != P; pre = pre->next);*/
    if(pre == NULL) {
    	printf("Delete 没有该元素，删除失败\n");
    	return false;
    } else {
    	printf("Delete pre 元素为：%d\n", pre->Data);
    	pre->next = P->next;
    	printf("Delete 删除的元素为：%d\n", P->Data);
    	free(P);
    	return true;
    }
}

/* 查找P结点的前1个结点 */
Position FindPositionPre(List L, Position P, Position* ppre) {
	printf("FindPositionPre data to Found data:%d\n", P->Data);
	for(*ppre = L; (*ppre != NULL) && (*ppre)->next != P; *ppre = (*ppre)->next);

	if(*ppre == NULL) {
		printf("FindPositionPre *ppre is null\n");
	} else {
		printf("FindPositionPre out for recircle *ppre data:%d\n", (*ppre)->Data);
	}
	return *ppre;
}

/* print list */
void PrintList(List L) {
	Position tmp;
    for(tmp = L; tmp != NULL; tmp = tmp->next) {
    	printf("%d ", tmp->Data);
    }
    printf("\n");
}

int main() {
	setvbuf(stdout,NULL,_IONBF,0);
	List mList = (List)malloc(sizeof(struct LNode));
	mList->Data = -1;
	mList->next = NULL;
	PrintList(mList);

	Insert(&mList, 5, mList);
	Insert(&mList, 6, mList);
	Insert(&mList, 7, mList);
	Insert(&mList, 8, mList);
	Insert(&mList,9, Find(mList, 6));
    printf("after  insert\n");
	PrintList(mList);
	printf("find 7\n");
	Find(mList, 7);
	printf("\n");

	printf("before delete 7\n");
	PrintList(mList);
	Position deleteP = Find(mList, 7);
	Delete(mList, deleteP);
	printf("after delete 7\n");
	PrintList(mList);
	printf("\n");
	return 0;
}
