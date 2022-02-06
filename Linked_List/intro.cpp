#include<iostream>
using namespace std;

class Node {
    public : 
    int data;
    Node *next;
    Node(int d){
        data = d;
        next = NULL;
    }
};

// Passing the pointer by reference
void insertAtHead(Node*&head,int d){
// Dynamic allocation is done, so the memory is not wiped every time the function execution is completed

    if(head == NULL){
        head = new Node(d);
        return;
    }
    Node *n = new Node(d);
    n->next = head;
    head = n;

}

//insert at the tail

void insertAtTail(Node *&head,int d){

    if(head==NULL){
        head = new Node(d);
        return;
    }
    Node*tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    tail->next = new Node(d);

}

//Calculate the length of the Linked List
int length(Node*head){
    int count = 0;
    while(head !=NULL){
        count++;
        head = head->next;
    }
    return count;
}

// Insert element in middle
void insertInMiddle(Node*&head,int d,int pos){
   //Corner case 
   if(head==NULL || pos == 0){
       insertAtHead(head,d);
   }
   else if(pos>length(head)){
       insertAtTail(head,d);
   }
   else {
       int jump = 1;
       Node*temp = head;
       while(jump<=pos-1){
           temp = temp->next;
           jump++;
       }
       Node *t = new Node(d);
       t->next = temp->next;
       temp->next = t;
   }
} 

// Head value passed by value
void print(Node*head){
    while(head != NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<endl;
}

// deleteHead
void deleteHead(Node*&head){
    if(head == NULL){
        return;
    }
    Node *t = head->next;
    delete head;
    head = t;
}

// Delete tail
void deleteTail(Node*&head){
    Node *t = head;
    while((t->next)->next != NULL){
        t = t->next;
    }
    Node *temp = t->next;
    delete temp;
    t->next = NULL;
}

//Delete from a middle point 
void deleteMiddle(Node*&head,int p){
     if(p == 0 || head == NULL){
        deleteHead(head);
    } else if(p>=length(head)-1){
        deleteTail(head);
    }else {

    int jump = 1;
    Node *t = head;
    while(jump<=p-1){
        t = t->next;
        jump++;
    }
    Node *temp = t->next;
    t->next = temp->next;
    delete temp;
    }
}

//Searching 
int search(Node*&head,int v){
    int jump = 1;
    int pos = 0;
    Node *t = head;
    while(t != NULL){
        if(t->data == v)
        return pos;
        pos++;
        t = t->next;
    }
  return -1;
}

void take_input(Node*&head){

    int d;
    cin>>d;
    while(d!=-1){
        insertAtHead(head,d);
        cin>>d;

    }
}

Node* take_input2(){

    int d;
    cin>>d;
    Node *head = NULL;
    while(d!=-1){
        insertAtHead(head,d);
        cin>>d;
    }
    return head;
}

// Operator overloading ->Cascaded (Returns cout object)
ostream& operator<<(ostream &os,Node *head){
    print(head);
    return os;
}

//Operator overloading ->
istream& operator>>(istream &is,Node *&head){ //Need to take by reference because the original value is being updated

    head = take_input2();
    return is;

}
void reverseLinkedList(Node*&head){
 Node*t = head;
 Node  *prev = NULL;
 while(t != NULL){
     Node *temp = t->next;
     t->next = prev;
     prev = t;
     t = temp;
 }
 head = prev;
}

int main(){
    Node*head;
    cin>>head;
    print(head);
    reverseLinkedList(head);
    cout<<head;
    // insertAtHead(head,3);
    // insertAtHead(head,7);
    // insertInMiddle(head,2,15);
    // //print(head);
    // insertAtHead(head,1);
    // insertAtTail(head,12);
    // insertAtTail(head,44);
    // // print(head);
    // // deleteHead(head);
    // print(head);
    // deleteMiddle(head,3);
    // print(head);
    // deleteMiddle(head,10);
    // print(head);
    // cout<<search(head,12);



    return 0;
}