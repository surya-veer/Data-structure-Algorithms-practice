#include<stdlib.h>
#include<stdio.h>

struct Node{
	int data;
	Node* next;
};

Node* Insert(Node* head,int x){
	struct Node* temp = (Node*)malloc(sizeof(Node*));
	temp->data = x;
	temp->next = NULL;
	if(head!=NULL) temp->next =head;
	head = temp;
}

void Print(Node* head)
{
	printf("List is: ");
	while(head!=NULL)
	{
		printf("%d ",head->data);
		head = head->  next;
	}
	printf("\n");
}
int main()
{
	Node* head = NULL;
	printf("How many number?\n");
	int n,x;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("Enter the number\n");
		scanf("%d",&x);
		head = Insert(head,x);
		Print(head);
	}
	return 0;
}






