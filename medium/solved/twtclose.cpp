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
#define toint(s) atoi(s.c_str())

int a[1001];

int main(){
  int n,k,twt;
  int t=0;
  string s;
  cin>>n>>k;
  while(k--){
    cin>>s;
    if(s=="CLOSEALL"){
      set(a,0);
      t=0;
    }
    else{
      cin>>twt;
      twt--;
      a[twt]=1-a[twt];
      if(a[twt]){
	t++;
      }
      else{
	t--;
      }
    }
    cout<<t<<endl;
  }
}
