#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	Node* next;
};

Node* Insert(Node* head,int pos,int x){
	Node* temp =(Node*)malloc(sizeof(Node*));
	temp->data = x;
	if(pos == 1)
	{
		temp->next = head;
		head = temp;
		return head;
	}
	else{

		Node* temp1 =head;
		Node* temp2 =NULL;
		for(int i=1;i<pos;i++){
			temp2 = temp1;
			temp1 = temp1->next;
		}
		temp2->next = temp;
		temp->next = temp1;
		return head;
	}

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
Node* del(Node* head, int pos)
{
	Node* temp = head;
	Node* left = NULL;
	if(pos == 1 )
	{
		head = head->next;
		return head;
	}
	else
	{
		for(int i=1;i<pos;i++)
		{
			left = temp;
			temp =temp->next;
		}

		left->next = temp->next;
		return head;
	}
	
}

int main()
{
	Node* head = NULL;
	printf("Number of operations: ");
	int n,pos,x;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		head = Insert(head,i+8);
		Print(head);
	}
	for(int i=0;i<n;i++)
	{
		printf("Enter the position which you want to delete: ");
		scanf("%d",&pos);
		head = del(head,pos);
		Print(head);
	}
}