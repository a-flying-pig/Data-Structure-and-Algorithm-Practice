/*
 * TreeNode.c
 *
 *  Created on: 2020��6��25��
 *      Author: zhuhua
 */
#include "HuffmanTreeNode.h"

#include <stdio.h>

void printTreeNode(HuffmanTree tree) {
	printf("HuffmanTree Node info: Weight:%d, Value:%c \n", tree->Weight, tree->Value);
}

