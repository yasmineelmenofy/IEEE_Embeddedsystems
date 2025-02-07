#ifndef S_LINKEDLIST_H_INCLUDED
#define S_LINKEDLIST_H_INCLUDED

typedef struct node{
int data;
struct node *link;
}node;

node* Add_ToEmpty(node* head, int data);
node* Insert_AtEnd(node* ptr, int data);
node* Insert_Atbegin(node* head, int data);
void Insert_AtPosition(node* head, int data, int pos);
void Del_NodeAtPos(node** head, int pos);
node* Del_FirstNode(node* head);
node* Del_Lastnode(node* head);
node* Del_EntireList(node* head);
void print_data(node* head);
void Count_Nodes(node* head);
node* Reverse_List(node* head);

#endif
