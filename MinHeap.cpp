#include <bits/stdc++.h> 
using namespace std; 

class MinHeap{
    int *arr;
    int size;
    int capacity;
    
    public:
    MinHeap(int c){
    size = 0; 
    capacity = c; 
    arr = new int[c];
    }

    int left(int i) { return (2*i + 1); } 
    int right(int i) { return (2*i + 2); } 
    int parent(int i) { return (i-1)/2; } 
    
    void insert(int x) 
    { 
    if (size == capacity)return;
    size++; 
    arr[size-1]=x; 
 
    for (int i=size-1;i!=0 && arr[parent(i)]>arr[i];) 
    { 
       swap(arr[i], arr[parent(i)]); 
       i = parent(i); 
    } 
    }

    void deleteFromHeap(){
        if(size == -1){
            cout<<" nothing to delete"<< endl;
        }
        //step1: Put last element in first index
        arr[0]=arr[size];
        //Step2; Remove last element
        size--;

        //Step3: take root node to its correct position
        int i=0;
        while(i<size){
            if(left(i) < size && arr[i] > arr[left(i)]){
                swap(arr[i],arr[left(i)]);
                i=left(i);
            }
            else if(right(i) <size && arr[i]>arr[right(i)]){
                swap(arr[i],arr[right(i)]);
                i=right(i);
            }
            else{
                return ;
            }
        }
    }
    void print(){
        for(int i=0;i<capacity;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main() 
{ 
    MinHeap h(4);
    h.insert(3); 
    h.insert(2);
    h.insert(15);
    h.insert(20);
    h.print();
    h.deleteFromHeap();
    h.print();
    return 0;
} 
