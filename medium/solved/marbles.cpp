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

using namespace std;

#define inf 1000000007
#define rev(s,e) reverse(s,e)
#define set(s,i) memset(s,i,sizeof(i))
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

int main(){
  int t;
  lli n,k,ans;
  cin>>t;
  while(t--){
    ans=1;
    cin>>n>>k;
    n--;k--;
    if(k>n/2){
      k=n-k;
    }
    f(i,1,k+1){
      ans=ans*(n+1-i)/i;
    }
    cout<<ans<<endl;
  }
}
