#include<stdio.h>
#include<stdlib.h>

struct DLL{
    int data;
    struct DLL *next,*prev;
};
int curSize=0;
struct DLL *head,*tail;
void constructEmptyStack(){
    head = (struct DLL*) malloc(sizeof(struct DLL));
    tail = (struct DLL*) malloc(sizeof(struct DLL));

    head->next=tail;
    head->prev=NULL;
    tail->next=NULL;
    tail->prev=head;
    curSize=0;
}

void stackPush(int data){
    struct DLL* node = (struct DLL*) malloc(sizeof(struct DLL));
    struct DLL* temp=tail->prev;
    temp->next = node;
    tail->prev = node;
    node->next = tail;
    node->prev = temp;
    curSize++;
    node->data=data;
}

void stackPop(){
    if(curSize==0){
        return;
    }
    struct DLL* temp=tail->prev;
    temp->prev->next=tail;
    tail->prev = temp->prev;
    free(temp);
    curSize--;
}

int stackTop(){
    if(curSize==0){
        return -1;
    }
    return tail->prev->data;
}

int main() {
    constructEmptyStack();
    stackPush(10);
    stackPush(20);
    printf("Top element is %d\n", stackTop());
    stackPop();
    printf("Top element is %d\n", stackTop()); 
    stackPop();
    printf("Top element is %d\n", stackTop()); 
    
    return 0;
}