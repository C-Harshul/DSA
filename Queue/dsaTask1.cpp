#include <iostream>
using namespace std;

class Queue
{
    char arr[10000];
    int back;
    int front;

public:
    Queue()
    {
        back = -1;
        front = -1;
    }
    Queue(char c)
    {
        arr[0] = c;
    }
    void enqueue(char c)
    {
        int displacements = 0;
        if (front == -1)
        {
            arr[++front] = c;
            ++back;
        }
        else
        {
            int pos = 0;
            for (int i = 0; i <= front; ++i)
            {
                if (c < arr[i])
                    pos = i + 1;
            }

            for (int i = front; i >= pos; --i)
            {
                arr[i + 1] = arr[i];
                displacements++;
            }
            arr[pos] = c;
            front++;
        }
        cout<<displacements<<endl;
    }
    void dequeue()
    {
        front--;
    }
    void Print()
    {
        for (int i = back; i <= front; ++i)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Queue a;
    a.enqueue('A');
    a.Print();
    a.enqueue('N');
    a.Print();
    a.enqueue('F');
    a.Print();
    a.enqueue('Z');
    a.Print();
    a.enqueue('B');
    a.Print();
    a.dequeue();
    a.Print();
    return 0;
}