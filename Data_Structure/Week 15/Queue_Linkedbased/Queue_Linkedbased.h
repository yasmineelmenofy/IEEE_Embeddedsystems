#ifndef QUEUE_LINKEDBASED_H_INCLUDED
#define QUEUE_LINKEDBASED_H_INCLUDED

typedef int QueueElement;

typedef struct QueueNode{
  QueueElement data;
  struct QueueNode *link;
}QueueNode;

typedef struct Queue{
 QueueNode *Front;
 QueueNode *rear;
 int Size;
}Queue;

void CreateQueue(Queue *q);
void Append(QueueElement e,Queue *q);
QueueElement serve(Queue *q);
int isQueueEmpty(Queue *q);
int isQueueFull(Queue *q);
int QueueSize(Queue *q);
void ClearQueue(Queue *q);
void TraverseQueue(Queue *q,void(*f)(QueueElement));

#endif // QUEUE_LINKEDBASED_H_INCLUDED
