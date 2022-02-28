#include <iostream>
using namespace std;

class Queue
{
    char arr[10000];
    int back;
    int front;
    int totalDisplacements;

public:
    Queue()
    {
        back = -1;
        front = -1;
        totalDisplacements = 0;
    }
    Queue(char c)
    {
        arr[0] = c;
    }
    void enqueue(char c)
    {
        int displacements = 0;
        if (back == -1 || front == -1)
        {
            arr[0] = c;
            back = 0;
            front = 0;
        }
        else
        {

            int pos = front;
            for (int i = front; i <= back; ++i)
            {
                if (c > arr[i])
                    pos = i + 1;
            }
            for (int i = back; i >= pos; --i)
            {
                arr[i + 1] = arr[i];
                displacements++;
            }
            arr[pos] = c;
            ++back;
        }
        cout <<"Displacemensts adding "<<c<<" : "<< displacements << endl;
        totalDisplacements += displacements;
    }
    void dequeue()
    {
        if(front>back){
            cout<<"Queue empty";
            return;
        }
        front++;
    }
    void Print()
    {
        for (int i = back; i >= front; --i)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    int getTotalDisplacements (){
        return totalDisplacements;
    }
};

int main()
{
    Queue a;
    L:
    cout<<"Enter 1 to add to Enqueue \nEnter 2 to dequeue \nEnter anything else to exit "<<":";
    int n = 0;
    cin>>n;
    switch(n){
        case 1 : {
            char c;
            cin>>c;
            a.enqueue(c);
            cout<<endl;
            a.Print();
            cout<<endl;
            break;
        }

        case 2 : {
            a.dequeue();
            cout<<endl;
            a.Print();
            cout<<endl;
            break;
        }
        default: goto X;
    }
    goto L;
    X:
    cout<<"Total displacements to get current arrangement :"<<a.getTotalDisplacements()<<endl;
    return 0;
}