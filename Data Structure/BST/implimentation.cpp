//this is recursive implimentation of Binary Search Tree

#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
};
Node* CreateNode(int data){
	Node* BSTnode = new Node();
	BSTnode->data = data;
	BSTnode->left = NULL;
	BSTnode->right = NULL;
}
Node* Insert(Node* root, int data){
	if(root==NULL){
		root = CreateNode(data);
	}
	else if(data <= root->data){
		root->left = Insert(root->left, data);
	}
	else if(data> root->data){
		root->right = Insert(root->right, data);
	}
	return root;
}
int Search(Node* root, int data){

	if(root==NULL) 
		return false;
	else if(data == root->data)
		return true;
	else if(data <= root->data){
		cout<<root->data<<" ";
		return Search(root->left,data);
	}
	else if(data > root->data){
		cout<<root->data<<" ";
		return Search(root->right,data);
	}
	cout<<endl;
}

int main(){
	Node* root = NULL;
 
	root = Insert(root,15);
	root = Insert(root,10);
	root = Insert(root,20);
	root = Insert(root,8);
	root = Insert(root,12);
	root = Insert(root,17);
	root = Insert(root,25);
 
	cout<<Search(root,25)<<endl;
}