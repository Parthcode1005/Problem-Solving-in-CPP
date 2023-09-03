#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int x){
        this->data=x;
        this->next=NULL;
    }
};
void insertAtBegin(Node* &head, int x){
    Node *temp= new Node(x);
    temp->next = head;
    head = temp;
}
void insertAtEnd(Node* &head,int x){
    Node *temp=new Node(x);
    if(head==NULL){      //If LinkedList is Empty
        head->next=temp;
        head = temp;
    }
    Node *curr = head;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    curr->next=temp;
}
void delHead(Node* &head){
    if(head==NULL){             //If LinkedList is empty
        cout<<head->data<<endl;
    }
    else{
        delete head;
        head=head->next;
    }
}
void delTail(Node* &head){
    if(head==NULL){            //If LnkedList is empty
        cout<<head->data<<endl;
    }
    if(head->next==NULL){      //If LinkedList has only one element
        delete head;
    }
    Node* curr=head;
    while(curr->next->next!=NULL){
        curr=curr->next;
    }
    delete curr;
    curr->next=NULL;
}

void InsertAtAnyPosition(Node* &head,int pos,int x){
    Node* temp=new Node(x);
    if(head==NULL){
        cout<<head->data<<endl;
    }
    Node* curr=head;
    for(int i=1;i<pos-1;i++){
        curr=curr->next;
    }
    if(curr==NULL){
        cout<<"Cannot add"<<endl;
    }
    temp->next=curr->next;
    curr->next=temp;
}
void print(Node* &head){
    if(head==NULL){
        return ;
    }
        cout<<head->data<<endl;
        print(head->next);
}

void Search(Node* &head,int x){
    if(head==NULL){
        cout<<" "<<endl;
    }
    Node* curr=head;
    int pos=1;
    int res=-1;
    while(curr->next!=NULL){
        if(curr->data==x){
            res=pos;
        }
        else{
            pos++;
            curr=curr->next;
        }
    }
    if(res==-1){
        cout<<"Not Found!"<<endl;
    }
    else{
        cout<<res<<endl;
    }
}
int main(){
    Node *head= NULL;
    insertAtBegin(head,30);
    insertAtBegin(head,20);
    insertAtBegin(head,10);

    insertAtEnd(head,40);
    insertAtEnd(head,50);

    // delHead(head);
    // delHead(head);

    // delTail(head);
    
    InsertAtAnyPosition(head,4,35);
    
    Search(head,35);
    Search(head,60);
    print(head);
    return 0;
}