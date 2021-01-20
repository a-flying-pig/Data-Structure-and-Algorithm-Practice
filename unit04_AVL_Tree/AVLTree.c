/*
 * AVLTree.c
 *
 *  Created on: 2020��6��5��
 *      Author: zhuhua
 */
#include <stdio.h>
#include <stdlib.h>

#include "AVLTree.h"
#include "LinkedQueue.h"

int Max(int a, int b) {
	return (a > b ? a : b);
}

AVLTree SingleLeftRotation(AVLTree A) {
	/*  ע�⣺A������һ�����ӽ��B */
	/* ��A��B������������A��B�ĸ߶ȣ������µĸ��ڵ�B */
	AVLTree B = A->Left;
	A->Left = B->Right;
	B->Right = A;
	A->Height = Max(GetHeight(A->Left), GetHeight(A->Right)) + 1;
	B->Height = Max(GetHeight(B->Left), A->Height) + 1;
	return B;
}

AVLTree SingleRightRotation(AVLTree A) {
	/* ע�⣺A������һ���ҽ��B */
	/* ��A��B���ҵ���������A��B�ĸ߶ȣ������µĸ��ڵ�B */
	AVLTree B = A->Right;
	A->Right = B->Left;
	B->Left = A;
	A->Height = Max(GetHeight(A->Left), GetHeight(A->Right)) + 1;
	B->Height = Max(A->Height, GetHeight(B->Right)) + 1;
	return B;
}

AVLTree DoubleLeftRightRotation(AVLTree A) {
	/* ע�⣺A������һ������B����B������һ���ҽ��C */
	/* ��A��B��C��2�ε����������µĸ��ڵ�C */

	/* ��B��C���ҵ�����C������ */
	A->Left = SingleRightRotation(A->Left);
	/* ��A��C��������C������ */
	return SingleLeftRotation(A);
}

AVLTree DoubleRightLeftRotation(AVLTree A) {
	/* ע�⣺A������һ���ҽ��B����B������һ������C */
	/* ��A��B��C��2�ε����������µĽڵ�C */

	/* ��B��C��������C������ */
	A->Right = SingleLeftRotation(A->Left);
	/* ��A��C���ҵ�����C������ */
	return SingleRightRotation(A);
}


/*AVLTree Insert(AVLTree BST, ElementType X) {
	if (!BST) {
		BST = (AVLTree) malloc(sizeof(struct AVLNode));
		BST->Data = X;
		BST->Left = NULL;
		BST->Right = NULL;
	} else if (X < BST->Data) {
		//printf("X < BST->Data %d \n", BST->Data);
		BST->Left = Insert(BST->Left, X); // ���˲���Ķ���
	} else if (X > BST->Data) {
		//printf("X > BST->Data %d \n", BST->Data);
		//return BST->Right = Insert(X, BST->Right);
		BST->Right = Insert(BST->Right, X); // ���˲���Ķ���
	} else { // X �Ѿ����ڣ�ʲô������
		printf("The %d is already exist\n", X);
	}
	//printf("BST: %X \n", BST);
	return BST;
}*/

// *****
AVLTree Insert(AVLTree T, ElementType X) {
	 // ��X����AVL��T�У����ҷ��ص������AVL��
	if (!T) {  // ��������������½�����һ��������
		T = (AVLTree) malloc(sizeof(struct AVLNode));
		T->Data = X;
		T->Left = T->Right = NULL;
		T->Height = 0;
	} else if (X < T->Data) {
		 // ����T��������
		T->Left = Insert(T->Left, X);
		 // �����Ҫ����
		if (GetHeight(T->Left) - GetHeight(T->Right) == 2) {
			if (X < T->Left->Data) {
				 // ����
				T = SingleLeftRotation(T);
			} else { // (X > T->Left->Data) {
				 // ��-�� ˫��
				T = DoubleLeftRightRotation(T);
			}
		}

	} else if (X > T->Data) {
		T->Right = Insert(T->Right, X);
		// �����Ҫ����
		if (GetHeight(T->Right) - GetHeight(T->Left) == 2) {
			if (X > T->Right->Data) {  // �ҵ���
				T = SingleRightRotation(T);
			} else { //  ���� ˫��
				T = DoubleRightLeftRotation(T);
			}
		}
	}

	// else X == T->Data,�������

	 // �����˸�������
	T->Height = Max(GetHeight(T->Left), GetHeight(T->Right)) + 1;
	return T;
}

void printTree(AVLTree T) {
	if (T) {
		printTree(T->Left);
		printf("%d ", T->Data);
		printTree(T->Right);
	}
}

void LevelOrderTraversal(AVLTree BT) {
	printf(" LevelOrderTraversal \n");
	AVLTree T = BT;
	Queue q = createQueue();
	if (T) {
		enque(q, T);
	} else {
		printf(" tree is empty \n");
	}
	while(!isEmpty(q)) {
		printf(" *1*");
		AVLTree T = deque(q);

		printf(" *2* ");

		printf("%d ", T->Data);
		printf(" *3* ");
		if(T->Left) enque(q, T->Left);
		if(T->Right) enque(q, T->Right);
		printf(" *4* ");
		printf("\n");
		printQueue(q);
	}

}

AVLTree Delete(ElementType X, AVLTree T) {
	Position temp;
	if (!T) {
		printf("There is no %d in BST!\n", X);
		return NULL;
	}
	if (X < T->Data) {
		T->Left = Delete(X, T->Left);
	} else if (X > T->Data) {
		T->Right = Delete(X, T->Right);
	} else {
		if (T->Left && T->Right) {
			AVLTree leftMax = FindMax(T->Left);
			T->Data = leftMax->Data;
			T->Left = Delete(T->Data, T->Left);
		}
		temp = T;
		if (!T->Left) {
			T = T->Right;
			free(temp);
		} else if (!T->Right) {
			T = T->Left;
			free(temp);
		}
	}
	return T;
}

AVLTree FindMax(AVLTree BST) {
	if (!BST)
		return BST;
	if (BST->Right) {
		return FindMax(BST->Right);
	} else {
		return BST;
	}
}

int GetHeight(AVLTree A) {
	if (!A) {
		return 0;
	}
	int height = Max(GetHeight(A->Left), GetHeight(A->Right)) + 1;
	return height;
}

