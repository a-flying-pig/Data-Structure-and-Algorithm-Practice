/*
 * HuffmanTree.h
 *
 *  Created on: 1980��1��4��
 *      Author: zhuhua
 */

#ifndef HUFFMANTREE_H_
#define HUFFMANTREE_H_
#include <stdlib.h>
#include "heap.h"
#include "DataInfo.h"

#define DataType DataInfo

HuffmanTree BuildHuffmanTree(DataType* datas, int size);

void PrintHuffmanTree(HuffmanTree HT);

#endif /* HUFFMANTREE_H_ */
