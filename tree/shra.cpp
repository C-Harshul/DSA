
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

class Queue
{
public:
    Node *front;
    Node *rear;
    Queue()
    {
        front = NULL;
        rear = NULL;
    }
    void enqueue(int value)
    {
        Node *temp = new Node(value);

        if (rear == NULL)
        {
            front = rear = temp;
        }
        else
        {
            rear->next = temp;
            rear = temp;
        }
    }

    void dequeue()
    {
        if (front == NULL && rear == NULL)
        {
            cout << "Queue is empty! \n";
        }
        if (front == rear)
        {
            free(front);
            front = rear = NULL;
        }
        else
        {
            Node *temp = front;
            front = front->next;
            free(temp);
        }
    }

    void frontShow()
    {
        if (front == NULL && rear == NULL)
        {
            cout << "Queue is empty! \n";
        }
        else
        {
            cout << "The element at the front of the queue is: " << front->data;
        }
    }
    void displayQueue()
    {
        if (front == NULL && rear == NULL)
        {
            cout << "Queue is empty! \n";
        }
        else
        {
            cout << "The elements in the queue are:\n";
            Node *temp = front;
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
    }
};

int main()
{
    int c, flag = 1, value;
    Queue q;
    while (flag == 1)
    {
        cout << "\nPress 1 to enqueue \nPress 2 to dequeue \nPress 3 to view the front of the queue \nPress 4 to display the queue \nPress anything else to exit!\n";
        cin >> c;
        switch (c)
        {
        case 1:
        {

            cout << "Enter Value:\n";
            cin >> value;
            q.enqueue(value);
            break;
        }
        case 2:
        {

            q.dequeue();
            break;
        }
        case 3:
        {

            q.frontShow();
            break;
        }
        case 4:
        {

            q.displayQueue();
            break;
        }
        default:
        {

            flag = 0;
            break;
        }
        }
        return 0;
    }
}