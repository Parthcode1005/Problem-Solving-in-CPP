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

struct myStack{
    Node* head;
    int size;

    myStack(){
        head=NULL;
        size=0;
    }
    void push(int x){
        Node* temp=new Node(x);
        temp->next=head;
        head=temp;
        size++;
    }
    int pop(){
        if(head==NULL){
            return size;
        }
        int rem=head->data;
        Node*temp=head;
        head=head->next;
        delete(temp);
        size--;
        return rem;
    }
    int length(){
    return size;
    }
    int peek(){
    if(head==NULL){
        return INT16_MAX;
    }
    return head->data;
    }
    bool isEmpty(){
        return (head==NULL);
    }
};
int main(){
    myStack s;
    s.push(5);
    s.push(10);
    s.push(20);
    cout<<s.pop()<<endl;
    cout<<s.length()<<endl;
    cout<<s.peek()<<endl;
    cout<<s.isEmpty()<<endl;
    return 0; 
}