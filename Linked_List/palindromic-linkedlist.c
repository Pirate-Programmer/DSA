#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node
{
  int data;
  struct node *next;
};

void Print(struct node * head) {
    struct node* cur = head;
    printf("\nElements of a linked list : ");
    while(cur){
        printf("%d ",cur->data);
        cur = cur->next;
    }
  
}

struct node* makeNodewithData(int data){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
struct node* makeNode(){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->next=NULL;
    return newNode;
}
struct node* reverseLinkedList(struct node *head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    struct node* nextNode;
    struct node* curNode=head;
    struct node* prevNode=NULL;

    while(curNode->next){
        nextNode=curNode->next;
        curNode->next=prevNode;
        prevNode=curNode;
        curNode=nextNode;
    }
    curNode->next=prevNode;
    return curNode;

}
struct node* reverseLinkedListRecursively(struct node *nhead){
    struct node* head = nhead;
    if(!head|| !head->next){
        return head;   
    }
    struct node* newNode = reverseLinkedListRecursively(head->next);
    struct node* nextNode = head->next;
    nextNode->next=head;
    head->next=NULL;
    return newNode;
}

struct node* findMiddle(struct node *head){
    if(!head){
        return head;
    }
    struct node* fast = head;
    struct node* slow = head;
    struct node* temp;
    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast -> next -> next;
    }
    
    return slow;
}

int main(){

    struct node *one = makeNodewithData(1);
    struct node *two = makeNodewithData(2);
    struct node *three = makeNodewithData(3);
    struct node *four = makeNodewithData(4);
    struct node *five = makeNodewithData(3);
    struct node *six = makeNodewithData(2);
    struct node *seven = makeNodewithData(1);
    struct node *head = one;
struct node *prevHead = head;
    one->next=two;
    two->next=three;
    three->next=four;
    four->next=five;
    five->next=six;
    six->next=seven;
    //seven->next=NULL; already null
    Print(head);
    struct node* middle= findMiddle(head);
    struct node* newHead = reverseLinkedList(middle->next);
    middle->next=NULL;
    int pal = 1;
    struct node* tempNewHead = newHead;
    struct node* tempPrevHead = prevHead;

    while(tempNewHead && tempPrevHead) {
        if(tempNewHead->data != tempPrevHead->data) {
            pal = 0;
            break;
        }
        tempNewHead = tempNewHead->next;
        tempPrevHead = tempPrevHead->next;
    }

    if(pal) {
        printf("\nLinked List is palindromic");
    } else {
        printf("\nLinked List is not palindromic");
    }
;
    newHead = reverseLinkedList(newHead);
    middle->next = newHead;
    Print(head);
    printf("\n");

}
