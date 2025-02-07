#include <stdio.h>
#include <stdlib.h>
#include "S_LinkedList.h"

int main() {
    node* head = NULL;
    head = Add_ToEmpty(head, 10);
    print_data(head);

    node* ptr = head;
    ptr = Insert_AtEnd(ptr, 20);
    ptr = Insert_AtEnd(ptr, 30);
    ptr = Insert_AtEnd(ptr, 40);
    print_data(head);

    head = Insert_Atbegin(head, 5);
    print_data(head);

    Insert_AtPosition(head, 25, 3);
    print_data(head);

    Del_NodeAtPos(&head, 3);
    print_data(head);

    head = Del_FirstNode(head);
    print_data(head);

    head = Del_Lastnode(head);
    print_data(head);

    head = Reverse_List(head);
    print_data(head);

    Count_Nodes(head);

    head = Del_EntireList(head);
    print_data(head);

    return 0;
}
