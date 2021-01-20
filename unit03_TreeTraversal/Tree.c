/*
 * Tree.c
 *
 *  Created on: 2020Äê5ÔÂ13ÈÕ
 *      Author: zhuhua
 */
#include <stdio.h>
#include "Tree.h"

Tree createTree() {
	Tree root = (Tree) malloc(sizeof(struct TreeNode));
	root->data = NULL;
	root->left = NULL;
	root->right = NULL;
	return root;
}

void PreOrderTraversal(Tree BT){
	if(BT) {
		printf("%c ", BT->data);
		PreOrderTraversal(BT->left);
		PreOrderTraversal(BT->right);
	}
}

void InOrderTraversal(Tree BT){
	if(BT){
		InOrderTraversal(BT->left);
		printf("%c ", BT->data);
		InOrderTraversal(BT->right);
	}
}

void PostOrderTraversal(Tree BT){
	if(BT){
		PostOrderTraversal(BT->left);
		PostOrderTraversal(BT->right);
		printf("%c ", BT->data);
	}
}


