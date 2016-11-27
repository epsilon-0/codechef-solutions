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

#define eps 1e-19
#define rev(s,e) reverse(s,e)
#define mset(s,i) memset(s,i,sizeof(s))
#define cpy(i,j) memset(i,j,sizeof(j))
#define mp(x,y) make_pair(x,y)
#define ff first
#define ss second
#define ld long double
#define li long int
#define lli long long int
#define pb(x) push_back(x)
#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,a,b) for(int i=a;i>b;i--)
#define s(n) scanf("%d",&n)
#define p(n) printf("%d",n)

const int inf=1000000007;
const int MAX=5005;

const string imp="Impossible";

int pa[MAX],rk[MAX],tcnt[MAX];

// initializer
void init(int n){
  int i;
  f(i,0,n){
    pa[i]=i;tcnt[i]=1;rk[i]=0;
  }
}

int find(int x){
  int a=x;
  while(pa[a]!=a){
    a=pa[a]; // keep on travelling up the treee
  }
  int b=x,c;
  // path compression on query
  while(pa[b]!=a){
    c=pa[b];
    pa[b]=a;
    b=c;
  }
  return a;
}

void funion(int x,int y){
  int ax=find(x);
  int ay=find(y);
  if(ax!=ay){
    if(rk[ax]>rk[ay]){
      swap(ax,ay);
    }
    if(rk[ax]==rk[ay]){
      rk[ax]++;
    }
    pa[ay]=ax;
    tcnt[ax]+=tcnt[ay];
  }
}

struct edge{
  int u,v;
  lli w;
};

bool lst(edge x,edge y){
  return x.w<y.w;
}

edge chef[20001],comp[20001];

int main(){
  int t,n,m1,m2,u,v,sz;
  lli w,cc,cost;
  s(t);
  while(t--){
    cost=0;cc=0;sz=0;
    s(n);s(m1);s(m2);
    mset(pa,0);mset(rk,0);mset(tcnt,0);
    init(n);
    f(i,0,m1){
      s(comp[i].u);s(comp[i].v);scanf("%lld",&comp[i].w);
    }
    sort(comp,comp+m1,lst);
    f(i,0,m2){
      s(chef[i].u);s(chef[i].v);scanf("%lld",&chef[i].w);
    }
    sort(chef,chef+m2,lst);
    reverse(chef,chef+m2);
    f(i,0,m2){
      u=chef[i].u;
      v=chef[i].v;
      w=chef[i].w;
      if(find(u)!=find(v)){
	cost+=w;
	funion(u,v);
	sz++;
      }
    }
    cc=cost;
    f(i,0,m1){
      u=comp[i].u;
      v=comp[i].v;
      w=comp[i].w;
      if(find(u)!=find(v)){
	cost+=w;
	funion(u,v);
	sz++;
      }
    }
    if(sz==(n-1)){
      printf("%lld %lld\n",cc,cost);
    }
    else{
      printf("Impossible\n");
    }
  }
}
