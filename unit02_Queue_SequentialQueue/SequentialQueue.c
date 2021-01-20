#include <stdio.h>
#include <stdbool.h>

#define MaxSize 8
typedef int ElementType;
typedef struct SequentialQueue *Queue;

#define DBG false

struct SequentialQueue {
	//ElementType Data[MaxSize + 1]; // 多一个元素位置，解决当front == rear时判断是空还是满的问题，此时rear - front == 1时为空；
	// 也可以增加 size或者tag来解决
	ElementType* Data; // 用指针来指向数组
	int front;
	int rear;
};

Queue createQueue();
bool enque(Queue queue, ElementType item);
ElementType deque(Queue queue);
void printQueue(Queue queue);
bool isFull(Queue queue);

int main() {
	setvbuf(stdout, NULL, _IONBF, 0);
	Queue q = createQueue();
	for (int i = 0; i < 10; i++)
		enque(q, i);
	printf("after enque:\n");
	printQueue(q);
	for (int i = 0; i < 5; i++)
		printf("deque %d: %d\n", i, deque(q));
	printf("after deque:\n");
	printQueue(q);


/*	 for (int i = 8; i < 16; i++)
	 enque(q, i);
	 printf("after enque again:\n");
	 printQueue(q);

	 for(int i =  0; i < 10; i++){
	 ElementType item = deque(q);
	 if(item == NULL)
	 break;
	 printf("deque %d: %d\n", i, item);
	 } */



	return 0;
}

Queue createQueue() {
	Queue queue;
	queue = (Queue) malloc(sizeof(struct SequentialQueue));
	queue->Data = (ElementType) malloc(sizeof(ElementType) * (MaxSize + 1));
	queue->front = 0;
	queue->rear = 0;
	return queue;
}
bool enque(Queue queue, ElementType item) {
	if (isFull(queue)) {
		printf("queue is packed!\n");
		return false;
	}
	queue->rear++;
	queue->rear = queue->rear % (MaxSize + 1);
	queue->Data[queue->rear] = item;
	return true;

}

bool isFull(Queue queue) {
	/*	if(queue->rear >= queue->front) {
	 if (queue->rear - queue->front == MaxSize) {
	 return true;
	 } else {
	 return false;
	 }
	 } else {
	 if (queue->front - queue->rear == 1) {
	 return true;
	 } else {
	 return false;
	 }
	 }*/
	return ((queue->rear + 1) % (MaxSize + 1) == queue->front);
}

bool isEmpty(Queue queue) {
	if (queue->front == queue->rear) {
		return true;
	} else {
		return false;
	}
}

ElementType deque(Queue queue) {
	if (isEmpty(queue)) {
		printf("Queue is empty, can not deque!\n");
		return NULL;
	}
	queue->front++;
	queue->front = queue->front % (MaxSize + 1);
	if (DBG) printf("deque front:%d, rear:%d\n", queue->front, queue->rear);
	ElementType item = queue->Data[queue->front];
	return item;
}
void printQueue(Queue queue) {
	printf("printQueue:\n");
	if (isEmpty(queue)) {
		printf("Queue is empty, no elements!\n");
		return;
	}
	int start = ((queue->front + 1) % (MaxSize + 1)); // front的下一位，数据从这里开始，包含
	int end = ((queue->rear + 1) % (MaxSize + 1)); // rear 的下一位，数据从这里结束，不包含
	if (DBG)
		printf("start = %d, end=%d", start, end);
	for (int i = start; !(i == end);) {
		if(DBG)
			printf("!(i == end) : %d \n", !(i == end));
		if(DBG)
			printf("i!=end i = %d, end=%d  \n", i, end);
		printf("%d ", queue->Data[i]);
		i++;
		i = i % (MaxSize + 1);
	}

	printf("\n");
}

