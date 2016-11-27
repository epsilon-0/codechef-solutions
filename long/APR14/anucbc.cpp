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
const LL inf=1000000009; //prime 
const LD eps=1e-9;
const LD pi=3.141592653589793;
const LD e=2.718281828459045;

///// MAIN CODE NOW /////

const int MAX=100010;
int m;
LL fact[MAX],invfact[MAX],inv[MAX];
int card[100010],mcard[501];

void precal(){
  inv[1]=1;
  F(i,2,MAX){
    inv[i]=inf -((inf/i)*inv[inf%i]%inf);
  }
  fact[0]=invfact[0]=1;
  F(i,1,MAX){
    fact[i]=(fact[i-1]*i)%inf;
    invfact[i]=(invfact[i-1]*inv[i])%inf;
  }
}

LL choose(int m,int n){
  if(m==n || n==0){
    return 1ll;
  }
  return (((fact[m]*invfact[n])%inf)*invfact[m-n])%inf;
}

vector<LL> prod(vector<LL> p,vector<LL> q){
  vector<LL> pr;
  pr.resize(m,0);
  F(i,0,p.size()){
    F(j,0,q.size()){
      pr[(i+j)%m]+=p[i]*q[j];
      pr[(i+j)%m]%=inf;
    }
  }
  return pr;
}

int main(){
  precal();
  int t,n,q;
  S(t);
  vector<LL> tmp,ans;
  while(t--){
    S(n);S(q);
    F(i,0,n){
      S(card[i]);
    }
    while(q--){
      MSET(mcard,0);
      ans.clear();
      S(m);
      ans.resize(m,0);
      ans[0]=1;
      F(i,0,n){
	mcard[(m+(card[i]%m))%m]++;
      }
      F(i,0,m){
	tmp.clear();
	tmp.resize(m,0);
	F(j,0,mcard[i]+1){
	  tmp[(j*i)%m]+=choose(mcard[i],j);
	  tmp[(j*i)%m]%=inf;
	}
	ans=prod(tmp,ans);
      }
      PLL(ans[0]);
    }
  }
}
