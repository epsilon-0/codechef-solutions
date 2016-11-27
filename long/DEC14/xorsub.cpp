#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int a[1005];

int main(){
  int t,k,n,mx;
  cin >> t;
  while(t--){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
      cin >> a[i];
    }
    sort(a,a+n);
    mx = k;
    for(int i = n-1; i >= 0; i--){
      mx = max(mx,mx^a[i]);
    }
    cout << mx << endl;
  }
}
