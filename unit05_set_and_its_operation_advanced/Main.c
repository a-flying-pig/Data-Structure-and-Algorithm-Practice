/*
 * Main.c
 *
 *  Created on: 2020年7月7日
 *      Author: zhuhua
 */
#include <stdio.h>
#include "Set.h"

int main() {
	setvbuf(stdout, NULL, _IONBF, 0); // 用于输出缓存

	SetType* Set = CreateSetType(10);
	PrintSetType(Set);

	Union(Set, 1, 2);
	Union(Set, 1, 4);
	Union(Set, 1, 7);
	PrintSetType(Set);

	Union(Set, 3, 5);
	Union(Set, 3, 8);
	PrintSetType(Set);

	Union(Set, 6, 9);
	Union(Set, 6, 10);
	PrintSetType(Set);

	printf("1 belongs to root:%d\n", Find(Set, 1 - 1));
	printf("2 belongs to root:%d\n", Find(Set, 2 - 1));
	printf("4 belongs to root:%d\n", Find(Set, 4 - 1));
	printf("7 belongs to root:%d\n", Find(Set, 7 - 1));

	printf("3 belongs to root:%d\n", Find(Set, 3 - 1));
	printf("5 belongs to root:%d\n", Find(Set, 5 - 1));
	printf("8 belongs to root:%d\n", Find(Set, 8 - 1));

	printf("6 belongs to root:%d\n", Find(Set, 6 - 1));
	printf("9 belongs to root:%d\n", Find(Set, 9 - 1));
	printf("10 belongs to root:%d\n", Find(Set, 10 - 1));
}
