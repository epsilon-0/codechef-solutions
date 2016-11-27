#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cmath>

#define mset(s) memset(s,sizeof(s),0)

using namespace std;

const int mod=1000000007;

int pr[201],ans[201][201][201],cnt[201];

int main(){
  mset(pr);mset(ans);mset(cnt);
  int t,n,k;
  long long int temp;
  cin>>t;
  while(t--){
    cin>>n>>k;
    for(int i=0;i<n;i++){
      cin>>pr[i];
      cnt[pr[i]]++;
    }
  }
  sort(pr,pr+n);
  for(int i=0;i<n;i++){
    for(int j=0;j<k;j++){
      for(int l=0;l<k;l++){
	temp=0;
	temp+=ans[i][;
	ans[i][j][k]=temp%mod;
      }
    }
  }
}
