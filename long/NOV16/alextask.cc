#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b){
  if(a == 0)
    return b;
  return gcd(b % a, a);
}

long long lcm(long long a, long long b){
  return a / gcd(a, b) * b;
}

long long nums[501];

int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
      cin >> nums[i];
    long long minLCM = LLONG_MAX;
    for(int i = 0; i < n; i++)
      for(int j = i+1; j < n; j++)
        minLCM = min(minLCM, lcm(nums[i], nums[j]));

    cout << minLCM << endl;
  }
}