#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*#include<cstdio>
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
const int inf=1000000007;
const ld eps=1e-9;
const ld pi=3.141592653589793;
const ld e=2.718281828459045;
*/

typedef long long int ll;

int main(){
  int t;
  ll u,v,w,U,V,W,a,b,c,d,e,f,g,h;
  double x,y,z;
  scanf("%d",&t);
  while(t>0){
    t=t-1;
    scanf("%lld%lld%lld%lld%lld%lld",&u,&v,&w,&W,&V,&U);
    u*=u;v*=v;w*=w;U*=U;V*=V;W*=W; 
    a=u+v-W; 
    e=a*a;
    b=v+w-U;
    f=b*b;
    c=w+u-V;
    g=c*c;
    d=U+V-W;
    h=d*d;
    x=4*u*v*w-u*f-v*g-w*e+a*b*c;
    x=sqrt(x);
    y=sqrt(4*u*v-e);
    y+=sqrt(4*v*w-f);
    y+=sqrt(4*w*u-g);
    y+=sqrt(4*U*V-h);
    z=x/y;
    printf("%.4lf\n",z);
  }
}
