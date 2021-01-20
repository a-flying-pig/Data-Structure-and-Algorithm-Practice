/*
 * Main.c
 *
 *  Created on: 2020年6月7日
 *      Author: zhuhua
 */
#include <stdio.h>
#include <stdlib.h>
/*
 int main() {
 对每组数据
 读入N和L
 根据第一行序列建树T
 依据树T分别判别后面的L个序列是否能与T行成同一搜索树并输出结果
 return 0;
 }
 */

typedef struct TreeNode* Position;
typedef Position Tree;
struct TreeNode {
	int v;
	Tree Left;
	Tree Right;
	int flag;
};

Tree MakeTree(int N);
int Judge(Tree T, int N);
void ResetT(Tree T);
void FreeTree(Tree T);
Tree NewNode(int V);
Tree Insert(Tree T, int v);
int check(Tree T, int V);

int main() {
	setvbuf(stdout, NULL, _IONBF, 0); // 用于输出缓存
	int N, L, i;
	Tree T;
	scanf("%d", &N);
	while (N) {
		scanf("%d", &L);
		T = MakeTree(N); // 建树
		for (i = 0; i < L; i++) {
			if (Judge(T, N))
				printf("Yes\n");
			else
				printf("No\n");
			ResetT(T); // 清除T中的标记flag
		}
		FreeTree(T);
		scanf("%d", &N);
	}
	return 0;
}

void ResetT(Tree T) {
	if (T) {
		ResetT(T->Left);
		ResetT(T->Right);
		T->flag = 0;
	}
}

void FreeTree(Tree T) {
	if (T) {
		FreeTree(T->Left);
		FreeTree(T->Right);
		free(T);
		T = NULL;
	}
}

int Judge(Tree T, int N) {
	int V;
	int flag = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &V);
		if ((!flag) && (!check(T, V))) {
			//printf("Judge flag =1, i = %d, V = %d\n", i, V);
			flag = 1;
		}
	}
	/* flag 为1，说明有不同的地方了 */
	if (flag) return 0;
	else return 1;
}

int check(Tree T, int V) {
	if (!T->flag) {
		/* 没有访问过该结点 */
		if (V == T->v) {
			/* 结点相等，一样 */
			T->flag = 1;
			return 1;
		} else {
			/* 结点不相等，说明不一样 */
			return 0;
		}
	} else {
		/* 访问过该节点，则往后比较 */
		if (V < T->v) {
			return check(T->Left, V);
		} else if (V > T->v) {
			return check(T->Right, V);
		} else {
			/* 该点访问过，又出现了1个相同的，即出现了2个相同的值，因此不相等  */
			return 0;
		}
	}
}


Tree MakeTree(int N) {
	Tree T;
	int V;

	scanf("%d", &V);
	T = NewNode(V);
	for (int i = 1; i < N; i++) {
		scanf("%d", &V);
		T = Insert(T, V);
	}
	return T;
}

Tree NewNode(int V) {
	Tree T = (Tree) malloc(sizeof(struct TreeNode));
	T->v = V;
	T->Left = T->Right = NULL;
	T->flag = 0;
	return T;
}

Tree Insert(Tree T, int V) {
	if (!T) {
		T = NewNode(V);
	} else if (V < T->v) {
		T->Left = Insert(T->Left, V);
	} else if (V > T->v) {
		T->Right = Insert(T->Right, V);
	} // V = T->v, no need to insert

	return T;
}
