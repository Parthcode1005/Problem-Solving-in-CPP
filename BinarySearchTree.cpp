#include <bits/stdc++.h>
using namespace std;

struct Node  
{ 
  int key; 
  struct Node *left; 
  struct Node *right; 
  Node(int k){
      key=k;
      left=right=NULL;
  }
};

bool search(Node *root, int x){
    if(root==NULL)
        return false;
    if(root->key==x)
        return true;
    else if(root->key>x){
        return search(root->left,x);
    }else{
        return search(root->right,x);
    }
} 

Node *insert(Node *root, int x){
    if(root==NULL)
        return new Node(x);
    if(root->key<x)
        root->right=insert(root->right,x);
    else if(root->key>x)
        root->left=insert(root->left,x);
    return root;
} 
Node *getSuccessor(Node *curr){
    curr=curr->right;
    while(curr!=NULL && curr->left!=NULL)
        curr=curr->left;
    return curr;
}

Node *delNode(Node *root, int x){
    if(root==NULL)
        return root;
    if(root->key>x)
        root->left=delNode(root->left,x);
    else if(root->key<x)
        root->right=delNode(root->right,x);
    else{
        if(root->left==NULL){
            Node *temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL){
            Node *temp=root->left;
            delete root;
            return temp;
        }
        else{
            Node *succ=getSuccessor(root);
            root->key=succ->key;
            root->right=delNode(root->right,succ->key);
        }
    }
    return root;
} 
void inorder(Node *root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);    
    }
}
Node* floor (Node* root, int val){
    Node* res=NULL;
    while(root!=NULL){
        if(root->key==val){
            return root;
        }
        if(root->key>val){
            root=root->left;
        }
        else{
            res=root;
            root=root->right;
        }
    }
    return res;
} 
Node* ceil (Node* root, int val){
    Node* res=NULL;
    while(root!=NULL){
        if(root->key==val){
            return root;
        }
        if(root->key<val){
            root=root->right;
        }
        else{
            res=root;
            root=root->left;
        }
    }
    return res;
}
 
int main() {
	
	Node *root=new Node(15);
	root->left=new Node(5);
	root->left->left=new Node(3);
	root->right=new Node(20);
	root->right->left=new Node(18);
	root->right->left->left=new Node(16);
	root->right->right=new Node(80);
	int x=16;
	
	if(search(root,x))
	    cout<<"Found"<<endl;
	else
	    cout<<"Not Found"<<endl;

    root=insert(root,17);
	inorder(root); 
    cout<<endl;
    root=delNode(root,15);
	inorder(root);
    cout<<endl;
    Node* Floor=floor(root,19);
    cout<<Floor->key<<endl;
    Node* Ceil=ceil(root,19);
    cout<<Ceil->key<<endl;
}