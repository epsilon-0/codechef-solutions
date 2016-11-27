#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<numeric>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<list>
#include<climits>
#include<cstdlib>
#include<string>
#include<cmath>

using namespace std;

// useful input/output macros
#define s(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define p(n) printf("%d\n",n)
#define pll(n) printf("%lld\n",n)
#define sf(n) scanf("%lf\n",&n)
#define pf(n) printf("%lf\n",n)

// useful functions
#define rev(s,e) reverse(s,e)
#define mset(s,i) memset(s,i,sizeof(s))
#define cpy(i,j) memset(i,j,sizeof(j))
#define mp(x,y) make_pair(x,y)
#define f(i,a,b) for(int i=a;i<b;i++)
#define fk(i,a,b,k) for(int i=a;i<b;i+=k)
#define fr(i,a,b) for(int i=a;i>b;i--)
#define frk(i,a,b,k) for(int i=a;i>b;i-=k)
#define pb(x) push_back(x)

// shortforms
#define ff first
#define ss second
#define ld long double
#define li long int
#define lli long long int
#define ug unsigned

// constants
const int inf=1000000007; //prime 
const ld eps=1e-9;
const ld pi=3.141592653589793;
const ld e=2.718281828459045;


#define MAX 100001

int segtr[262150]; //2*2^([log_2(100001)]+1) = 262144

int arr[MAX];

int query(int n,int x, int y, int i,int j){
  int mid=(x+y)/2;
  if(x==i && y==j){
    return segtr[n];
  }
  else if(j<=mid){
    return query(2*n,x,mid,i,j);
  }
  else if(i>mid){
    return query(2*n+1,mid+1,y,i,j);
  }
  else{
    return min(query(2*n,x,mid,i,mid),query(2*n+1,mid+1,y,mid+1,j));
  }
}

void make_tree(int n,int x,int y){
  int mid=(x+y)/2;
  if(x==y){
    segtr[n]=arr[x];
  }
  else{
    make_tree(2*n,x,mid);
    make_tree(2*n+1,mid+1,y);
    segtr[n]=min(segtr[2*n],segtr[2*n+1]);
  }
}

int main(){
  int t,n,q,a,b;
  s(t);
  f(i,1,t+1){
    printf("Scenario #%d:\n",i);
    scanf("%d %d",&n,&q);
    f(i,0,n){
      s(arr[i]);
    }
    make_tree(1,0,n-1);
    f(i,0,q){
      s(a);s(b);
      p(query(1,0,n-1,a-1,b-1));
    }
  }
}
