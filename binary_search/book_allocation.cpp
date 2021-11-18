#include<iostream>
#include <numeric> 

using namespace std;

bool checkPagePossibility(int pages[],int n,int stu,int min_pages){
    
    int studentCount = 1;
    int currpages = 0;
   
    for(int i = 0;i<n;++i){
     if(currpages + pages[i]>min_pages){
         studentCount++;
         currpages = pages[i];
         if(studentCount>stu){
             return false;
         }
     } else {
         currpages += pages[i];
     }
        
    }
    return true;
}

int main() {
    int t;
    cin>>t;
    for(int i = 0;i<t;++i){
        int n,stu,sum = 0;
        cin>>n>>stu;
        int pages[1000];
        for(int j = 0;j<n;++j){
            cin>>pages[j];
            sum+=pages[j];
        }
        int ans = sum;
        int s = pages[n-1];
        int e = sum;

    
        while(s<=e){
            int mid = (s+e)/2;
            bool isMinPagesPossible = checkPagePossibility(pages,n,stu,mid);
            if(isMinPagesPossible){
                ans = mid;
                e = mid -1;
            } else {
                s = mid + 1;
            }
        }
        cout<<ans<<endl;
    }
    
    
    return 0;
}