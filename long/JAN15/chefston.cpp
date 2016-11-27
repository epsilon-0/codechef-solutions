#include<iostream>

using namespace std;

long long a[100005];

int main(){
  int t, n;
  long long k, b, mp;
  cin >> t;
  while(t--){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
      cin >> a[i];
    }
    mp = 0;
    for(int i = 0; i < n; i++){
      cin >> b;
      mp = max(mp, b * ((long long)k/a[i]));
    }
    cout << mp << endl;
  }
}
