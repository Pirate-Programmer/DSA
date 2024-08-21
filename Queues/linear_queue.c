#include<stdio.h>
#include<stdlib.h>


int queue[10],front=-1,rear=-1;
int sz = sizeof(queue)/sizeof(queue[0]);

void enque(int val){
    if(rear==sz-1){
        printf("The Queue is full");
    }
    else if(front==-1 && rear==-1){
        front++;
        rear++;
        queue[rear]=val;
    }
    else {
        rear++;
        queue[rear]=val;
    }
}

void deque(){
    if(front==-1){
        printf("\nThe Queue is currently empty");
    }
    // not neccessary but efficient
    else if(front == rear){
        printf("\nElement popped : %d",queue[front]);
        queue[front]=0;
        front=-1;
        rear=-1;

        printf("\nThe Queue is currently empty");
    }
    else{
        queue[front++]=0;
    }
}

void printQueue(){
    printf("\nElements in queue:");
    for(int i=front;i<=rear;i++){
        printf(" %d",queue[i]);
    }
}

int queueFront(){
    if(front==-1 || front==rear){
        return -1;
    }
    return queue[front];
}

int main(){
    enque(4);
    enque(5);
    enque(6);
    printf("\nqueue Front : %d",queueFront());
    deque();
    printQueue();
    return 0;
}