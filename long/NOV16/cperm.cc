#include <bits/stdc++.h>

using namespace std;

long long mod_pow(long long x,long long y,long long k){
  if(y==0){
    return 1%k;
  }
  long long tmp=x,ans=1ll;
  for(;y;y>>=1){
    if(y&1){
      ans=(ans*tmp)%k;
    }
    tmp=(tmp*tmp)%k;
  }
  return ans;
}

const long long MOD = 7 + (1e9);

int main(){
  int t;
  cin >> t;
  while(t--){
    long long n;
    cin >> n;
    if(n <= 2){
      cout << 0 << endl;
      continue;
    }
    long long ans = (mod_pow(2, n-1, MOD) + MOD - 2) % MOD;
    cout << ans << endl;
  }
  
}