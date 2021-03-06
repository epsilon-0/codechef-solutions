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
/*
LL lattice[1562510]={0},divisor[1562510]={0};
bool iscomp[1562510]={false};
vector<int> primes;

void precal(){
  iscomp[0]=true;
  iscomp[1]=true;
  F(i,2,1255){
    if(!iscomp[i]){
      FK(j,i*i,1562510,i){
	iscomp[j]=true;
      }
    }
  }
  primes.clear();
  F(i,0,1562510){
    if(!iscomp[i]){
      primes.PB(i);
    }
  }
  divisor[1]=1;
  int cnt=0,div,temp;
  F(i,2,1562510){
    temp=i;
    cnt=0;
    if(!iscomp[i]){
      divisor[i]=2;
      continue;
    }
    F(j,0,primes.size()){
      if(i%primes[j]==0){
	div=primes[j];
	break;
      }
    }
    while(temp%div==0){
      cnt++;
      temp/=div;
    }
    divisor[i]=divisor[temp]*(cnt+1);
  }
  F(i,1,1562510){
    lattice[i]=underhyper(i)-divisor[i];
  }
}

LL answer(LL n){
  LL temp=0,prod;
  F(i,1,n){
    prod=(n-i)*i;
    temp+=lattice[prod];
  }
  return temp;
}
*/

LL underhyper(int n){
  if(n==1){
    return 1;
  }
  LL ans=0;
  int sqrt=pow(n,0.5);
  F(i,1,sqrt+1){
    ans+=2*(n/i);
  }
  ans-=(sqrt*sqrt);
  return ans;
}

int main(){
  int t;
  LL n;
  S(t);
  while(t--){
    SLL(n);
    LL ans=0;
    F(i,1,n){
      ans+=underhyper(i*(n-i)-1);
    }
    PLL(ans);
  }
}
