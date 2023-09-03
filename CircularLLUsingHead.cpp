// C++ program to implement
// the above approach
#include <bits/stdc++.h>
using namespace std;

/* structure for a node */
class Node{
	public:
	int data;
	Node *next;

    Node(int d) {
        this->data = d;
        this->next = NULL;
    }
};

/* Function to insert a node at the beginning
of a Circular linked list */
void push(Node* &head_ref, int data)
{
	Node *ptr1 = new Node(data);
	Node *temp = head_ref;
	ptr1->data = data;
	ptr1->next = head_ref;

	/* If linked list is not NULL then
	set the next of last node */
	if (head_ref != NULL)
	{
		while (temp->next != head_ref)
			temp = temp->next;
		temp->next = ptr1;
	}
	else
		ptr1->next = ptr1; /*For the first node */

	head_ref = ptr1;
}
void insertATBegin(Node* &head,int data){
    Node* temp=new Node(data);
    if(head==NULL){
        temp->next=temp;
    }
    else{
        // Node* curr=head;
        // while(curr->next!=head){
        //     curr=curr->next;
        // }
        // curr->next=temp;
        // temp->next=head;
        // head=temp;
        temp->next=head->next;  //Insert Element at 2nd position and then just swipe the data elements
        head->next=temp;
        int t=head->data;
        head->data=temp->data;
        temp->data=t;
    }
}

void insertATEnd(Node* &head,int data){
    Node* temp=new Node(data);
    if(head==NULL){
        temp->next=temp;
        return ;
    }
    else{
        Node* curr=head;
        while(curr->next!=head){
            curr=curr->next;
        }
        curr->next=temp;
        temp->next=head;

    }
}
/* Function to print nodes in
a given Circular linked list */

Node *delHead(Node *head){
    if(head==NULL)return NULL;
    if(head->next==head){
        delete head;
        return NULL;
    }
    // Node *curr=head;
    // while(curr->next!=head)
    //     curr=curr->next;
    // curr->next=head->next;
    // delete head;
    // return (curr->next);
    head->data=head->next->data;
    Node *temp=head->next;
    head->next=head->next->next;
    delete temp;
    return head;
}
Node *deleteKth(Node *head,int k){
    if(head==NULL)return head;
    if(k==1)return delHead(head);
        Node *curr=head;
    for(int i=0;i<k-2;i++)
        curr=curr->next;
    Node *temp=curr->next;
    curr->next=curr->next->next;
    delete temp;
    return head;
}
void printList(Node *head)
{
	Node *temp = head;
	if (head != NULL)
	{
		do
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		while (temp != head);
	}
    cout<<endl;
}

/* Driver program to test above functions */
int main()
{
	/* Initialize lists as empty */
	Node *head = NULL;

	/* Created linked list will be 11->2->56->12 */
	push(head, 12);
	push(head, 56);
	push(head, 2);
	push(head, 11);

	cout << "Contents of Circular Linked List\n ";
	printList(head);

    insertATBegin(head,89);
    printList(head);

    insertATEnd(head,19);
    printList(head);

    head=delHead(head);
    printList(head);

    head=deleteKth(head,3);
	printList(head);
	return 0;
}
