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

bool iprm[31629];

bool clst[100007];

// all primes stored here
vector<int> prm;

//calculates all primes between 2,31627
void precal(){
  iprm[1]=true;
  f(i,2,180){
    if(!iprm[i]){
      for(int j=i*i;j<31629;j+=i){
	iprm[j]=true;
      }
    }
  }
  f(i,2,31629){
    if(!iprm[i]){
      prm.pb(i);
    }
  }
}

int main(){
  precal();
  //  f(i,0,prm.size())cout<<prm[i]<<endl;
  int t,m,n,l,i,s;
  scanf("%d",&t);
  while(t--){
    mset(clst,0);
    scanf("%d %d",&m,&n);
    if(n==1){
      printf("\n");
      continue;
    }
    i=0;
    //limit to check for prime factors
    l=sqrt(n);
    while(prm[i]<=l && i<prm.size()){
      // the smallest multiple of prm[i] greater equal m
      s=prm[i] * ((m+prm[i]-1)/prm[i]);
      for(int j=s;j<=n;j+=prm[i]){
	if(j!=prm[i]){
	  clst[j-m]=1;
	}
      }
      i++;
    }
    f(i,0,n-m+1){
      if(!clst[i] && (i+m)!=1){
	printf("%d\n",i+m);
      }
    }
    printf("\n");
    }
}
