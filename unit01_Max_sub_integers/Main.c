/*
 * Main.c
 *
 *  Created on: 2020��3��20��
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
������: setvbuf
�� ��: int setvbuf(FILE *stream, char *buf, int type, unsigned size);
type �� ���������������ͣ�
_IOFBF(�����壩����������Ϊ��ʱ�������������ݡ����ߵ���������ʱ������д���� �ݡ�
_IOLBF(�л��壩��ÿ�δ����ж���һ�����ݻ�������д��һ�����ݡ�
_IONBF(�޻��壩��ֱ�Ӵ����ж������ݻ�ֱ��������д�����ݣ���û�л�������
size �� ���������ֽڵ�������
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

// ��ͳ������������1
int MaxSubSum1(int A[], int N) {
	int maxSum = 0;
	int thisSum = 0;
	for (int i = 0; i < N; i++) { // i Ϊ���������λ��
		for (int j = i; j < N; j++) { // jΪ�������Ҷ�λ��
			thisSum = 0;
			for (int k = i; k <= j; k++) { // i-j ���еĺ�
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

// ��ͳ������������2
int MaxSubSum2(int A[], int N) {
	int maxSum = 0;
	int thisSum = 0;
	for (int i = 0; i < N; i++) { // i Ϊ���������λ��
		thisSum = 0;
		for (int j = i; j < N; j++) { // jΪ�������Ҷ�λ��
			thisSum += A[j]; // i-j���к�
			if (thisSum > maxSum) {
				maxSum = thisSum;
			}
		}
	}
	return maxSum;
}

// ���ߴ���
int MaxSubSum4(int A[], int N) {
	int maxSum = 0;
	int thisSum = 0;
	for (int i = 0; i < N; i++) {
		thisSum += A[i]; // �����ۼ�

		if (thisSum > maxSum) {
			maxSum = thisSum; // ���ָ��󣬸��µ�ǰ���
		} else if (thisSum < 0) { // ���Ϊ�����򲻿���ʹ����Ĳ�����������֮
			thisSum = 0;
		}

	}
	if (thisSum > maxSum) {
		maxSum = thisSum;
	}
	return maxSum;
}

// �ֶ���֮���ݹ�

int MaxSubSum3(int A[], int N) {
	return DevideLeftRight(A, 0, N - 1);// �ұ�ΪN - 1
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
	if (left == right) { // �ݹ���ֹ�����������ٽ�һ����,�������Ӧ��ֵ
		if (A[left] > 0) { // �������0�������к�Ϊ��ֵ�����������0�����к�Ϊ0��һ��Ԫ�ض���Ҫ
			return A[left];
		} else {
			return 0;
		}
	}
	// ������
	mid = (left + right) / 2;
	// �ݹ����
	maxLeft = DevideLeftRight(A, left, mid); // ��ߵݹ����
	maxRight = DevideLeftRight(A, mid + 1, right); // �ұߵݹ����

	// �����߽����������м�����������
	maxLeftBoard = maxSumLineLeft(A, left, mid); // ���м俪ʼ������߳����� ��������
	maxRightBoard = maxSumLineRight(A, mid + 1, right); // ���м俪ʼ�����ұ߳��������ұ����
	maxMiddle = maxLeftBoard + maxRightBoard; // �м�����������
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
