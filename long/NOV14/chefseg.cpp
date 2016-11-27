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

LL x, k, level, num;
double div_l, ans;
int t;

int main(){
  cin >> t;
  while(t--){
    cin >> x >> k;
    x *= 1e7;
    level = ceil(log2(k + 1));
    num = k - pow(2, level - 1) + 1;
    div_l = ((double) x)/pow(2,level-1);
    ans = div_l*num - ((double)x)/pow(2,level);
    printf("%.9f", ans/1e7);
  }
}
