#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

class CircularQueue
{
public:
    int currentSize;
    Node *front;
    Node *rear;
    CircularQueue()
    {
        front = NULL;
        rear = NULL;
        currentSize = 0;
    }
    CircularQueue(int d, int s)
    {
        front = new Node(d);
        rear = front;
        currentSize = 1;
    }
    void enQueue(int d)
    {
        Node *t = new Node(d);

        if (front == NULL)
        {
            front = t;
        }
        else
        {
            rear->next = t;
        }
        rear = t;
        rear->next = front;
        currentSize++;
    }
    void deQueue()
    {
        if (currentSize == 0)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << front->data << " Dequeued" << endl;
        Node *t = front;
        front = t->next;
        rear->next = front;
        delete t;
        currentSize--;
    }
    void print()
    {   
        if(front == NULL){
            cout<<"Circular queue is empty"<<endl;
            return;
        }
        Node *t = front;
        while (t->next != front)
        {
            cout << t->data << "->";
            t = t->next;
        }
        cout << t->data;
    }
};

int main()
{
    CircularQueue q;
l:
    cout << "Enter 1 : Enqueue\nEnter 2 : Dequeue\nEnter 3 : Print\nEnter 4 : Get front\nEnter 5 : Get rear\nEnter anything else : Exit\nInput : ";
    int n;
    cin >> n;
    switch (n)
    {
    case 1:
    {
        int t;
        cin >> t;
        q.enQueue(t);
        cout << endl;
        break;
    }
    case 2:
    {
        q.deQueue();
        cout << endl;
        break;
    }
    case 3:
    {
        q.print();
        cout << endl;
        break;
    }
    case 4:
    {
        cout << q.front->data << endl;
        break;
    }
    case 5:
    {
        cout << q.rear->data << endl;
        break;
    }
    default:
        goto X;
    }
    goto l;
X:

cout<<"The value that rear->next points to :"<<q.rear->next->data;
    return 0;
}
