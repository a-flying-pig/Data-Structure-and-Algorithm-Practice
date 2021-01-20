/*
 * TreeNode.h
 *
 *  Created on: 2020��6��25��
 *      Author: zhuhua
 */

#ifndef HUFFMANTREENODE_H_
#define HUFFMANTREENODE_H_

typedef struct TreeNode* HuffmanTree;
#define SizeOfHuffmanTree sizeof(struct TreeNode)
struct TreeNode {
	int Weight;
	HuffmanTree Left;
	HuffmanTree Right;
	char Value;
};

void printTreeNode(HuffmanTree tree);

#endif /* HUFFMANTREENODE_H_ */
