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

// Delete tail
void deleteTail(Node*&head){
    Node *t = head;
    if(t == NULL){
        cout<<"Stack empty"<<endl;
        return;
    }
    if(t->next != NULL){

    while((t->next)->next != NULL){
        t = t->next;
    }
    Node *temp = t->next;
    cout<<temp->data<<" popped"<<endl;
    delete temp;
    t->next = NULL;
    } else {
        cout<<head->data<<" popped"<<endl;
        delete(head);
        head = NULL;
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

// Operator overloading ->Cascaded (Returns cout object)
ostream& operator<<(ostream &os,Node *head){
    print(head);
    return os;
}
void pop(Node* &head){
    deleteTail(head);
}
int top(Node*head){
    Node*t = head;
    while(t->next != NULL){
        t = t->next;
    }
    return t->data;
}

int main(){
    Node*head = NULL;
    l:
    cout<<"Enter 1 : Push to stack\nEnter 2 : Pop from stack\nEnter 3 : Print stack \nEnter 4 : Get stack top\nEnter any key : Exit\nInput:";
    int n;
    cin>>n;

    switch(n) {
        case 1 : {
            int d;
            cin>>d;
            insertAtTail(head,d);
            break;
        }
        case 2 : {
            pop(head);
            break;
        }
        case 3 : {
            cout<<head<<endl;
            break;
        }
        case 4 : {
            cout<<top(head)<<endl;
            break;
        }
        default : goto X;
    }
    goto l;
    X:
    return 0;
}