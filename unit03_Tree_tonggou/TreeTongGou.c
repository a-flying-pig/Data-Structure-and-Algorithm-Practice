/*
 * TreeTongGou.cpp
 *
 *  Created on: 2020年5月21日
 *      Author: zhuhua
 */
#include <stdio.h>

#define ElementType char
#define Tree int
#define MaxTree 10
#define Null -1

struct TreeNode {
	ElementType Element;
	Tree left;
	Tree right;
} T1[MaxTree], T2[MaxTree];


Tree BuildTree(struct TreeNode T[]);
int Isomorphic(Tree tree1, Tree Tree2);
void PreOrderTraversal(struct TreeNode T[], Tree root);
int main() {
	// 建二叉树1
	// 建二叉树2
	// 判别是否同构并输出
	setvbuf(stdout, NULL, _IONBF, 0);// 用于输出缓存

/*	int N;
	char a, b, c;

	scanf("%d\n", &N);
	printf("N: %d\n", N);
	if (N) {
		//printf("1\n");

		for (int i = 0; i < N; i++) {
			scanf("%c %c %c\n", &a, &b, &c);
			printf("a = %c, b = %c, c = %c", a, b, c);
		}
	}*/

	//printf("a = %c, b = %c, c = %c", a, b, c);

	Tree Root;
	Tree R1, R2;

	R1 = BuildTree(T1); // 建二叉树1
	R2 = BuildTree(T2); // 建二叉树2

	printf("PreOrderTraversal T1 R1\n");
	PreOrderTraversal(T1, R1);
	printf("\n");

	printf("PreOrderTraversal T2 R2\n");
	PreOrderTraversal(T2, R2);
	printf("\n");

	if (Isomorphic(R1, R2)) 	// 判别是否同构并输出
		printf("Yes\n");
	else
		printf("No\n");

	return 0;
}

Tree BuildTree(struct TreeNode T[]) {
	int N;
	char cl = '-';
	char cr = '-';
	Tree Root;
	scanf("%d\n", &N);
	//printf("N: %d\n", N);
	if (N) {
		int check[N];
		for (int i = 0; i < N; i++)
			check[i] = 0;
		//printf("1\n");

		for (int i = 0; i < N; i++) {
			scanf("%c %c %c\n", &T[i].Element, &cl, &cr);
			//printf("build tree:data--, left:%c, right:%c\n", cl, cr);
			if (cl != '-') {
				T[i].left = cl - '0'; // 字符值 减去0字符的值即为字符整数值
				check[T[i].left] = 1; // 指向的这个地方是有父节点的
			} else {
				T[i].left = Null;
			}
			if (cr != '-') {
				T[i].right = cr - '0'; // 字符值 减去0字符的值即为字符整数值
				check[T[i].right] = 1; // 指向的这个地方是有父节点的
			} else {
				T[i].right = Null;
			}
		    //printf("build tree:data %c, left:%d, right:%d\n", T[i].Element, T[i].left, T[i].right);
		}
		int i = 0;
		for (int i; i < N; i++) {
			if (!check[i])
				break; // 没有父节点，即为跟节点
		}
		Root = i;
	}
	return Root;
}

int Isomorphic(Tree R1, Tree R2) {
	if ((R1 == Null) && (R2 == -1)) {
		// both empty
		return 1;
	}
	if (((R1 == -1) && (R2 != -1)) || ((R1 != -1) && (R2 == -1))) {
		// one of them is empty
		return 0;
	}
	if (T1[R1].Element != T2[R2].Element){
		// roots are different
		return 0;
	}
	if ((T1[R1].left == -1) && (T2[R2].left == -1)) {
		// both have no left subtree
		return Isomorphic(T1[R1].right, T2[R2].right);
	}
	if (((T1[R1].left) != -1 && (T2[R2].left != -1)) &&
		((T1[T1[R1].left].Element) == (T2[T2[R2].left].Element))){
			// no need to swap the left and the right
		return (Isomorphic(T1[R1].left, T2[R2].left) &&
				Isomorphic(T1[R1].right, T2[R2].right));
	} else {
		// need to swap the left and the right
		return(Isomorphic(T1[R1].left, T2[R2].right) &&
			   Isomorphic(T1[R1].right, T2[R2].left));
	}
}

void PreOrderTraversal(struct TreeNode T[], Tree root) {
	if(root != Null) {
		printf("%c ", T[root].Element);
		PreOrderTraversal(T, T[root].left);
		PreOrderTraversal(T, T[root].right);
	}
}
