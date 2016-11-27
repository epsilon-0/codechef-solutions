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
#define eps 1e-19
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


int arrK[11]={0};

int main(){
  int t;
  cin>>t;
  int n,k,tmp;
  while(t--){
    set(arrK,0);
    cin>>n>>k;
    f(i,0,n){
      cin>>tmp;
      tmp%=(k+1);
      arrK[tmp]++;
    }
    int ans=0;
    f(i,0,11){
      if(arrK[i]){
	ans++;
      }
    }
    if(ans==1){
      cout<<"YES"<<endl;
    }
    else if(ans>2){
      cout<<"NO"<<endl;
    }
    else{
      f(i,0,11){
	if(arrK[i]){
	  if(arrK[i] == 1 || arrK[i] == (n-1)){
	    cout<<"YES"<<endl;
	  }
	  else{
	    cout<<"NO"<<endl;
	  }
	  break;
	}
      }
    }
  }
}
