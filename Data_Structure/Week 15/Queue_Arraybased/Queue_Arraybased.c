#include <stdio.h>
#include <stdlib.h>
#include "Queue_Arraybased.h"

void CreateQueue(Queue *q){
 q->Front =0;
 q->rear=-1;
 q->Size=0;
}

void Append(QueueElement e,Queue *q){
   if (isQueueFull(q)) {
   printf("Queue is full! Cannot append.\n");
        return ;
   }
 q->rear = (q->rear+1)%MAX;
 q->Qu_Arr[q->rear]=e;
 q->Size++;
}

QueueElement serve(Queue *q){
  if (isQueueEmpty(q)) {
    printf("Queue is empty! Cannot serve.\n");
         return ;
    }
 QueueElement value;
 value= q->Qu_Arr[q->Front];
 q->Front=(q->Front +1)%MAX;
 q->Size--;
 return value;
}

int isQueueEmpty(Queue *q){
  return !q->Size;
}

int isQueueFull(Queue *q){
 return( q->Size == MAX);
}

int QueueSize(Queue *q){
 return q->Size;
}

void ClearQueue(Queue *q){
 q->Front =0;
 q->rear=-1;
 q->Size=0;
}

void TraverseQueue(Queue *q,void(*f)(QueueElement)){
  int pos,s;
  for(pos=q->Front,s=0;s<q->Size;s++){
    (*f)(q->Qu_Arr[pos]);
    pos=(pos+1)%MAX;
  }
  printf("\n");
}

