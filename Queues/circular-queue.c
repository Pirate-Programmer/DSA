#include<stdio.h>
#include<stdlib.h>


int queue[5],front=-1,rear=-1;
int sz = sizeof(queue)/sizeof(queue[0]);

void enque(int val){
    if((rear+1)%sz==front){ 
        // This time queue is full when r is present immediately behind f
        printf("\nThe Queue is full");
    }
    else if(front==-1 && rear==-1){
        front++;
        rear++;
        queue[rear]=val;
    }
    else {
        rear = (rear+1)%sz;
        //preventing index out of bounds 😎
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

        printf("\nNow the Queue is currently empty");
    }
    else{
        queue[front]=0;
        front  = (front+1)%sz;
    }
}

void printQueue(){
    printf("\nElements in queue:");
    for(int i=front;i!=rear;){
        printf(" %d",queue[i]);
        i=(i+1)%sz;
    }
    printf(" %d", queue[rear]);

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
    printf("\nqueue Front: %d", queueFront());
    deque();
    printQueue();
    
    enque(7);
    enque(8);
    enque(9);
    enque(10);
    enque(11);
    enque(12);  

    deque();
    deque();
    enque(13);  

    printQueue();
    return 0;
}