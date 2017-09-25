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
	Node* head = NULL;
	printf("No of elements in initial list: ");
	int n,pos,x;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		head = Insert(head,i+8);

		Print(head);
	}
		// head = Reverse(head);
		Recursion_print(head);
		Recursion_rev_print(head);
		printf("\n");
	
}