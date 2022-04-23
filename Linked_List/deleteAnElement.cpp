#include<iostream>
using namespace std;

class Node { 

    public:
    int val;
    Node * next;
    Node (int v){
        val = v;
        next = nullptr;
    }
    
};

void addToTail(Node*&head,int v){

    if(head == nullptr){
        head = new Node(v);
        return;
    }
    Node *temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = new Node(v);
    return;
}

void deleteFromList(Node *&head,int v){
    if(head == nullptr){
        return;
    }
    if(head->val == v){
        Node * t = head->next;
        delete(head);
        head = t;
        return;
    }
    Node *cur = head->next;
    Node *prev = head;
    while(cur->next != nullptr){
        if(cur->val == v){
            Node *t = cur->next;
            delete(cur);
            prev->next = t;

        }
        prev = prev->next;
        cur = cur->next;
    }
    if(cur->val == v){
        prev->next = nullptr;
        delete(cur);
    }
    if(v%2 == 0){
        addToTail(head,v);
    }
}

void printList(Node*head){
    while(head != nullptr){
        cout<<head->val<<"->";
        head = head->next;
    }
}

int main(){ 

    int n;
    Node *head = nullptr;
    l:
    cout<<"Enter 1 : Add element to linked list\nEnter 2 : Delete an element from the linked list\nEnter 3 : Print the linked List\nEnter 4 : exit\n:";
    cin>>n;
    switch(n) {
        case 1 : {
            int t;
            cout<<"Enter the element you want to add : ";
            cin>>t;
            addToTail(head,t);
            break;
        }
        case 2 : {
            int t;
            cout<<"Enter the element you want to delete from the linked list : ";
            cin>>t;
            deleteFromList(head,t);
            break;
        }
        case 3 :{
            printList(head);
            cout<<endl;
            break;
        }
        case 4 :{
            goto x;
        }
    }
    goto l;
    x:
    return 0;
}