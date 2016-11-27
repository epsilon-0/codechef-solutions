#include <bits/stdc++.h>

using namespace std;

long long fact0(long long int n){
  long long ans = 0;
  while(n > 0){
    ans += n/5;
    n /= 5;
  }
  return ans;
}

int main(){
  int t;
  long long n;
  cin >> t;
  while(t--){
    cin >> n;
    cout << fact0(n) << endl;
  }
}
