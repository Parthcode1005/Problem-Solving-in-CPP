#include <bits/stdc++.h>
using namespace std;

struct Node
{
    /* data */
    int data;
    Node *next;
    Node(int x){
    data=x;
    next=NULL;
    }
};
int main(){
    int n;
    cin>>n;
    int a;
    cin>>a;
    Node *head=new Node(a);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        Node* temp1=new Node(x);
        temp1=head->next;
    }
//  Node *temp1=new Node(20);
//  Node *temp2=new Node(30);
//  head->next=temp1;
//  temp1->next=temp2;
//  cout<<head->data<<" "<<temp1->data<<" "<<temp2->data<<endl;
 while(head!=NULL){
    cout<<head->data<<endl;
    head=head->next;
 }
 return 0;   
}
