#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node *left;
    Node *right;
    Node(int k){
        key=k;
        left=right=NULL;
    }
};
void inorder(Node* &root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
}
void preorder(Node* &root){
    if(root!=NULL){
        cout<<root->key<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(Node* &root){
    if(root!=NULL){
    postorder(root->left);
    postorder(root->right);
    cout<<root->key<<" ";
    }
}
int height(Node* &root){
    if(root==NULL){
        return 0;
    }
    else{
        return max(height(root->left),height(root->right))+1;
    }
}
void printKDist(Node* &root,int k){
    if(root==NULL){
        return ;
    }
    if(k==0){
        cout<<root->key<<" ";
    }
    else{
        printKDist(root->left,k-1);
        printKDist(root->right,k-1);
    }
}
vector<int> levelOrder(Node* root){
    vector<int> v;
    if(root==NULL){
        return v;
    }
    queue<Node*> q;
    q.push(root);
    while(q.empty() == false){
        Node* node=q.front();
        q.pop();
        v.push_back(node->key);
        if(node->left!=NULL){
            q.push(node->left);
        }
        if(node->right!=NULL){
            q.push(node->right);
        }
    }
    return v;
}
int getMax(Node* root){
    if(root==NULL){
        return INT_MIN;
    }
    return max(root->key,max(getMax(root->left),getMax(root->right)));
}
int getMin(Node* root){
    if(root==NULL){
        return INT_MAX;
    }
    return min(root->key,min(getMin(root->left),getMin(root->right)));
}
// Recursive function to print
// left view of a binary tree.
void leftViewUtil(struct Node* root, int level,
                  int* max_level)
{
    // Base Case
    if (root == NULL)
        return;
 
    // If this is the first Node of its level
    if (*max_level < level) {
        cout << root->key << " ";
        *max_level = level;
    }
 
    // Recur for left subtree first,
    // then right subtree
    leftViewUtil(root->left, level + 1, max_level);
    leftViewUtil(root->right, level + 1, max_level);
}
 
// A wrapper over leftViewUtil()
void leftView(struct Node* root)
{
    int max_level = 0;
    leftViewUtil(root, 1, &max_level);
}
// Recursive function to print
// left view of a binary tree.
void rightViewUtil(struct Node* root, int level,
                  int* max_level)
{
    // Base Case
    if (root == NULL)
        return;
 
    // If this is the first Node of its level
    if (*max_level < level) {
        cout << root->key << " ";
        *max_level = level;
    }
 
    // Recur for right subtree first,
    rightViewUtil(root->right, level + 1, max_level);
    // then left subtree
    rightViewUtil(root->left, level + 1, max_level);
    
}
 
// A wrapper over leftViewUtil()
void rightView(struct Node* root)
{
    int max_level = 0;
    rightViewUtil(root, 1, &max_level);
}

int main(){
	Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->right->left=new Node(40);
	root->right->right=new Node(50);
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    cout<<height(root)<<endl;

    printKDist(root,1);
    cout<<endl;

    vector<int> v = levelOrder(root);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    int maxValue=getMax(root);
    int minValue=getMin(root);
    cout<<maxValue<<" "<<minValue<<endl;
    rightView(root);
    cout<<endl;
    leftView(root);
    cout<<endl;
    return 0;
}