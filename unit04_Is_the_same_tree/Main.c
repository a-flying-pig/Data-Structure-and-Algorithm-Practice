/*
 * Main.c
 *
 *  Created on: 2020��6��7��
 *      Author: zhuhua
 */
#include <stdio.h>
#include <stdlib.h>
/*
 int main() {
 ��ÿ������
 ����N��L
 ���ݵ�һ�����н���T
 ������T�ֱ��б�����L�������Ƿ�����T�г�ͬһ��������������
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
	setvbuf(stdout, NULL, _IONBF, 0); // �����������
	int N, L, i;
	Tree T;
	scanf("%d", &N);
	while (N) {
		scanf("%d", &L);
		T = MakeTree(N); // ����
		for (i = 0; i < L; i++) {
			if (Judge(T, N))
				printf("Yes\n");
			else
				printf("No\n");
			ResetT(T); // ���T�еı��flag
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
	/* flag Ϊ1��˵���в�ͬ�ĵط��� */
	if (flag) return 0;
	else return 1;
}

int check(Tree T, int V) {
	if (!T->flag) {
		/* û�з��ʹ��ý�� */
		if (V == T->v) {
			/* �����ȣ�һ�� */
			T->flag = 1;
			return 1;
		} else {
			/* ��㲻��ȣ�˵����һ�� */
			return 0;
		}
	} else {
		/* ���ʹ��ýڵ㣬������Ƚ� */
		if (V < T->v) {
			return check(T->Left, V);
		} else if (V > T->v) {
			return check(T->Right, V);
		} else {
			/* �õ���ʹ����ֳ�����1����ͬ�ģ���������2����ͬ��ֵ����˲����  */
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
