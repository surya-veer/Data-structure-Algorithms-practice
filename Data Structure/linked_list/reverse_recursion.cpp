#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	Node* next;
};
Node* Recursion_print(Node* head){
	if(head == NULL) {printf("\n");return 0;}
	printf("%d ",head->data);
	Recursion_print(head->next);
}
Node* Recursion_rev_print(Node* head){
	if(head == NULL) return 0;
	Recursion_rev_print(head->next);
	printf("%d ",head->data);
	
}
//reversing the list using recursion
Node* head;
Node* Reverse_recursion(Node* p){

	if(p->next == NULL){
		head = p;
		return 0;
	}
	Reverse_recursion(p->next);
	//statements
	Node* q = p->next;
	q->next = p;
	p->next = NULL;
}


Node* Insert(Node* head,int x){
	struct Node* temp = (Node*)malloc(sizeof(Node*));
	temp->data = x;
	temp->next = NULL;
	if(head!=NULL) temp->next =head;
	head = temp;
}


void Print(Node* head){

	printf("List is: ");
	while(head!=NULL){
		int data = head->data;
		printf("%d ",data);
		head = head->next;
	}
	printf("\n");
}

int main()
{
	head = NULL;
	printf("No of elements in initial list: ");
	int n,pos,x;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		head = Insert(head,i+8);

		Print(head);
	}
		// head = Reverse(head);
		Reverse_recursion(head);
		Print(head);
}