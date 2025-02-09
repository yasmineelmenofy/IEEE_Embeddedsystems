#include<stdio.h>
#include<stdlib.h>
#include"D_LinkedList.h"


node* Add_AtEnd(node *head,int data){
 node *temp=(node*)malloc(sizeof(node));
 node *ptr = head;
 temp->prev=NULL;
 temp->data=data;
 temp->next=NULL;
 if (head == NULL) {
    return Add_ToEmpty(head, data);
}

 while(ptr->next != NULL){
    ptr=ptr->next;
 }
 ptr->next=temp;
 temp->prev=ptr;
 return head;
}
node* Add_ToBegin(node *head,int data){
node *temp=(node*)malloc(sizeof(node));
temp->prev=NULL;
temp->data=data;
temp->next=NULL;
temp->next=head;
if (head == NULL) {
    return Add_ToEmpty(head, data);
}
head->prev=temp;
head=temp;
return head;
}
node* Add_ToEmpty(node *head,int data){
 node *temp=(node*)malloc(sizeof(node));
 temp->prev=NULL;
 temp->data=data;
 temp->next=NULL;
 head = temp;
 return head;
}

node* Add_AfterPos(node *head,int data,int pos){
node *temp=head;
node *temp2=NULL;
node *newp=NULL;
newp=Add_ToEmpty(head,data);

while(pos != 1){
    temp=temp->next;
    pos--;
}
if(temp->next == NULL){
    head=Add_AtEnd(head,data);
}else{
temp2=temp->next;
temp->next=newp;
temp2->prev=newp;
newp->next=temp2;
newp->prev=temp;
}
return head;
}

node* Add_BeforePos(node *head,int data,int pos){
node *temp=head;
node *temp2=NULL;
node *newp=NULL;
newp=Add_ToEmpty(head,data);

while(pos >2){
    temp=temp->next;
    pos--;
}
if(pos == 1){
    head=Add_ToBegin(head,data);
}else{
temp2=temp->next;
temp->next=newp;
temp2->prev=newp;
newp->next=temp2;
newp->prev=temp;
}
return head;
}

node* Create_List(node *head){
    int n,data,i;
    printf("Please Enter the number of Nodes you want to create:");
    scanf("%d",&n);
     if(n == 0)
        return head;
    printf("please Enter the data of the first node:");
    scanf("%d",&data);
    head=Add_ToEmpty(head,data);
    for(i=2;i<=n;i++){
        printf("Enter the data of node no %d:",i);
        scanf("%d",&data);
        head=Add_AtEnd(head,data);
    }
    return head;
}
node* Del_First(node *head){
    if(head == NULL){
        printf("The list is already empty !:");
        return head;
    }
 node *temp=head;
 head=head->next;
 free(temp);
 temp=NULL;
 head->prev=NULL;
 return head;
}


node* Del_LastNode(node *head){
node *ptr=head;
node *ptr2=NULL;
while(ptr->next != NULL){
    ptr=ptr->next;
}
  ptr2=ptr->prev;
  ptr2->next=NULL;
  free(ptr);
  ptr=NULL;
  return head;
}

node* Del_Interm(node *head,int pos){
 node *ptr=head;
 node *ptr2=NULL;
 if(pos == 1){
    head = Del_First(head);
    return head;
 }
  while(pos != 1){
    ptr=ptr->next;
    pos--;
  }
  if(ptr->next == NULL){
    head= Del_LastNode(head);
    return head;
  }
  ptr2=ptr->prev;
  ptr2->next=ptr->next;
  ptr->next->prev=ptr2;
  free(ptr);
  ptr=NULL;
  return head;
}

void Print_Node(node *head){
    node *ptr =head;
while(ptr != NULL){
    printf(" %d ",ptr->data);
    ptr=ptr->next;
}
printf("\n");

}

node* Reverse_List(node *head){
node *ptr=head;
node *ptr2=NULL;

while(ptr != NULL){
        ptr2=ptr->prev;
    ptr->prev=ptr->next;
     ptr->next=ptr2;
    ptr=ptr->prev;

}
    if (ptr2 != NULL) {
    head = ptr2->prev;
}
   return head;
}

node* Del_EntireList(node *head){
    node *temp;
    while (head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
    return head;
}

int Count_Nodes(node *head){
    int count = 0;
    node *ptr = head;
    while(ptr != NULL){
        count++;
        ptr = ptr->next;
    }
    return count;
}

void Print_Reverse(node *head){
    if (head == NULL) return;
    node *ptr = head;
    while (ptr->next != NULL){
        ptr = ptr->next;
    }
    while (ptr != NULL){
        printf("%d\n", ptr->data);
        ptr = ptr->prev;
    }
}
