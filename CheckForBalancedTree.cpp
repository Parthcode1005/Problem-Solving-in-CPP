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
                        //NAIVE SOLUTION
int height(Node *root){
    if(root==NULL)
        return 0;
    else
        return (1+max(height(root->left),height(root->right)));
}

bool isBalancedN(Node *root){
    if(root==NULL)
        return true;
    int lh=height(root->left);
    int rh=height(root->right);
    return (abs(lh-rh)<=1 && isBalancedN(root->left) && isBalancedN(root->right));
}

                        //EFFICIENT SOLUTION
    int isBalancedE(Node *root){
    if(root==NULL)
        return 0;
    int lh=isBalancedE(root->left);
    if(lh==-1)return -1;
    int rh=isBalancedE(root->right);
    if(rh==-1)return -1;
    
    if(abs(lh-rh)>1)
        return -1; 
    else
        return max(lh,rh)+1;
}
int main() {
	
	Node *root=new Node(10);
	root->left=new Node(5);
	root->right=new Node(30);
	root->right->left=new Node(15);
	root->right->right=new Node(20);
	
	cout<<isBalancedN(root)<<endl;
    if(isBalancedE(root)==-1){
        cout<<"False"<<endl;
    }
    else{
        cout<<"True"<<endl;
    }
}