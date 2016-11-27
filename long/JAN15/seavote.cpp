#include<iostream>
#include<numeric>

using namespace std;

int v[10005];

bool poss(int n, int cnt);

int main(){
  int t, n, cnt;
  cin >> t;
  while(t--){
    cin >> n;
    cnt = 0;
    for(int i = 0; i < n; i++){
      cin >> v[i];
      if(v[i]) cnt++;
    }
    if(poss(n, cnt)){
      cout << "YES\n";
    }
    else{
      cout << "NO\n";
    }
  }
}

bool poss(int n, int cnt){
  int sum = accumulate(v, v+n, 0);
  if( sum < 100 || sum > 100+cnt-1) return false;
  return true;
}
