//this code is for linked list implimentation of Queue

#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* next;
};

Node* front = NULL;
Node* rear = NULL;

int IsEmpty(){
	if(front==NULL&&rear==NULL)
		return 1;
	else
		return 0;
}

void EnQueue(int x){
	Node* temp = new Node;
	temp->data = x;
	temp->next = NULL;
	if(IsEmpty()){
		rear = temp;
		front = temp;
	}
	rear->next = temp;
	rear = temp;
}

void DeQueue(){
	Node* temp = front;
	if(IsEmpty()){
		cout<<"Queue is empty!\n";
	}
	else if(front == rear){
		front = NULL;
		rear = NULL;
	}
	else{
		front = front->next;
	}
	free(temp);
}

int Front(){
	if(front!=NULL)
	return front->data;
	else{
		cout<<"Queue is empty!\n";
	}
}

void Print(){
	cout<<"Elements of queue are: ";
	Node* temp =front;
	while(temp!=NULL){
		cout<< temp->data <<" ";
		temp = temp->next;
	}
	cout<<endl;
}

int main(){
	while(true){
		cout<<"Choose one operation: 1.EnQueue,  2.DeQueue,  3.Front,  4.Print,  5.Exit"<<endl;
		int in;
		cin>>in;
		switch(in){
			case 1:{
				int x;
				cin>>x;
				EnQueue(x);
				break;
			}
			case 2:{
				DeQueue();
				break;
			}

			case 3:{
				cout<<"Front is: "<<Front()<<endl;
				break;
			}
			case 4:{
				Print();
				break;
			}

			case 5: return 0;

		}
	}
	return 0;
}