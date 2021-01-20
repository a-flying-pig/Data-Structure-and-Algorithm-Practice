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
	Position tmp = L; /* pָ��L�ĵ�1����� */
	//printf("before while circle\n");
	while((tmp != NULL) && (tmp->Data != X)) {
		tmp = tmp->next;
		//printf("in while circle\n");
	}
	//printf("after while circle\n");
	/*���������� return tmp; �滻 */
	if(tmp != NULL) {
		printf("find element : %d\n", tmp->Data);
		return tmp;
	} else {
		printf("can't find element return null\n");
		return ERROR;
	}

}

/* ��ͷ���Ĳ��� */
/* ע�⣺�ڲ���λ�ò���P����γ���Ƶ������ͬ���γ���Ƶ��������λ�򣨴�1��ʼ��������P��������ָ�룬��P֮ǰ�����½�� */
bool Insert(List* Pl, ElementType X, Position P) {
	Position tmp, pre; /* ����Ĭ��L��ͷ��� */
	// ��������PΪͷ����λ�ã���Ϊ�����������ʱPû��ǰһ�����,ֱ�ӽ�P���뵽ǰ��
	if (*Pl == P) {
		PtrToLNode tmp = (PtrToLNode) malloc(sizeof(struct LNode));
		tmp->Data = X;
		tmp->next = *Pl;
		*Pl = tmp; /* ��ͷ��㻻Ϊ�²���ڵ� */
	    return true;
	}

	//for(pre = *Pl; (pre != NULL) && pre->next != P; pre = pre->next); /* ����P��ǰһ����� */
	pre = *Pl;
	FindPositionPre(*Pl, P, &pre); /* ����P��ǰһ����� */
	if(pre == NULL){ /* P��ָ�Ľ�㲻��L�� */
		printf("λ�ô���\n");
		return false;
	} else { /* �ҵ���P��ǰһ�����pre */
		/* ��Pǰ�����½�� */
		PtrToLNode tmp = (PtrToLNode) malloc(sizeof(struct LNode));
		tmp->Data = X;
		tmp->next = pre->next;
		pre->next = tmp;
	    return true;
	}
}

/* ��ͷ����ɾ�� */
/* ע�⣺��ɾ��λ�ò���P����γ���Ƶ������ͬ���γ���Ƶ��i������λ�򣨴�1��ʼ��������P����ɾ�����ָ�� */
bool Delete(List L, Position P) {
    Position pre;
    pre = L;
    FindPositionPre(L, P, &pre);
	/*for(pre = L; (pre != NULL) && pre->next != P; pre = pre->next);*/
    if(pre == NULL) {
    	printf("Delete û�и�Ԫ�أ�ɾ��ʧ��\n");
    	return false;
    } else {
    	printf("Delete pre Ԫ��Ϊ��%d\n", pre->Data);
    	pre->next = P->next;
    	printf("Delete ɾ����Ԫ��Ϊ��%d\n", P->Data);
    	free(P);
    	return true;
    }
}

/* ����P����ǰ1����� */
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
