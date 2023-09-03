#include <bits/stdc++.h> 
using namespace std; 

struct Node{
    int data;
    Node* next;
    Node(int x){
        data=x;
        next=NULL;
    }
};

void printlist(Node *head){
    Node *curr=head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }cout<<endl;
}

void printMiddle(Node * &head){
    if(head==NULL)return;
    //NAIVE SOLUTION

    // int count=0;
    // Node *curr;
    // for(curr=head;curr!=NULL;curr=curr->next)
    //     count++;
    // curr=head;
    // for(int i=0;i<count/2;i++)
    //     curr=curr->next;
    // cout<<curr->data;

    //EFFICIENT SOLUTION
    Node *slow=head,*fast=head; //In this we create two pointers , slow & fast
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;               //slow will move 1 position 
        fast=fast->next->next;         //while fast will move 2 positions at a time
    }
    cout<<slow->data;                  //so by the time fast will reach end , slow will reach the middle.
}

int main() 
{ 
	Node *head=new Node(10);
	head->next=new Node(20);
	head->next->next=new Node(30);
	head->next->next->next=new Node(40);
	head->next->next->next->next=new Node(50);
    head->next->next->next->next->next=new Node(60);
	printlist(head);
	cout<<"Middle of Linked List: ";
	printMiddle(head);
	return 0;
} 
