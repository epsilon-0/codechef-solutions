#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

// useful input/output macros
#define S(n) scanf("%d",&n)
#define SLL(n) scanf("%lld",&n)
#define P(n) printf("%d\n",n)
#define PLL(n) printf("%lld\n",n)
#define SF(n) scanf("%lf\n",&n)
#define PF(n) printf("%lf\n",n)

// useful functions
#define MSET(s,i) memset(s,i,sizeof(s))
#define F(i,a,b) for(int i=a;i<b;i++)
#define MP(i,j) make_pair(i,j)
#define PB(i) push_back(i)

// shortforms
#define FF first
#define SS second
#define LD long double
#define LI long int
#define LL long long int
#define UG unsigned

// constants
const int inf=1000000007; //prime 
const LD eps=1e-9;
const LD pi=3.141592653589793;
const LD e=2.718281828459045;

///// MAIN CODE NOW /////

bool graph[21][21];
vector<int> offers[21];
bool isindependent[(1<<20)+10];

bool intersect(int i,int j){
  int c1=0;
  int c2=0;
  while(c1<offers[i].size() && c2<offers[j].size()){
    if(offers[i][c1]==offers[j][c2]){
      return true;
    }
    else if(offers[i][c1]<offers[j][c2]){
      c1++;
    }
    else{
      c2++;
    }
  }
  return false;
}

pair<int,int> nums(int n){
  int i,j;
  i=log2(n);
  n-=1<<i;
  j=log2(n);
  return MP(i,j);
}

int intsize(int n){
  int s=0;
  while(n){
    if(n&1){
      s++;
    }
    n>>=1;
  }
  return s;
}

int independent_set(int n){
  int mx_size=0,k;
  MSET(isindependent,false);
  pair<int,int> t;
  F(i,1,(1<<n)){
    if(1<<((int)log2(i))==i){
      isindependent[i]=true;
    }
    else{
      t=nums(i);
      if(isindependent[i-(1<<t.FF)] && isindependent[i-(1<<t.SS)] && !graph[t.FF][t.SS]){
	isindependent[i]=true;
      }
    }
    k=intsize(i);
    if(mx_size<k && isindependent[i]){
      mx_size=k;
    }
  }
  return mx_size;
}

int main(){
  int n,m,k,temp;
  MSET(graph,false);
  S(n);S(m);
  F(i,0,21){
    offers[i].clear();
  }
  F(i,0,m){
    S(k);
    F(j,0,k){
      S(temp);
      offers[i].PB(temp);
    }
  }
  F(i,0,m){
    F(j,0,m){
      if(intersect(i,j)){
	graph[i][j]=true;
	graph[j][i]=true;
      }
    }
  }
  P(independent_set(m));
}
