#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define LIMIT 100 
typedef struct{
    __int64_t curSize,capacity;
    int *Array;
}Stack;

void constructEmptyStack(Stack *self){
    self->capacity=1;
    self->curSize=0;
    self->Array = (int*)calloc(self->capacity,sizeof(int));
}

void stackPush(Stack *self,int data){
    if(!self->Array){
        constructEmptyStack(self);
        self->curSize++;
        self->Array[0]=data;
        //self->curSize++;
    }
    else if(self->curSize==self->capacity){
        self->capacity*=2;
        self->curSize++;
        self->Array[self->curSize-1]=data;
        
    }
    else{
        self->curSize++;
        self->Array[self->curSize-1]=data;
    }
}

void pop(Stack *self){
    if(self->curSize==0){
        return;
    }
    self->Array[self->curSize-1]=0;
    self->curSize--;
}

int stackTop(Stack *self){
    return self->Array[self->curSize-1];
}

bool isEmpty(Stack *self){
    return (self->curSize==0);
}
int stackSize(Stack *self){
    return self->curSize;
}