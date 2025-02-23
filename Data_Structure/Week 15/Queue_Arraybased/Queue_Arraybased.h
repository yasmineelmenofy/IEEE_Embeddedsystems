#ifndef QUEUE_ARRAYBASED_H_INCLUDED
#define QUEUE_ARRAYBASED_H_INCLUDED

#define MAX 5
typedef int QueueElement;

typedef struct Queue{
  int Front;
  int rear;
  int Size;
  QueueElement Qu_Arr[MAX];
}Queue;

void CreateQueue(Queue *q);
void Append(QueueElement e,Queue *q);
QueueElement serve(Queue *q);
int isQueueEmpty(Queue *q);
int isQueueFull(Queue *q);
int QueueSize(Queue *q);
void ClearQueue(Queue *q);
void TraverseQueue(Queue *q,void(*f)(QueueElement));

#endif // QUEUE_ARRAYBASED_H_INCLUDED
