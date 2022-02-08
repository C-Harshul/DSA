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
            }
            arr[pos] = c;
            front++;
        }
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
    a.enqueue('N');
    a.enqueue('F');
    a.enqueue('Z');
    a.enqueue('B');
    a.Print();
    a.dequeue();
    a.Print();
    return 0;
}