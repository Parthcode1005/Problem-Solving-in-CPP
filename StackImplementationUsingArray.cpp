#include<bits/stdc++.h>
using namespace std;

struct myStack{
    int *arr;
    int cap;
    int top;

    myStack(int c){
        cap=c;
        arr=new int[cap];
        top=-1;
    }
    void push(int x){
        if(top==cap-1){
            cout<<"Stack is full"<<endl;
        }
        top++;
        arr[top]=x;
    }
    int pop(){
        if(top==-1){
            cout<<"Stack is empty"<<endl;
        }
        int rem=arr[top];
        top--;
        return rem;
    }
    int peek(){
        if(top==-1){
            cout<<"Stack is empty"<<endl;
        }
        return arr[top];
    }
    int size(){
        return (top+1);
    }
    bool isEmpty(){
        return (top==-1);
    }
};

int main(){

    myStack s(5);
    s.push(5);
    s.push(10);
    s.push(20);
    cout<<s.pop()<<endl;
    cout<<s.size()<<endl;
    cout<<s.peek()<<endl;
    cout<<s.isEmpty()<<endl;
  
    return 0;
}