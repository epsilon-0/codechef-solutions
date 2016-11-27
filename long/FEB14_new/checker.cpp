#include<iostream>

using namespace std;

int A[250][250];

void flip(int x,int y,int a,int b){
  for(int i=x;i<a+1;i++){
    for(int j=y;j<b+1;j++){
      A[i][j]=1-A[i][j];
    }
  }
}

int main(){
  int n,m;
  cin>>n>>m;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>A[i][j];
    }
  }
  int cntr,x,y,a,b;
  cin>>cntr;
  for(int i=0;i<cntr;i++){
    cin>>x>>y>>a>>b;
    flip(x-1,y-1,a-1,b-1);
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(A[i][j]==1){
	cout<<"bad"<<endl;
      }
    }
  }
}
