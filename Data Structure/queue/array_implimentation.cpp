//this code is for array implimentation of queue using concept of circular imterpetation

#include<bits/stdc++.h>
using namespace std;

#define MAX_SIZE 5

int A[5];
int front = -1 , rear = -1;

int IsFull(){

	if((rear+1)%MAX_SIZE == front)
		return true;
	else
		return false;
}

int IsEmpty(){

	if(front==-1&&rear==-1)
		return true;
	else
		return false;
}

void EnQueue(int x){

	if(IsFull()){
		cout<<"Queue is full, can't be insert! "<<endl;
	}
	else if(IsEmpty()){
		front = 0;
		rear = 0;
	}
	else{
		rear = (rear+1)%MAX_SIZE;
	}
	A[rear] = x;
}

void DeQueue(){

	if(IsEmpty()){
		cout<<"Queue is Empty, can't be delete! "<<endl;
	}
	else if(front==0&&rear==0){
		front = -1;
		rear = -1;
	}
	else{
		front = (front + 1)%MAX_SIZE;
	}
}

int Front(){
	if(IsEmpty()){
		cout<<"Queue is Empty! "<<endl;
	}
	else{
		return A[front];
	}
}
void Print(){
	cout<<"Elements in Queue is: ";
	if(!IsEmpty()){
		for(int i=front;i<=(rear);i++){
			cout<<A[i]<<" ";
		}
	}
	cout<<endl;
}

int main(){

	EnQueue(5);
	EnQueue(505);
	EnQueue(5450);
	EnQueue(5);
	EnQueue(504);
	EnQueue(504);
	cout<<rear<<" "<<front;
	Print();
	cout<<Front()<<endl;
}