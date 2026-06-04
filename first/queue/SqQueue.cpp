#include <stdio.h> 
#include <stdlib.h>
#include <windows.h>

// 队列的实现
#define OVERFLOW -2 
#define OK 1
#define ERROR 0

typedef int Status;
typedef int QElemType;

typedef struct QNode {
	QElemType data;
	struct QNode* next;
}QNode, * QueuePtr;
typedef struct {
	QueuePtr front;            // 队头指针 
	QueuePtr rear;             // 队尾指针 
}LinkQueue;

Status InitQueue(LinkQueue& Q)
{
	// 构造一个空队列
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q.front) exit(OVERFLOW);         // 分配存储失败 
	Q.front->next = NULL;
	return OK;
}

Status DestroyQueue(LinkQueue& Q)
{
	// 销毁队列 Q
	while (Q.front) {
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear;
	}
	return OK;
}

Status EnQueue(LinkQueue& Q, QElemType e)
{
	// 插入元素 e 为 Q 的新的队列元素 
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if (!p) exit(OVERFLOW);          // 存储分配失败
	p->data = e;
	p->next = NULL;                // 队尾 next == NULL，有 data 
	Q.rear->next = p;
	Q.rear = p;                    // 更新队尾 
	return OK;
}

Status DeQueue(LinkQueue& Q, QElemType& e)
{
	// 若对头不空，则删除对头元素，用 e 返回其值，并返回 OK，否则返回 ERROR
	if (Q.front == Q.rear) return ERROR;
	QueuePtr p = Q.front->next;         // Q.front 没有 data, next != NULL(除非空队列) 
	e = p->data;
	Q.front->next = p->next;            // 更新队头 
	if (Q.rear == p) Q.rear = Q.front;   // 队列为空了 
	free(p);
	return OK;
}

Status PrintQueue(LinkQueue Q)
{
	// 打印队列 Q 全部元素 
	QueuePtr p = Q.front;
	while (p->next) {
		printf("%d  ", p->next->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}
int main()
{
	SetConsoleOutputCP(65001);
	LinkQueue q;
	InitQueue(q);       // 初始化队列

	QElemType e1 = 666, e2 = 888;    // 向队列添加元素 
	EnQueue(q, e1);
	EnQueue(q, e2);
	printf("队列元素:  ");
	PrintQueue(q);        // 打印队列 

	QElemType e3;
	DeQueue(q, e3);
	printf("删除元素为: %d \n", e3);
	printf("队列元素:  ");
	PrintQueue(q);        // 打印队列 	

	DestroyQueue(q);      // 删除队列 

	return 0;
}
/* Code Running Results
队列元素:  666  888
删除元素为: 666
队列元素:  888
*/
