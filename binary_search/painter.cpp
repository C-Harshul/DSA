#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isPossible(int board[],int k,int n,int time_check){
  int boardPos = 0;
  for(int i = 0;i<k;++i){
	int time = 0;
	for(int j = boardPos;j<n;++j){
		time = time + board[j];
		if(time <= time_check){
         boardPos++;
		}else break;
	}
  }
  if(boardPos >= n)
  return true;
  else 
  return false;
}

int main() {

	int k,n,board[10];
	cin>>k>>n;
	for(int i =0;i<n;++i){
		cin>>board[i];
	}
    
	int s = 0;
	int e;
	for(int i=0;i<n;++i){
		e = e+board[i];
	}
	int ans = e;
	while(s<=e){
		int mid = (s+e)/2;
		if(isPossible(board,k,n,mid)){
		  ans = mid;	
          e = mid - 1;
		} else {
		  s = mid + 1;
		}
	}

	cout<<ans;
    
	return 0;
}