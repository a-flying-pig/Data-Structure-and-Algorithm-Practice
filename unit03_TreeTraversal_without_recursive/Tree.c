/*
 * Tree.c
 *
 *  Created on: 2020年5月13日
 *      Author: zhuhua
 */
#include <stdio.h>
#include "Tree.h"
#include "LinkedStack.h"
#include "LinkedQueue.h"

Tree createTree() {
	Tree root = (Tree) malloc(sizeof(struct TreeNode));
	root->data = NULL;
	root->left = NULL;
	root->right = NULL;
	return root;
}

void PreOrderTraversal(Tree BT) {
    Stack s = createStack();

    while(!isEmpty(s) || BT) {
        while(BT) {
        	printf("%c ", BT->data);
        	push(s, BT);
        	BT = BT->left;
        }

        if(!isEmpty(s)) {
        	BT = pop(s);
        	//printf("%c ", BT->data);
        	BT = BT->right;
        }
    }
}

void InOrderTraversal(Tree BT) {
	Stack s = createStack();

	while (!isEmpty(s) || BT) {
		//printf("1 \n");
		while (BT) {
			//printf("2 \n");
			push(s, BT);
			BT = BT->left;
		}

		if (!isEmpty(s)) {
			//printf("3 \n");
			BT = pop(s);
			printf("%c ", BT->data);
           /*if (BT->right) { // 有右节点就访问右节点
				BT = BT->right;
			} else {
				BT = NULL; // 没有右节点就访问栈中下一个节点，要将BT置为NULL,	避免再push进去
			}*/
			BT = BT->right;
		}
	}
}

void PostOrderTraversal(Tree BT) {
/*	if (BT) {
		PostOrderTraversal(BT->left);
		PostOrderTraversal(BT->right);
		printf("%c ", BT->data);
	}*/
	Stack s = createStack();
	Tree LastVisited;

	while(!isEmpty(s) || BT) {
		while(BT) {
			//printf("1 \n");
			push(s, BT);
			BT = BT->left;
		}

		if (!isEmpty(s)) {
			BT = pop(s);
			//printf("2 %c\n", BT->data);
			if(BT->right == NULL || LastVisited == BT->right) {
				printf("%c ", BT->data);
				LastVisited = BT;
				BT = NULL; // 访问过则不再访问，访问栈中下一个节点，避免死循环
			} else {
				push(s, BT); // 把该节点放回stack，先访问其右节点
				BT = BT->right;
				//printf("3 %c\n", BT->data);
			}
		}
	}
}

void LevelOrderTraversal(Tree BT) {
	Tree T = BT;
	Queue q = createQueue();
	enque(q, T);
	while(!isEmptyQueue(q)) {
		Tree T = deque(q);
		printf("%c ", T->data);
		if(T->left) enque(q, T->left);
		if(T->right) enque(q, T->right);
	}
}

