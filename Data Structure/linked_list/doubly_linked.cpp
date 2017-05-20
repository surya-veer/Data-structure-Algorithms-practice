#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	Node* next;
	Node* prev;
};
Node* head;

void InsertAtHead(int x){
	Node* temp = (Node*)malloc(sizeof(Node*));
	temp->data = x;
	temp->next = NULL;
	temp->prev = NULL;
	if(head == NULL){
		head = temp;
		return;	
	}
	else{
		head->prev = temp;
		temp->next = head;
		head = temp;
		return;	
	}
}
void InsertAtTail(int x){
	Node* temp = (Node*)malloc(sizeof(Node*));
	temp->data = x;
	temp->next = NULL;
	temp->prev = NULL;
	if(head == NULL){
		head = temp;
		return;	
	}
	else{
		Node* temp1 = head;
		while(temp1->next!=NULL){
			temp1 = temp1->next;
		}
		temp1->next = temp;
		temp->prev = temp1;
		return;
	}
}
void Insert_nth(int pos,int x){
	Node* temp = (Node*)malloc(sizeof(Node*));
	temp->data = x;
	temp->next = NULL;
	temp->prev = NULL;
	if(pos == 1){
		if(head==NULL){
			temp->next  = head;
			head = temp;
		}
		else{
			temp->next  = head;
			head->prev = temp;
			head = temp;
		}
		return;
	}
	else{
		Node* next = head;
		Node* prev = NULL;
		for(int i=1;i<pos;i++){
			prev = next;
			// if(next!=NULL)
			next = next->next;
		}
		if(next!=NULL)
		next->prev = temp;
	
		temp->next = next;
		prev->next = temp;
		temp->prev = prev;
		return;
	}
}

void Forward_print(){
	printf("List elements in forward manner: ");\
	Node* temp = head;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}
void Reverse_print(){
	printf("List elements in backward manner: ");
	Node* temp = head;
	while(temp->next!=NULL){
		temp = temp->next;
	}
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp = temp->prev;
	}
	printf("\n");
}


int main(){
	head = NULL;
	printf("Number of element you want to insert: ");
	int n,x,pos;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("Enter the element which you want to insert: ");
		scanf("%d%d",&pos,&x);
		// InsertAtHead(x);
		// InsertAtTail(x);
		Insert_nth(pos,x);
		Forward_print();
		// Reverse_print();
	}
}