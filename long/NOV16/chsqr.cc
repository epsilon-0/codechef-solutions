#include <bits/stdc++.h>

using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int k;
    cin >> k;
    for(int i = 0; i < k; i++){
      for(int j = 1; j <= k; j++){
        cout << (j + i + k + (k + 1) / 2) % k + 1 << " ";
      }
      cout << endl;
    }
  }
}