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
#define S(n) scanf("%d",&n)
#define SLL(n) scanf("%lld",&n)
#define P(n) printf("%d\n",n)
#define PLL(n) printf("%lld\n",n)
#define SF(n) scanf("%lf\n",&n)
#define PF(n) printf("%lf\n",n)

// useful functions
#define REV(s,e) reverse(s,e)
#define MSET(s,i) memset(s,i,sizeof(s))
#define CPY(i,j) memset(i,j,sizeof(j))
#define MP(x,y) make_pair(x,y)
#define F(i,a,b) for(int i=a;i<b;i++)
#define FK(i,a,b,k) for(int i=a;i<b;i+=k)
#define FR(i,a,b) for(int i=a;i>b;i--)
#define FRK(i,a,b,k) for(int i=a;i>b;i-=k)
#define PB(x) push_back(x)

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

vector<vector<int> > G;

bool cycles(vector<vector<int> > G);
bool visited[10010];

int main(){
  MSET(visited,false);
  int n,m,x,y;
  cin>>n>>m;
  G.clear();
  G.resize(n);
  F(i,0,m){
    cin>>x>>y;
    x--;y--;
    G[x].PB(y);
    G[y].PB(x);
  }
  cout<<cycles(G)<<endl;
}

bool dfs(vector<vector<int> >G,int v,int parent){
  visited[v]=true;
  bool iscycle=false;
  F(i,0,G[v].size()){
    if(visited[G[v][i]] && G[v][i]!=parent){
      iscycle=true;
      break;
    }
    if(!visited[G[v][i]]){
      iscycle=dfs(G,G[v][i],v);
    }
  }
  return iscycle;
}

bool cycles(vector<vector<int> > G){
  F(i,0,G.size()){
    if(!visited[i] && dfs(G,i,i)){
      return true;
    }
  }
  return false;
}
