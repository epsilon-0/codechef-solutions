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

int t,r,g,b,m;
LL MAXr,MAXb,MAXg,temp,ans;

LL solve(LL x,LL y,LL z,int moves){
  LL m[3]={x,y,z};
  sort(m,m+3);
  if(moves==0){
    return m[2];
  }
  LL tp=solve(m[0],m[1],m[2]/2,moves-1);
  return min(tp,m[2]);
}

int main(){
  scanf("%d",&t);
  while(t--){
    MAXr=MAXg=MAXb=-1;
    cin>>r>>g>>b>>m;
    REP(i,0,r){
      cin>>temp;
      MAXr=max(temp,MAXr);
    }
    REP(i,0,g){
      cin>>temp;
      MAXg=max(temp,MAXg);
    }
    REP(i,0,b){
      cin>>temp;
      MAXb=max(temp,MAXb);
    }
    ans=solve(MAXr,MAXb,MAXg,m);
    cout<<ans<<endl;
  }
}
