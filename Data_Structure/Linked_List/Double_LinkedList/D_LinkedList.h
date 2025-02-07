#ifndef D_LINKEDLIST_H_INCLUDED
#define D_LINKEDLIST_H_INCLUDED

typedef struct node{
    struct node *prev;
    int data;
    struct node *next;
}node;

node* Add_AtEnd(node *head, int data);
node* Add_ToBegin(node *head, int data);
node* Add_ToEmpty(node *head, int data);
node* Add_AfterPos(node *head, int data, int pos);
node* Add_BeforePos(node *head, int data, int pos);
node* Create_List(node *head);
node* Del_First(node *head);
node* Del_LastNode(node *head);
node* Del_Interm(node *head, int pos);
void Print_Node(node *head);
node* Reverse_List(node *head);
node* Del_EntireList(node *head);
int Count_Nodes(node *head);
void Print_Reverse(node *head);

#endif // D_LINKEDLIST_H_INCLUDED
