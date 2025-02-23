#include <stdio.h>
#include <stdlib.h>
#include "Queue_Arraybased.h"

void display(QueueElement e) {
    printf("%d ", e);
}

int main() {
    Queue q;
    CreateQueue(&q);
    Append(4, &q);
    Append(3, &q);
    Append(7, &q);
    Append(2, &q);
    Append(9, &q);

    printf("Queue after appending elements: ");
    TraverseQueue(&q, display);


    Append(5, &q);

    printf("Served element: %d\n", serve(&q));

    Append(8, &q);

    printf("Queue after serving and appending: ");
    TraverseQueue(&q, display);

    ClearQueue(&q);
    printf("Queue after clearing: ");
    TraverseQueue(&q, display);
    return 0;
}
