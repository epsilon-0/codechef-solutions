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
const int inf=1000000007;

const int mx=5000005;
bool nprm[mx];
int ans[mx];


void calc(){
  ans[1]=1;
  lli c=1;
  int l=1;
  f(i,2,mx){
    if(!nprm[i]){
      c++;
      if(i<2500){
	for(int j=i*i;j<mx;j+=i){
	  nprm[j]=true;
	}
      }
    }
    l=ans[i]=(l*c)%inf;
  }
}

int main(){
  calc();
  int t,n;
  scanf("%d",&t);
  while(t--){
    scanf("%d",&n);
    printf("%d\n",ans[n]);
  }
}
