#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node *left,*right;
	Node(int val)
	{
		data=val;
		left=NULL;
		right=NULL;
	}
};
Node* insertBST(Node *root,int val)
{
	if(root==NULL)
	{
		return new Node(val);
	}
	if(val<root->data)
	{
		root->left=insertBST(root->left,val);
	}
	else
	{
		root->right=insertBST(root->right,val);
	}
	return root;
}
int ansS=-1,ansL=-1;
void inorderS(Node* root, int &k){
    if(root==NULL){
        return ;
    }
    inorderS(root->left,k);
    if(--k==0){
        ansS=root->data;
    }
    inorderS(root->right,k);
}
int KthSmallest(Node* root, int k){
    inorderS(root,k);
    return ansS;
}
void inorderL(Node* root, int &k){
    if(root==NULL){
        return ;
    }
    inorderL(root->right,k);
    if(--k==0){
        ansL=root->data;
    }
    inorderL(root->left,k);
}
int KthLargest(Node* root, int k){
    inorderL(root,k);
    return ansL;
}
int main()
{
	
	int arr[]={10,40,45,20,25,30,50},i;
	
	int k=3;
	Node* root=NULL;
	for(i=0;i<7;i++)
	{
		root=insertBST(root,arr[i]);
	}
	cout<<"\n";
	
	int p=k;
	int large=KthLargest(root,k);
	k=p;
	int small=KthSmallest(root,k);
	if(large==-1)
	{
		cout<<"Invalid input"<<"\n";
	}
	else
	cout<<"kth largest element is  "<<large<<"\n";
	
	if(small==-1)
	{
		cout<<"Invalid input"<<"\n";
	}
	else
	{
		cout<<"kth smallest element is  "<<small<<"\n";
	}
}