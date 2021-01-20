/*
 * TreeTraversal.c
 *
 *  Created on: 2020年5月13日
 *      Author: zhuhua
 */
#include <stdio.h>
#include "Tree.h"

Tree BuildTree(Tree root);
int main() {
	setvbuf(stdout, NULL, _IONBF, 0);// 用于输出缓存
	//struct TreeNode root = {'A', NULL, NULL};
	Tree root = createTree();
	root = BuildTree(root);
	printf("PreOrderTraversal:\n");
	PreOrderTraversal(root);
	printf("\nInOrderTraversal:\n");
	InOrderTraversal(root);
	printf("\nPostOrderTraversal:\n");
	PostOrderTraversal(root);
	printf("\n");

	printf("\nLevelOrderTraversal:\n");
	LevelOrderTraversal(root);
	printf("\n");
	return 0;
}

Tree BuildTree(Tree root) {
	root->data = 'A';
	root->left = NULL;
	root->right = NULL;

	Tree B = (Tree) malloc(sizeof(struct TreeNode));
	B->data = 'B';
	B->left = NULL;
	B->right = NULL;

	Tree C = (Tree) malloc(sizeof(struct TreeNode));
	C->data = 'C';
	C->left = NULL;
	C->right = NULL;

	Tree D = (Tree) malloc(sizeof(struct TreeNode));
	D->data = 'D';
	D->left = NULL;
	D->right = NULL;

	Tree E = (Tree) malloc(sizeof(struct TreeNode));
	E->data = 'E';
	E->left = NULL;
	E->right = NULL;

	Tree F = (Tree) malloc(sizeof(struct TreeNode));
	F->data = 'F';
	F->left = NULL;
	F->right = NULL;

	Tree G = (Tree) malloc(sizeof(struct TreeNode));
	G->data = 'G';
	G->left = NULL;
	G->right = NULL;

	Tree H = (Tree) malloc(sizeof(struct TreeNode));
	H->data = 'H';
	H->left = NULL;
	H->right = NULL;

	Tree I = (Tree) malloc(sizeof(struct TreeNode));
	I->data = 'I';
	I->left = NULL;
	I->right = NULL;

	root->left = B;
	root->right = C;
	B->left = D;
	B->right = F;
	C->left = G;
	C->right = I;
	F->left = E;
	G->right = H;

	return root;
}

