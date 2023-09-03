#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;

    Node(int x){
        this->data=x;
        this->next=NULL;
    }
};

void sortedInsert(Node* &head,int value){
    Node* temp=new Node(value);
    if(head==NULL){
        head=temp;
        return;
    }
    else if(temp->data <= head->data){
        temp->next=head;
        head=temp;
        return;
      }
    else{
        Node* curr=head;
        while(curr->next!=NULL && curr->next->data<value)
        {
            curr=curr->next;
        }
        temp->next=curr->next;
        curr->next=temp;
    }
}
void printlist(Node* &head)
    {
      if(head==NULL){
        return ;
    }
        cout<<head->data<<" ";
        printlist(head->next);
    }
int main(){
    Node *head=NULL;
    sortedInsert(head,25);
    sortedInsert(head,10);
    sortedInsert(head,5);
    sortedInsert(head,15);

    printlist(head);
	cout<<endl;
    return 0;
  }