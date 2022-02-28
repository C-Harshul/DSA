#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int d)
    {
        data = d;
        next = NULL;
        prev = NULL;
    }
};

class CircularQueue
{
public:
    Node *front;
    Node *rear;
    CircularQueue()
    {
        front = NULL;
        rear = NULL;
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
            t->prev = rear;
            rear->next = t;
        }
        rear = t;
        rear->next = front;
        front->prev = rear;
    }
    void deQueue()
    {
        if (front == NULL)
        {
            cout << "The circular queue is empty" << endl;
            return;
        }
        cout << front->data << " Dequeued" << endl;
        if (front == rear)
        {
            Node *t = front;
            front = NULL;
            rear = NULL;
            delete t;
            return;
        }

        Node *t = front;
        front = t->next;
        front->prev = t->prev;
        rear->next = front;
        delete t;
    }
    void print()
    {
        if (front == NULL)
        {
            cout << "Circular queue is empty" << endl;
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
    cout<<"Rear->next points to front having data : ";
    cout << q.rear->next->data << endl; // Rear->next points to front
    cout<<"Front->prev points to rear having data : ";
    cout << q.front->prev->data << endl; // Front->prev points to rear
    return 0;
}