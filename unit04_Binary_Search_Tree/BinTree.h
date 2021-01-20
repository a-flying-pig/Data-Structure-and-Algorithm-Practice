/*
 * BinTree.h
 *
 *  Created on: 2020Äê5ÔÂ29ÈÕ
 *      Author: zhuhua
 */

#ifndef BINTREE_H_
#define BINTREE_H_

#define ElementType int
typedef struct TreeNode* Position;
typedef Position BinTree;
struct TreeNode {
	ElementType Data;
	BinTree Left;
	BinTree Right;
};

BinTree Insert(ElementType X, BinTree BST);
void printBinTree(BinTree BST);
BinTree Find(ElementType X, BinTree BST);
BinTree FindMax(BinTree BST);
BinTree FindMin(BinTree BST);
BinTree Delete(ElementType X, BinTree BST);

#endif /* BINTREE_H_ */
