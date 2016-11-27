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

using namespace std;

#define inf 1000000007
#define rev(s,e) reverse(s,e)
#define set(s,i) memset(s,i,sizeof(s))
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

int dp[101][101];
int arr[101];
int sums[101][101];

int ans(int a,int b){
  if(a==b){
    dp[a][b]=0;
  }
  if(dp[a][b]==-1){
    int tmp;
    dp[a][b]=inf;
    f(i,a,b){
      tmp=ans(a,i)+ans(i+1,b)+(sums[a][i]*sums[i+1][b]);
      if(tmp<dp[a][b]){
	dp[a][b]=tmp;
	sums[a][b]=(sums[a][i]+sums[i+1][b])%100;
      }
    }
  }
  return dp[a][b];
}

int main(){
  int n,sum;
  while(cin>>n){
    set(dp,-1);
    f(i,0,n){
      cin>>arr[i];
      sums[i][i]=arr[i];
    }
    cout<<ans(0,n-1)<<endl;
  }
}
