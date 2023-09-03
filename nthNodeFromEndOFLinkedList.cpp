#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int x){
        this->data=x;
        this->next=NULL;
    }
};

void printNthNode(Node* &head,int n){
    int count=0;
    Node* curr=head;
    while(curr->next!=NULL){
        curr=curr->next;
        count++;
    }
    curr=head;
    for(int i=0;i<count-n+1;i++){
        curr=curr->next;
    }
    cout<<curr->data<<endl;
}

int main(){
    Node *head=new Node(10);
	head->next=new Node(20);
	head->next->next=new Node(30);
	head->next->next->next=new Node(40);
	head->next->next->next->next=new Node(50);
    head->next->next->next->next->next=new Node(60);
	cout<<"Nth Node From END of Linked List is ";
	printNthNode(head,3);
	return 0;
}
