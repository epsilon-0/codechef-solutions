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

int main(){
  LL a;
  cin>>a;
  int b=a%6;
  if(b==0 || b==1 || b==3){
    printf("yes\n");
  }
  else{
    printf("no\n");
  }
}
