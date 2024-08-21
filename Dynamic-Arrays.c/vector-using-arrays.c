#include<stdio.h>
#include<stdlib.h>


typedef struct{
    size_t size,capacity;
    __int64_t *Array;
} vector;

vector *construct (vector *self,size_t size,__int64_t value){
    self->size = size;
    self->capacity=size;
    self->Array = (__int64_t*) calloc(self->capacity,sizeof(__int64_t));
    for(int i=0;i<size;i++){
        self->Array[i] = value;

    }
    return self;
}

void push_back(vector *self,__int64_t value){
    if(!self->size){
        self->size=self->capacity=1;
        self->Array = (__int64_t*) calloc(self->capacity,sizeof(__int64_t));
        self->Array[0]=value;
    }
    else if(self->size==self->capacity){
        self->capacity*=2;
        self->Array = (__int64_t*) realloc(self->Array,self->capacity*sizeof(__int64_t));
        self->Array[self->size++]=value;
    }
    else{
        self->Array[self->size++]=value;
    }
}

size_t size(vector *self){
    return self->size;
}

void pop(vector *self){
    if(!self->Array){
        return;
    }
    self->size--;
    self->Array[self->size]=0;
}

__int64_t front(vector *self){
    if(!self->Array){
        return -1;
    }
    return self->Array[0];
}
// shrink to fit

void clear(vector *self){
    free(self->Array);
    self->Array=NULL;
    self->capacity=0;
    self->size=0;
}
int main(){
     vector *myVector = (vector*) malloc(sizeof(vector));
    construct(myVector, 3, 10);
    push_back(myVector, 20);
    push_back(myVector, 30);
    
    printf("Front element: %lld\n", front(myVector));
    pop(myVector);
    printf("Size after pop: %zu\n", size(myVector));
    
    clear(myVector);

    return 0;
}