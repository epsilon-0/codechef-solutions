#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

#define s(n) scanf("%d",&n)

using namespace std;

int B[1001][1001],C[1001][1001],A[1001],incr[1001];

int main(){
  int t,n,m,k,cur;
  s(t);
  while(t--){
    s(n);s(m);s(k);
    for(int i=0;i<n;i++){
      s(A[i]);
      A[i]--;
    }
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
	s(B[i][j]);
      }
    }
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
	s(C[i][j]);
      }
    }

    cur=0;
    for(int i=0;i<n;i++){
      incr[i]=-1;
      cur+=B[i][A[i]];
      for(int j=0;j<m;j++){
	if(j!=A[i]){
	  incr[i]=max(incr[i],B[i][j]-C[i][j]);
	}
      }
      incr[i]=max(0,incr[i]-B[i][A[i]]);
    }

    sort(incr,incr+n);

    for(int i=n-1;i>=n-k;i--){
      cur+=incr[i];
    }
    printf("%d\n",cur);
  }
}
