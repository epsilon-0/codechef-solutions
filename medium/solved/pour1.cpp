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

int gcd(int a,int b){
  int temp;
  while(a){
    temp=b%a;
    b=a;
    a=temp;
  }
  return b;
}

int main(){
  int t,a,b,c;
  cin>>t;
  while(t--){
    cin>>a>>b>>c;
    // we will keep a>=b
    if(a<b){
      swap(a,b);
    }
    if(c>a){
      cout<<-1<<endl;
      continue;
    }
    // now we can only achieve c if it is divisible by the gcd
    if(c%gcd(a,b)!=0){
      cout<<-1<<endl;
    }
    else{
      int ans=0,w=0,x=0,y=0,z=0;
      // continue till we have not filled c
      while(w!=c && x!=c && y!=c && z!=c){
	if(w==0){
	  w=a;
	}
	else if(x==b){
	  x=0;
	}
	else{
	  if(w<=b-x){
	    //we empty this tank
	    x+=w;
	    w=0;
	  }
	  else{
	    w-=(b-x);
	    x=b;
	  }
	}
	if(y==0){
	  y=b;
	}
	else if(z==a){
	  z=0;
	}
	else{
	  if(y<=a-z){
	    z+=y;
	    y=0;
	  }
	  else{
	    y-=(a-z);
	    z=a;
	  }
	}
	ans++;
      }
      cout<<ans<<endl;
    }
  }
}
