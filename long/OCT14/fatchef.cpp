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

const int MOD=1000000009;

vector<pair<int,char> > buckets;

int main(){
  int t,n,m,p;
  char c;
  LL ans;
  scanf("%d",&t);
  while(t--){
    scanf("%d %d",&n,&m);
    buckets.clear();
    ans=1;
    REP(i,0,m){
      scanf(" %c %d",&c,&p);
      buckets.push_back(make_pair(p,c));
    }
    sort(buckets.begin(),buckets.end());
    REP(i,0,buckets.size()-1){
      if(buckets[i].second!=buckets[i+1].second){
        ans=(ans*(buckets[i+1].first-buckets[i].first))%MOD;
      }
    }
    cout<<ans<<endl;
  }
}
