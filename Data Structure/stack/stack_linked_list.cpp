#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	Node* next;
};
Node* top;
void Push(int x){
	Node* temp = (Node*)malloc(sizeof(Node*));
	temp->data = x;
	if(top!=NULL) temp->next = top;
	top = temp;
}
void Pop(){
	Node* temp = top;
	if(top == NULL) return;
	top = top->next;
}
int IsEmpty(){
	if(top==NULL)
		return true;
	else
		return false;
}
int Top(){
	return top->data;
}
void Print(){
	printf("\nElements of the stack are: ");
	Node* temp = top;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	}
}
int main(){

	top = NULL;

	Push(10);Print();
	Push(4);Print();
	Push(3);Print();
	printf("\n%d\n",Top());
	printf("%d\n",IsEmpty());
	Push(7);Print();
	Pop();Print();
}