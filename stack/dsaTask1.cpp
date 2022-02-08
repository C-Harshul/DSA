#include<iostream>
#include<vector>
using namespace std;

class Stack{
    char v[10000];
    int top;
    public:
    Stack(){
        top = -1;
    }

    void Push(char data){
        top++;
        v[top] = data;
    }
    int length(){
        int x = 0;
        for(int i = 0;i<=top;++i){
            x++;
        }
        return x;
    }
    bool isEmpty(){
        return length() == 0;
    }
    
    void pop(){
        if(!isEmpty()){
            top--;
        }
    }
    char Top(){
        return v[top];
    }
};

bool doesFollow(Stack st){

    int b = 0;
    int a = 0;
    int len = st.length();
    if(len%2 != 0){
        return false;
    }
    while(!st.isEmpty()){
        char t = st.Top();
        if(t == 'b')
        b++;
        else 
        break;
        st.pop();
    }
    if(b == len/2){
        while(!st.isEmpty()){
            char t = st.Top();
            if(t != 'a')
            return false;
            st.pop();
        }
        return true;
    } else {
        return false;
    }

    return true;
    
}

int main(){
    string s;
    cin>>s;
    Stack st;
    for(int i = 0; s[i] != '\0'; ++i){
        st.Push(s[i]);
    }
    if(doesFollow(st)){
        cout<<"Yes";
    } else {
        cout<<"No";
    }  
    return 0;
}