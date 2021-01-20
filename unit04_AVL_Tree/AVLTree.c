/*
 * AVLTree.c
 *
 *  Created on: 2020年6月5日
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
	/*  注意：A必须有一个左子结点B */
	/* 将A与B做左单旋，更新A与B的高度，返回新的根节点B */
	AVLTree B = A->Left;
	A->Left = B->Right;
	B->Right = A;
	A->Height = Max(GetHeight(A->Left), GetHeight(A->Right)) + 1;
	B->Height = Max(GetHeight(B->Left), A->Height) + 1;
	return B;
}

AVLTree SingleRightRotation(AVLTree A) {
	/* 注意：A必须有一个右结点B */
	/* 将A与B做右单旋，更新A与B的高度，返回新的跟节点B */
	AVLTree B = A->Right;
	A->Right = B->Left;
	B->Left = A;
	A->Height = Max(GetHeight(A->Left), GetHeight(A->Right)) + 1;
	B->Height = Max(A->Height, GetHeight(B->Right)) + 1;
	return B;
}

AVLTree DoubleLeftRightRotation(AVLTree A) {
	/* 注意：A必须有一个左结点B，且B必须有一个右结点C */
	/* 将A、B与C做2次单旋，返回新的根节点C */

	/* 将B与C做右单旋，C被返回 */
	A->Left = SingleRightRotation(A->Left);
	/* 将A与C做左单旋，C被返回 */
	return SingleLeftRotation(A);
}

AVLTree DoubleRightLeftRotation(AVLTree A) {
	/* 注意：A必须有一个右结点B，且B必须有一个左结点C */
	/* 将A、B与C做2次单旋，返回新的节点C */

	/* 将B与C做左单旋，C被返回 */
	A->Right = SingleLeftRotation(A->Left);
	/* 将A与C做右单旋，C被返回 */
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
		BST->Left = Insert(BST->Left, X); // 做了插入的动作
	} else if (X > BST->Data) {
		//printf("X > BST->Data %d \n", BST->Data);
		//return BST->Right = Insert(X, BST->Right);
		BST->Right = Insert(BST->Right, X); // 做了插入的动作
	} else { // X 已经存在，什么都不做
		printf("The %d is already exist\n", X);
	}
	//printf("BST: %X \n", BST);
	return BST;
}*/

// *****
AVLTree Insert(AVLTree T, ElementType X) {
	 // 将X插入AVL树T中，并且返回调整后的AVL树
	if (!T) {  // 若插入空树，则新建包含一个结点的树
		T = (AVLTree) malloc(sizeof(struct AVLNode));
		T->Data = X;
		T->Left = T->Right = NULL;
		T->Height = 0;
	} else if (X < T->Data) {
		 // 插入T的左子树
		T->Left = Insert(T->Left, X);
		 // 如果需要左旋
		if (GetHeight(T->Left) - GetHeight(T->Right) == 2) {
			if (X < T->Left->Data) {
				 // 左单旋
				T = SingleLeftRotation(T);
			} else { // (X > T->Left->Data) {
				 // 左-右 双旋
				T = DoubleLeftRightRotation(T);
			}
		}

	} else if (X > T->Data) {
		T->Right = Insert(T->Right, X);
		// 如果需要右旋
		if (GetHeight(T->Right) - GetHeight(T->Left) == 2) {
			if (X > T->Right->Data) {  // 右单旋
				T = SingleRightRotation(T);
			} else { //  右左 双旋
				T = DoubleRightLeftRotation(T);
			}
		}
	}

	// else X == T->Data,无须插入

	 // 别忘了更新树高
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

