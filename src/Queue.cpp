#include"/home/wth/VSproj/CProj/Proj1/include/Queue.h"
#include<iostream>

void InitQueue(SqQueue*& q){
	q = (SqQueue*)malloc(sizeof(SqQueue));
	q->front = q->rear = -1;
}

void DestoryQueue(SqQueue*& q){
	free(q);
}

bool QueueEmpty(SqQueue* q){
	return(q->front == q->rear);
}

bool enQueue(SqQueue*& q, char e){
	if (q->rear == MaxSize - 1)
		return false;
	q->rear++;
	q->data[q->rear] = e;
	return true;
}

bool deQueue(SqQueue*& q, char e){
	if (q->front = q->rear)
		return false;
	q->front++;
	e = q->data[q->front];
	return true;
}



void InitQueue(QuType*& qu){
	qu = (QuType*)malloc(sizeof(QuType));
	qu->front = 0;
	qu->count = 0;
}

bool EnQueue(QuType*& qu, char x){
	int rear;
	if (qu->count == MaxSize)
		return false;
	else
	{
		rear = (qu->front + qu->count) % MaxSize;
		rear = (rear + 1) % MaxSize;
		qu->data[rear] = x;
		qu->count++;
		return true;
	}
}

bool DeQueue(QuType*& qu, char& x){
	if (qu->count == 0)
		return false;
	else
	{
		qu->front = (qu->front + 1) % MaxSize;
		x = qu->data[qu->front];
		qu->count--;
		return true;
	}
}

bool QueueEmpty(QuType* qu){
	return(qu->count == 0);
}



void InitQueue(LinkQuNode*& q){
	q = (LinkQuNode*)malloc(sizeof(LinkQuNode));
	q->front = q->rear = NULL;
}

void DestroyQueue(LinkQuNode*& q){
	DataNode* p = q->front, * r;
	if (p != NULL)
	{
		r = p->next;
		while (r != NULL)
		{
			free(p);
			p = r;
			r = p->next;
		}
	}
	free(p);
	free(q);
}

bool QueueEmpty(LinkQuNode* q){
	return(q->rear == NULL);
}

void enQueue(LinkQuNode*& q, char e){
	DataNode* p;
	p = (DataNode*)malloc(sizeof(DataNode));
	p->data = e;
	p->next = NULL;
	if (q->rear == NULL)
		q->front = q->rear = p;
	else
	{
		q->rear->next = p;
		q->rear = p;
	}
}

bool deQueue(LinkQuNode*& q, char e){
	DataNode* t;
	if (q->rear == NULL)
		return false;
	t = q->front;
	if (q->front == q->rear)
		q->front = q->rear = NULL;
	else
		q->front = q->front->next;
	e = t->data;
	free(t);
	return true;
}



void initQueue(LinkList*& rear){
	rear = NULL;
}

bool queueEmpty(LinkList* rear){
	return (rear == NULL);
}

void enQueue(LinkList*& rear, char x){
	LinkList* p;
	p = (LinkList*)malloc(sizeof(LinkList));
	p->data = x;
	if (rear == NULL)
	{
		p->next = p;
		rear = p;
	}
	else
	{
		p->next = rear->next;
		rear->next = p;
		rear = p;
	}
}

bool deQueue(LinkList*& rear, char& x){
	LinkList* q;
	if (rear == NULL)
		return false;
	else
		if (rear->next == rear)
		{
			x = rear->data;
			free(rear);
			rear = NULL;
		}
		else
		{
			q = rear->next;
			x = q->data;
			rear->next = q->next;
			free(q);
		}
	return true;
}