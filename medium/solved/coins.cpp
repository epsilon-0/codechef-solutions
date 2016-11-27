#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<numeric>
#include<stack>
#include<set>
#include<map>

using namespace std;

#define inf 1000000007
#define mp make_pair
#define pb push_back
#define poly vector<long long int>
#define f(i,j) for(int i=0;i<j;i++)
#define fe(i,j) for(int i=0;i<=j;i++)
#define fr(i,j) for(int i=j;i>0;i--)
#define fre(i,j) for(int i=j;i>=0;i--)

map<long long int,long long int> a;

long long int ans(long long int n){
  if(n==0){
    a[n]=0;
  }
  else{
    if(a[n]==0){
      a[n]=max(ans(n/2)+ans(n/3)+ans(n/4),n);
    }
  }
  return a[n];
}

int main(){
  long long int t;
  while(cin>>t){
    cout<<ans(t)<<endl;
  }
}
