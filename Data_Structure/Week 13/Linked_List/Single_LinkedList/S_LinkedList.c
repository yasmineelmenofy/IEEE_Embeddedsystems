
#include <stdio.h>
#include <stdlib.h>
#include "S_LinkedList.h"
node* Add_ToEmpty(node *head,int data){
 node *temp=(node*)malloc(sizeof(node));
 temp->data=data;
 temp->link=NULL;
 head = temp;
 return head;
}

node* Insert_AtEnd(node* ptr, int data){
 node* temp=(node*)malloc(sizeof(node));
 temp->data =data;
 temp->link=NULL;
 ptr->link =temp;
 return temp;

}

node* Insert_Atbegin(node* head, int data){
 node* ptr=(node*)malloc(sizeof(node));
 ptr->data =data;
 ptr->link=NULL;
 ptr->link =head;
 head=ptr;
 return head;

}

void Insert_AtPosition(node *head,int data,int pos){

node *ptr = head;
node *ptr2=(node*)malloc(sizeof(node));
ptr2->data=data;
ptr2->link=NULL;
int count =0;
while(count != pos-2){
    ptr=ptr->link;
    count++;
}
ptr2->link=ptr->link;
ptr->link=ptr2;
}


void Del_NodeAtPos(node **head,int pos){
    node *current=*head;
    node *previous=*head;
    if(*head == NULL){
        printf("The list is already empty !");
    }else if(pos == 1){
        *head=current->link;
        free(current);
        current=NULL;
    }else{
    while(pos != 1){
        previous=current;
        current=current->link;
        pos--;
    }
    previous->link=current->link;
    free(current);
    current=NULL;
    }

}

node* Del_FirstNode(node *head){
    if(head == NULL){
        printf("The list is already empty");
    }else{
node *temp=head;
 head=head->link;
 free(temp);
 temp=NULL;
    }
     return head;
}

node* Del_Lastnode(node *head){
    if(head == NULL){
        printf("The list is already empty");
        return NULL;
    }else if(head->link == NULL){
         free(head);
         head=NULL;
         return head;
    }else{
     node *temp=head;
     while(temp->link->link != NULL){
        temp=temp->link;
     }
     free(temp->link);
     temp->link=NULL;
    }
  return head;
}

node* Del_EntireList(node *head){
    node *temp=head;
    while(temp != NULL){
        temp=temp->link;
        free(head);
        head=temp;
    }
    return head;
}

void print_data(node *head){
  if(head == NULL){
    printf("The linkedlist is empty\n");
      return;
  }
  node *current = NULL;
  current = head;
  printf("The list data :");
   while(current != NULL){
    printf(" %d ",current->data);
     current = current->link;
   }
    printf("\n");
}

void Count_Nodes(node *head){
    int count =0;
  if(head == NULL){
    printf("The linkedlist is empty\n");
      return;
  }
  node *current = NULL;
  current = head;
   while(current != NULL){
     count ++;
     current = current->link;
   }
   printf("%d\n",count);
}

node* Reverse_List(node *head){
    node *prev=NULL;
    node *next=NULL;
    while(head != NULL){
        next= head->link;
        head->link=prev;
        prev=head;
        head=next;
    }
    head=prev;
    return head;
}


