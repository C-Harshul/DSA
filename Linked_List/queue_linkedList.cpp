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

// Head value passed by value
void print(Node*head){
    if(head == NULL){
        cout<<"Queue is empty"<<endl;
        return;
    }
    while(head != NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<endl;
}

// deleteHead
void deleteHead(Node*&head){
    if(head == NULL){
        cout<<"Queue is empty"<<endl;
        return;
    }
    Node *t = head->next;
    cout<<head->data<<" Dequeued"<<endl;
    delete head;
    head = t;
}

Node* take_input2(){

    int d;
    cin>>d;
    Node *head = NULL;
    while(d!=-1){
        insertAtTail(head,d);
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

int rear(Node *head){
    Node *t = head;
    while(t->next != NULL){
        t = t->next;
    }
    return t->data;
}

int front(Node *head){
    return head->data;
}

int main(){
    Node*queue = NULL;
    l:
    cout<<"Enter 1 : Enqueue\nEnter 2 : Dequeue\nEnter 3 : Print\nEnter 4 : Get front\nEnter 5 : Get rear\nEnter anything else : Exit\nInput : ";
    int n;
    cin>>n;
    switch(n){
        case 1: {
            int t;
            cin>>t;
            insertAtTail(queue,t);
            cout<<endl;
            break;
        }
        case 2: {
            deleteHead(queue);
            cout<<endl;
            break;
        }
        case 3: {
            print(queue);
            cout<<endl;
            break;
        }
        case 4:{
            cout<<front(queue)<<endl;
            break;
        }
        case 5:{
            cout<<rear(queue)<<endl;
            break;
        }
        default : goto X;
    }
    goto l;
    X:
    return 0;
}