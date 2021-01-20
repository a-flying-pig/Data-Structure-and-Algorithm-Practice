/*
 * Main.c
 *
 *  Created on: 2020年3月20日
 *      Author: zhuhua
 */
#include <stdio.h>

int MaxSubSum1(int A[], int N);
int MaxSubSum2(int A[], int N);
int MaxSubSum3(int A[], int N);
int MaxSubSum4(int A[], int N);

int DevideLeftRight(int A[], int left, int right);
int maxSumLineLeft(int A[], int left, int right);
int maxSumLineRight(int A[], int left, int right);

/*
函数名: setvbuf
用 法: int setvbuf(FILE *stream, char *buf, int type, unsigned size);
type ： 期望缓冲区的类型：
_IOFBF(满缓冲）：当缓冲区为空时，从流读入数据。或者当缓冲区满时，向流写入数 据。
_IOLBF(行缓冲）：每次从流中读入一行数据或向流中写入一行数据。
_IONBF(无缓冲）：直接从流中读入数据或直接向流中写入数据，而没有缓冲区。
size ： 缓冲区内字节的数量。
*/

int main() {
	setvbuf(stdout, NULL, _IONBF, 0);
	int a[8] = {4, -3, 5, -2, -1, 2, 6, -2};
    printf("MaxSubSum1 :%d\n", MaxSubSum1(a, sizeof(a) / sizeof(a[0])));
	printf("MaxSubSum2 :%d\n", MaxSubSum2(a, sizeof(a) / sizeof(a[0])));
	printf("MaxSubSum3 :%d\n", MaxSubSum3(a, sizeof(a) / sizeof(a[0])));
	printf("MaxSubSum4 :%d\n", MaxSubSum4(a, sizeof(a) / sizeof(a[0])));
	return 0;
}

// 传统暴力检索方法1
int MaxSubSum1(int A[], int N) {
	int maxSum = 0;
	int thisSum = 0;
	for (int i = 0; i < N; i++) { // i 为子列最左端位置
		for (int j = i; j < N; j++) { // j为子列最右端位置
			thisSum = 0;
			for (int k = i; k <= j; k++) { // i-j 子列的和
				thisSum += A[k];
			}
			//printf("i = %d , j = %d, thisSum = %d, maxSum = %d \n", i, j, thisSum, maxSum);
			if (thisSum > maxSum) {
				maxSum = thisSum;
			}
		}
	}
	return maxSum;
}

// 传统暴力检索方法2
int MaxSubSum2(int A[], int N) {
	int maxSum = 0;
	int thisSum = 0;
	for (int i = 0; i < N; i++) { // i 为子列最左端位置
		thisSum = 0;
		for (int j = i; j < N; j++) { // j为子列最右端位置
			thisSum += A[j]; // i-j子列和
			if (thisSum > maxSum) {
				maxSum = thisSum;
			}
		}
	}
	return maxSum;
}

// 在线处理
int MaxSubSum4(int A[], int N) {
	int maxSum = 0;
	int thisSum = 0;
	for (int i = 0; i < N; i++) {
		thisSum += A[i]; // 向右累加

		if (thisSum > maxSum) {
			maxSum = thisSum; // 发现更大，更新当前结果
		} else if (thisSum < 0) { // 如果为负，则不可能使后面的部分增大，抛弃之
			thisSum = 0;
		}

	}
	if (thisSum > maxSum) {
		maxSum = thisSum;
	}
	return maxSum;
}

// 分而治之，递归

int MaxSubSum3(int A[], int N) {
	return DevideLeftRight(A, 0, N - 1);// 右边为N - 1
}

int MaxOf3(int a, int b, int c) {
	if (a >= b && a >= c) {
		return a;
	} else if (b >= a && b >= c) {
		return b;
	} else {
		return c;
	}
}

int DevideLeftRight(int A[], int left, int right) {
	int maxLeft, maxRight, maxMiddle, maxLeftBoard, maxRightBoard;
	int mid;
	if (left == right) { // 递归中止条件，不能再进一步分,并求出相应的值
		if (A[left] > 0) { // 如果大于0，则子列和为其值，如果不大于0，子列和为0，一个元素都不要
			return A[left];
		} else {
			return 0;
		}
	}
	// 分左右
	mid = (left + right) / 2;
	// 递归调用
	maxLeft = DevideLeftRight(A, left, mid); // 左边递归调用
	maxRight = DevideLeftRight(A, mid + 1, right); // 右边递归调用

	// 处理跨边界的情况，求中间连续的最大的
	maxLeftBoard = maxSumLineLeft(A, left, mid); // 从中间开始，向左边出发， 求左边最大
	maxRightBoard = maxSumLineRight(A, mid + 1, right); // 从中间开始，向右边出发，求右边最大
	maxMiddle = maxLeftBoard + maxRightBoard; // 中间连续的最大的
	//printf("maxLeft = %d , maxRight = %d, maxMiddle = %d\n", maxLeft, maxRight, maxMiddle);
	return MaxOf3(maxLeft, maxRight, maxMiddle);
}

int maxSumLineRight(int A[], int left, int right) {
	int max = 0;
	int temp = 0;
	for (int i = left; i <= right; i++) {
		temp += A[i];
		if (temp > max) {
			max = temp;
		}
	}
	return max;
}

int maxSumLineLeft(int A[], int left, int right) {
	int max = 0;
	int temp = 0;
	for (int i = right; i >= left; i--) {
		temp += A[i];
		if (temp > max) {
			max = temp;
		}
	}
	return max;
}
