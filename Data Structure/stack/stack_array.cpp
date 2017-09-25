#include<stdio.h>
using namespace std;
int MAX_SIZE = 1000;
int A[1000];
int top = -1;

void Push(int x){
	top++;
	if(top>MAX_SIZE)
		printf("Stack over flow! \n");
	else
		A[top] = x;
}
void Pop(){
	if(top<0)
		printf("Stack is already empty!\n");
	else
		top--;
}
int Top(){
	return A[top];
}
int IsEmpty(){
	if(top==-1)
		return true;
	else
		return false;
}

void Print(){
	printf("The stack elements are: ");
	for(int i=0;i<=top;i++)
		printf("%d ",A[i]);
	printf("\n");
}

int main(){

	Push(10);Print();
	Push(4);Print();
	Push(3);Print();
	printf("%d\n",Top());
	printf("%d\n",IsEmpty());
	Push(7);Print();
	Pop();Print();

}