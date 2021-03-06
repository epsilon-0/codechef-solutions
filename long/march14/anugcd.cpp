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

vector<int> factors[100001];
bool comp[100001]={false};

void precal(){
  F(i,0,100001)factors[i].clear();
  comp[2]=false;
  F(i,2,317){
    if(!comp[i]){
      FK(j,i*i,100001,i){
	comp[j]=true;
	if(factors[j].size()==0){
	  factors[j].PB(i);
	}
      }
    }
  }
  int k;
  F(i,2,100001){
    if(factors[i].size()==0){
      factors[i].PB(i);
    }
    else{
      k=i/factors[i][0];
      F(j,0,factors[k].size()){
	if(j==0 && factors[k][0]>factors[i][0]){
	  factors[i].PB(factors[k][0]);
	}
	if(j>0){
	  factors[i].PB(factors[k][j]);
	}
      }
    }
  }
}

vector<pair<int,int> > indices[100001]={};

pair<int,int> qindex(int left,int right,int ind){
  int top,bot;
  top=upper_bound(indices[ind].begin(),indices[ind].end(),MP(right,inf))-indices[ind].begin()-1;
  bot=lower_bound(indices[ind].begin(),indices[ind].end(),MP(left,0))-indices[ind].begin();
  return MP(bot,top);
}



int main(){
  precal();
  int n,m,t;
  S(n);S(m);
  F(i,1,n+1){
    S(t);
    F(j,0,factors[t].size()){
      indices[factors[t][j]].PB(MP(i,t));
    }
  }
}
