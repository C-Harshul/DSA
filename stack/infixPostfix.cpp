#include<bits/stdc++.h>
using namespace std;

int prec(char c) {
    if(c == '^')
        return 3;
    else if(c == '/' || c=='*')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}

class Stack{
    char v[10000];
    int top;
    public:
    Stack(){
        top = -1;
    }

    void push(char data){
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
    bool empty(){
        return length() == 0;
    }
    
    void pop(){
        if(!empty()){
            top--;
        }
    }
    char Top(){
        return v[top];
    }
};

void infixToPostfix(string s) {
 
    Stack st; 
    string result;
 
    for(int i = 0; i < s.length(); i++) {
        char c = s[i];
 
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result += c;

        else if(c == '(')
            st.push('(');
 
      
        else if(c == ')') {
            while(st.Top() != '(')
            {
                result += st.Top();
                st.pop();
            }
            st.pop();
        }
        else {
            while(!st.empty() && prec(s[i]) <= prec(st.Top())) {
                result += st.Top();
                st.pop(); 
            }
            st.push(c);
        }
    }
    while(!st.empty()) {
        result += st.Top();
        st.pop();
    }
 
    cout << result << endl;
}
 
int main() {
    string exp;
    cin>>exp;
    infixToPostfix(exp);
    return 0;
}