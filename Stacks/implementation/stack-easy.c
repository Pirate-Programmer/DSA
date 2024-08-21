#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h> 
typedef struct {
	int size;
	int top;
	float *Arr;
} Stack;
void stackPush(Stack* self,float data) {
	if(self->size<=self->top) {
		return;
	}
	self->Arr[++self->top]=data;
}
void stackPop(Stack* self) {
	if(self->top<0) {
		return ;
	}
	self->Arr[self->top--]=0.00;
}
Stack* constructStack(int size) {
	Stack* stack=(Stack*)malloc(sizeof(Stack));
	stack->Arr = (float*) malloc(size*sizeof(char));
	stack->top=-1;
	stack->size=size;
	return stack;
}
int stackSize(Stack* self) {
	return (self->top)+1;
}
float stackTop(Stack* self) {
	return self->Arr[self->top];
}
void printStack(Stack* self) {
	int curSize=(self->top)+1;
	printf("Elements of Stack : \n");
	for(int i=0; i<curSize; i++) {
		printf("%f ",self->Arr[i]);
	}
}
int main()
{
	Stack* stack = constructStack(5);
	char s[50];
	printf("Enter a postfix expression: ");
    scanf("%s", s); 
	int stringSize = strlen(s); 
//printf(" %d ",stringSize);
	for(int i=0; i<stringSize; i++) {
		if(s[i]>='0' && s[i]<='9') {
			int floatnum = (float) s[i]-'0';
			stackPush(stack,floatnum);
		}
		else if (s[i]=='*') {
			float rightOp = stackTop(stack);
			stackPop(stack);
			float leftOp = stackTop(stack);
			stackPop(stack);
			float res = leftOp*rightOp;
			stackPush(stack,res);
		}
		else if (s[i]=='+') {
			float rightOp = stackTop(stack);
			stackPop(stack);
			float leftOp = stackTop(stack);
			stackPop(stack);
			float res = leftOp+rightOp;
			stackPush(stack,res);
		}
		else if (s[i]=='-') {
			float rightOp = stackTop(stack);
			stackPop(stack);
			float leftOp = stackTop(stack);
			stackPop(stack);
			float res = leftOp-rightOp;
			stackPush(stack,res);
		}
		else if (s[i]=='/') {
			float rightOp = stackTop(stack);
			stackPop(stack);
			float leftOp = stackTop(stack);
			stackPop(stack);
			float res = leftOp/rightOp;
			stackPush(stack,res) ;
		}
		else if (s[i]=='^') {
			float rightOp = stackTop(stack);
			stackPop(stack);
			float leftOp = stackTop(stack);
			stackPop(stack);
			float res = (float) pow((double)leftOp,(double)rightOp);
			stackPush(stack,res) ;
		}
	}
	printf("%f",stackTop(stack));
	return 0;
}