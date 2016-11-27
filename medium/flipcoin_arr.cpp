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

const int MAX=300010;

int heads[MAX],flag[MAX];

void update(int n,int bot,int top,int x,int y){
  if(x>top || y<bot){
    return;
  }
  if(x>=bot && y<=top){
    heads[n]=top-bot+1-heads[n];
    flag[n]=1-flag[n];
    return;
  }
  int mid=(bot+top)>>1;
  update(2*n,bot,mid,x,y);
  update(2*n+1,mid+1,top,x,y);
  heads[n]=heads[2*n]+heads[2*n+1];
  if(flag[n]){
    heads[n]=top-bot+1-heads[n];
  }
  return;
}

int query(int n,int bot,int top,int x,int y,int f){
  if(x>top || y<bot){
    return 0;
  }
  if(x>=bot && y<=top){
    if(f){
      return top-bot+1-heads[n];
    }
    return heads[n];
  }
  int mid=(bot+top)>>1,nf=(f+flag[n])%2;
  return query(2*n,bot,mid,x,y,nf)+query(2*n+1,mid+1,top,x,y,nf);
}

int main(){
  int t,n,q,a,b;
  s(n);
  s(t);
  while(t--){
    s(q);s(a);s(b);
    a++;b++;
    if(q){
      p(query(1,1,n,a,b,0));
    }
    else{
      update(1,1,n,a,b);
    }
  }
}
