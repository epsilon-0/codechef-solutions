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
#define sf(n) scanf("%lf",&n)
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
#define lli long long int
#define ug unsigned

// constants
const lli inf=1000000007; //prime 
const ld eps=1e-9;
const ld pi=3.141592653589793;
const ld e=2.718281828459045;
////////////////////////////////


lli fact[205],inv[205],infact[205],f[205][205][205],g[205][205][205],pr[205],dst[205],num[205],prm[205][205];

void calfact();
lli perm(int i,int j);
void calprm();

int main(){
  calfact();
  calprm();
  int t,n,K;
  s(t);
  while(t--){
    mset(pr,0);mset(dst,0);mset(num,0);
    s(n);s(K);
    f(i,0,n){
      sll(pr[i]);
    }
    sort(pr,pr+n);
    int distinct=1;
    dst[0]=0;
    dst[1]=1;
    f(i,1,n){
      if(pr[i]==pr[i-1]){
	dst[distinct]++;
      }
      else{
	distinct++;
	dst[distinct]=1;
      }
    }
    n=distinct;
    num[1]=dst[1];
    f(i,2,n+1){
      num[i]=dst[i]+num[i-1];
    }

    f(i,1,n+1){
      f(j,1,num[n]+1){
	f(k,1,K+1){
	  
	  if(j==1 && k==1){
	    f[i][j][k]=dst[i];
	  }
	  else if(k>1 && j==1){
	    f[i][j][k]=0;
	  }
	  else if(i==1 && j>1 && k==1){
	    f[i][j][k]=prm[num[i]][j];
	  }
	  else if(i>1 && j>1 && k==1){
	    f[i][j][k]=(dst[i]*prm[num[i]-1][j-1])%inf;
	  }
	  else if(i==1 && j>1 && k>1){
	    f[i][j][k]=0;
	  }
	  else{
	    f[i][j][k]=((f[i][j-1][k]*(num[i]-j+1))%inf + (g[i-1][j-1][k-1]*dst[i])%inf)%inf;
	  }

	  if(i==1){
	    g[i][j][k]=f[i][j][k];
	  }
	  else{
	    g[i][j][k]=g[i-1][j][k]+f[i][j][k];
	  }
	}
      }
    }
    lli ans=0;
    f(i,1,K+1){
      ans+=f[n][num[n]][i]; ans%=inf;
    }
    pll(ans);
  }
}


lli perm(int i,int j){
  if(j>i){
    return 0;
  }
  lli temp;
  temp=fact[i];
  temp=(temp*infact[i-j])%inf;
  return temp;
}

void calprm(){
  f(i,0,203){
    f(j,0,203){
      prm[i][j]=perm(i,j);
    }
  }
}

void calfact(){
  inv[1]=1ll;
  f(i,2,200){
    inv[i]=inf -((inf/i)*inv[inf%i]%inf);
  }
  fact[0]=infact[0]=1ll;
  f(i,1,201){
    fact[i]=(fact[i-1]*i)%inf;
    infact[i]=(infact[i-1]*inv[i])%inf;
  }
}
