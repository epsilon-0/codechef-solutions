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

int a[1000007];

int ispalin(int n){
  f(i,1,n+1){
    if(a[i]!=a[n-i+1]){
      return 0;
    }
  }
  return 1;
}

void addone(int j){
  if(j==0){
    a[j]++;
  }
  if(a[j]==9){
    a[j]=0;
    addone(j-1);
  }
  else{
    a[j]++;
  }
}

void next_palin(int n){
  int flag=0;
  fr(i,n/2,0){
    if(a[i]<a[n-i]){
      flag=1;
      break;
    }
  }
  if(flag){
    addone(n/2);
  }  
  f(i,(n+1)/2,n){
    a[i]=a[n-i];
  }
}

int main(){
  int t;
  string s;
  scanf("%d",&t);
  while(t--){
    cin>>s;
    f(i,0,s.length()){
      a[i+1]=s[i]-'0';
    }
    if(ispalin(s.length())){
      addone(s.length());
    }

    next_palin(s.length()+1);

    if(a[0]){
      printf("%d",a[0]);
    }
    f(i,1,s.length()+1){
      printf("%d",a[i]);
    }
    printf("\n");
  }
}
