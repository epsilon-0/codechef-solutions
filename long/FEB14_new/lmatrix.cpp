#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cassert>

using namespace std;

int A[250][250],B[250][250];
vector<pair<pair<int,int>,pair<int,int> > > tt,zz;

void flip(int x,int y,int a,int b);
pair<int,int> maxrect(int x,int y,int n,int m);

int main(){
  int n,m,x,y;
  cin>>n>>m;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>A[i][j];
      B[i][j]=A[i][j];
    }
  }
  pair<int,int> tmp;
  int cntr=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(A[i][j]){
	tmp=maxrect(i,j,n,m);
	flip(i,j,tmp.first,tmp.second);
	tt.push_back(make_pair(make_pair(i,j),tmp));
	cntr++;
      }
    }
  }
  assert(cntr<n*m);
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      A[i][j]=B[i][j];
    }
  }
  // Now we flip the whole matrix and do this again
  flip(0,0,n-1,m-1);
  int cntr1=1;
  zz.push_back(make_pair(make_pair(0,0),make_pair(n-1,m-1)));
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(A[i][j]){
	tmp=maxrect(i,j,n,m);
	flip(i,j,tmp.first,tmp.second);
	zz.push_back(make_pair(make_pair(i,j),tmp));
	cntr1++;
      }
    }
  }
  if(cntr<cntr1){
    cout<<cntr<<endl;
    for(int i=0;i<tt.size();i++){
      cout<<tt[i].first.first+1<<" "<<tt[i].first.second+1<<" "<<tt[i].second.first+1<<" "<<tt[i].second.second+1<<endl;
    }
  }
  else{
    cout<<cntr1<<endl;
    for(int i=0;i<zz.size();i++){
      cout<<zz[i].first.first+1<<" "<<zz[i].first.second+1<<" "<<zz[i].second.first+1<<" "<<zz[i].second.second+1<<endl;
    }
  }
}

void flip(int x,int y,int a,int b){
  for(int i=x;i<a+1;i++){
    for(int j=y;j<b+1;j++){
      A[i][j]=1-A[i][j];
    }
  }
}

pair<int,int> maxrect(int x,int y,int n,int m){
  int x2=x,y2=y,flag2=1,flag4=1;
  while(flag2 || flag4){
    if(x2<n-1 && flag2){
      x2++;
      for(int i=y;i<=y2;i++){
	if(A[x2][i]==0){
	  x2--;
	  flag2=0;
	  break;
	}
      }
    }
    else{
      flag2=0;
    }
    if(y2<m-1 && flag4){
      y2++;
      for(int i=x;i<=x2;i++){
	if(A[i][y2]==0){
	  y2--;
	  flag4=0;
	  break;
	}
      }
    }
    else{
      flag4=0;
    }
  }
  return make_pair(x2,y2);
}
