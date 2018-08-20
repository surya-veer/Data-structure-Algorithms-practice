#include<bits/stdc++.h>
#define print(x) cout<<x<<endl;
using namespace std;

struct Trie{
	bool isLeaf;
	unordered_map< char, Trie* > map;
};

Trie* getNewNode(){
	Trie* node  = new Trie;
	node->isLeaf = false;
	return node;
}

void insert(Trie* &root, string str){
	if(root==nullptr){
		root = getNewNode();
	}

	Trie* curr = root;
	for(auto c: str){

		if( curr->map[ c ] == nullptr ){
			cout<<c;
			curr->map[ c ] = getNewNode();
		}
		curr = curr->map[ c ];
	}
	curr->isLeaf = true;
}

// search word
bool search(Trie* root, string str){
	if(root==nullptr) return false;

	Trie* curr = root;
	for(auto c:str){
		curr = curr->map[ c ];
		if(curr==nullptr)
			return false;
	}
	if(curr->isLeaf) return true;
	return false;
}
// stack implementation of remove 
// void remove(Trie* &root, string str){
// 	stack<Trie*> st;
// 	Trie* curr = root;
// 	for(auto c:str){
// 		if(curr->map[ c ]==nullptr) return;
// 		st.push(curr);
// 		curr = curr->map[ c ];
// 	}
// 	curr->isLeaf = false;

// 	if(!curr->map.size()){
// 		return; 
// 	}
// 	else{
// 		print("xx");
// 		for(int i=0;i<st.size();i++){
// 			if(!curr->map.size()){
// 				print("xx");
// 				delete(curr);
// 				curr = st.top();
// 				st.pop();
// 			}
// 			else return;
// 		}
// 	}
// }

bool haveChildren(Trie* &curr){

	// do not use map.size() because size of map will not zero after putting nullptr to some key
	// so we have to check all the keys of map
    for (auto it : curr->map)
        if (it.second != nullptr)
            return true;
    return false;
}

// Recursive function to delete
void helper(Trie* &root, string str, int pos){
	
	if(str[pos]=='\0') {
		root->isLeaf = false;
		if(!haveChildren(root)) 
			root = nullptr;
		return;
	}
	helper(root->map[ str[pos] ],str, pos+1);
	if(!haveChildren(root)){
		delete(root);
		root = nullptr;
	}

}
//stack implimentation of remove 
void remove(Trie* &root, string str){
	Trie* curr = root;
	helper(root,str, 0);
}

int main(){

	Trie* root = nullptr;
    insert(root, "hello");
    cout << search(root,"hello")<<endl;
    remove(root,"hello");
    cout << search(root,"hello")<<endl;
    insert(root, "he");
    cout<<endl;
    insert(root, "hello");;
	return 0;
}