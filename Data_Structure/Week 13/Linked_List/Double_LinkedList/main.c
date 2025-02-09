#include <stdio.h>
#include <stdlib.h>
#include "D_LinkedList.h"

int main()
{
   node *head = NULL;
    int choice, data, pos;

    while (1) {
        printf("\nDoubly Linked List Operations:\n");
        printf("1. Add to Empty\n");
        printf("2. Add to Beginning\n");
        printf("3. Add to End\n");
        printf("4. Add After Position\n");
        printf("5. Add Before Position\n");
        printf("6. Delete First Node\n");
        printf("7. Delete Last Node\n");
        printf("8. Delete at Position\n");
        printf("9. Reverse List\n");
        printf("10. Print List\n");
        printf("11. Print Reverse\n");
        printf("12. Count Nodes\n");
        printf("13. Delete Entire List\n");
        printf("14. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                head = Add_ToEmpty(head, data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                head = Add_ToBegin(head, data);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                head = Add_AtEnd(head, data);
                break;
            case 4:
                printf("Enter data and position: ");
                scanf("%d %d", &data, &pos);
                head = Add_AfterPos(head, data, pos);
                break;
            case 5:
                printf("Enter data and position: ");
                scanf("%d %d", &data, &pos);
                head = Add_BeforePos(head, data, pos);
                break;
            case 6:
                head = Del_First(head);
                break;
            case 7:
                head = Del_LastNode(head);
                break;
            case 8:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                head = Del_Interm(head, pos);
                break;
            case 9:
                head = Reverse_List(head);
                break;
            case 10:
                Print_Node(head);
                break;
            case 11:
                Print_Reverse(head);
                break;
            case 12:
                printf("Total nodes: %d\n", Count_Nodes(head));
                break;
            case 13:
                head = Del_EntireList(head);
                printf("List deleted.\n");
                break;
            case 14:
                head = Del_EntireList(head);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}

