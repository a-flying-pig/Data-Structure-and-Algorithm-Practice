/*
 * Tree.h
 *
 *  Created on: 2020Äê5ÔÂ13ÈÕ
 *      Author: zhuhua
 */

#ifndef TREE_H_
#define TREE_H_

typedef char Data;
typedef struct TreeNode* Tree;

struct TreeNode {
	Data data;
	Tree left;
	Tree right;
};

Tree createTree();
void PreOrderTraversal(Tree BT);
void InOrderTraversal(Tree BT);
void PostOrderTraversal(Tree BT);

#endif /* TREE_H_ */
