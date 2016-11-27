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

#define inf 1000000007
#define eps 1e-19
#define rev(s,e) reverse(s,e)
#define mset(s,i) memset(s,i,sizeof(s))
#define cpy(i,j) memset(i,j,sizeof(j))
#define mp(x,y) make_pair(x,y)
#define ff first
#define ss second
#define ld long double
#define li long int
#define lli long long int
#define pb(x) push_back(x)
#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,a,b) for(int i=a;i>b;i--)
#define S(n) scanf("%d",&n)

int prefer[1002][501], wPartner[501];
bool mFree[501];
vector<int> mfree;


bool wPrefersM1OverM(int w, int m, int m1,int N){
  for (int i = 0; i < N; i++){
    if (prefer[w][i] == m1){
      return true;
    }
    if (prefer[w][i] == m){
      return false;
    }
  }
}

void stableMarriage(int N){
  mset(wPartner, -1);
  mset(mFree, false);
  int m,m1,w;

  while (mfree.size()){
    m=mfree[mfree.size()-1];
    mfree.pop_back();

    for (int i = 0; i < N && mFree[m] == false; i++){
      w = prefer[m][i];
      if (wPartner[w-N] == -1){
	wPartner[w-N] = m;
	mFree[m] = true;
      }
      else{
	m1 = wPartner[w-N];
	if (wPrefersM1OverM(w, m, m1,N) == false){
	  wPartner[w-N] = m;
	  mFree[m] = true;
	  mFree[m1] = false;
	  mfree.pb(m1);
	}
      }
    }
  }
    for (int i = 0; i < N; i++)
       cout<< i+1 << " " << wPartner[i]+1 << endl;
}

int main(){
  int t,n,temp;
  S(t);
  while(t--){
    S(n);
    f(i,0,n){
      mfree.pb(i);
      S(temp);
      f(j,0,n){
	S(prefer[i][j]);
	prefer[i][j]+=n-1;
      }
    }
    f(i,n,2*n){
      S(temp);
      f(j,0,n){
	S(prefer[i][j]);
	prefer[i][j]-=1;
      }
    }
    stableMarriage(n);
  }
}
