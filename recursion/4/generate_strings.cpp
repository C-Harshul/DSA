 #include<iostream>
 using namespace std;

void generateString(string num,char *out,int n,int i = 0,int j = 0){
   
    if(num[i] == '\0'){
        out[j] = '\0';
        cout<<out<<endl;
        return;
    }
    int ch = num[i] - '0';
    char c = ch + 64;
    out[j] = c;
    generateString(num,out,n-1,i+1,j+1);
    int Ch = (num[i] - '0')*10 + (num[i+1] - '0');
    if(Ch<=26 && Ch>=1){
        char C = Ch + 64;
        out[j] = C;
        generateString(num,out,n-2,i+2,j+1);
    }

    return;
    
}

int main(){
    string num;
    cin>>num;
    char out[1000];
    int n = num.length();
    generateString(num,out,n);
    return 0;
}