/*
 * AVL_Tree.h
 *
 *  Created on: 2020年6月5日
 *      Author: zhuhua
 */

#ifndef AVLTREE_H_
#define AVLTREE_H_

#define ElementType int

typedef struct AVLNode* Position;
typedef Position AVLTree; /* AVL树类型 */

struct AVLNode {
	ElementType Data; /* 结点数据 */
	AVLTree Left;
	AVLTree Right;
	int Height; /* 树高 */
};

int Max(int a, int b);
AVLTree SingleLeftRotation(AVLTree A);
AVLTree DoubleLeftRightRotation(AVLTree A);

AVLTree SingleRightRotation(AVLTree A);
AVLTree DoubleRightLeftRotation(AVLTree A);

AVLTree Insert(AVLTree A, ElementType X);

AVLTree FindMax(AVLTree A);
AVLTree Delete(ElementType X, AVLTree A);
void printTree(AVLTree A);
void LevelOrderTraversal(AVLTree A);
int GetHeight(AVLTree A);
#endif /* AVLTREE_H_ */
