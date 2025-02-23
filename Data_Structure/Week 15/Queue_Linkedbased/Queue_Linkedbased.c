
#include <stdio.h>
#include <stdlib.h>
#include "Queue_Linkedbased.h"


void CreateQueue(Queue *q){
  q->Front=NULL;
  q->rear=NULL;
  q->Size=0;
}

void Append(QueueElement e,Queue *q){
  QueueNode *n =(QueueNode*)malloc(sizeof(QueueNode));
  n->data=e;
  n->link=NULL;
  if(isQueueEmpty(q)){
    q->Front=n;
    q->rear=n;
  }else{
  q->rear->link=n;
  q->rear=n;
  }
  q->Size++;
}

QueueElement serve(Queue *q){
  if(isQueueEmpty(q)){
    printf("Error the queue is empty !");
    return 0;
  }
   QueueElement value ;
   QueueNode *n=q->Front;
   value=n->data;
   q->Front=q->Front->link;
   n->link=NULL;
   if (q->Front == NULL) {
        q->rear = NULL;
    }
   free(n);
   q->Size--;
   return value;

}

int isQueueEmpty(Queue *q){
  return ! q->Size;
}

int isQueueFull(Queue *q){
 return 0;
}

int QueueSize(Queue *q){
   return q->Size;
}

void ClearQueue(Queue *q){
    QueueNode *temp;
    while (q->Front != NULL) { 
        temp = q->Front;
        q->Front = q->Front->link;
        free(temp);
    }
    q->Front = NULL;
    q->rear = NULL;
    q->Size = 0;  
}

void TraverseQueue(Queue *q,void(*f)(QueueElement)){
   for(QueueNode *n=q->Front;n;n=n->link){
    (*f)(n->data);
   }
   printf("\n");
}
