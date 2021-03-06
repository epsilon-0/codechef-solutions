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
#include<cassert>

using namespace std;

// useful functions
#define REV(s,e) reverse(s,e)
#define MSET(s,i) memset(s,i,sizeof(s))
#define MCPY(i,j) memcpy(i,j,sizeof(j))
#define MP(x,y) make_pair(x,y)
#define REP(i,a,b) for(int i=a;i<b;i++)

// shortforms
#define FF first
#define SS second
#define LD long double
#define LL long long int
#define UG unsigned

// constants
const int inf=1000000007; //prime
const LD eps=1e-9;

///// MAIN CODE NOW /////

int heights[101];

int main(){
  int t,n,m,mx,cnt;
  scanf("%d",&t);
  while(t--){
    scanf("%d %d",&n,&m);
    REP(i,0,n) scanf("%d", heights+i);
    mx=*max_element(heights,heights+n);
    cnt=0;
    m-=(mx*n-accumulate(heights,heights+n,0));
    if(m<0 || m%n){
      puts("No");
    }
    if(m>-1 && m%n==0){
      puts("Yes");
    }
  }
}
















