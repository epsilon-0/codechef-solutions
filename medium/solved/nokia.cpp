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

int mn[31]={0, 2, 5, 8, 12, 16, 20, 24, 29, 34, 39, 44, 49, 54, 59, 64, 70, 76, 82, 88, 94, 100, 106, 112, 118, 124, 130, 136, 142, 148, 154};
int mx[31]={0, 2, 5, 9, 14, 20, 27, 35, 44, 54, 65, 77, 90, 104, 119, 135, 152, 170, 189, 209, 230, 252, 275, 299, 324, 350, 377, 405, 434, 464, 495};
/*
int cal_mn(int i){
  if(i==0){
    mn[0]=0;
  }
  if(mn[i]==-1){
    mn[i]=(i+1)+cal_mn(i/2)+cal_mn(i-1-(i/2));
  }
  return mn[i];
}

int cal_mx(int i){
  if(i==0){
    mx[0]=0;
  }
  if(mx[i]==-1){
    mx[i]=(i+1)+cal_mx(i-1);
  }
  return mx[i];
}
*/
int main(){
  int t,n,m;
  cin>>t;
  while(t--){
    cin>>n>>m;
    if(m<mn[n]){
      cout<<-1<<endl;
    }
    else if(m>=mn[n] && m<=mx[n]){
      cout<<0<<endl;
    }
    else{
      cout<<m-mx[n]<<endl;
    }
  }
}
