#include<iostream>

using namespace std;

int soln(int n, int m, int l, int r);

int main(){
  int t,n,m,l,r;
  cin >> t;
  while(t--){
    cin >> n >> m >> l >> r;
    cout << soln(n,m,l,r) << endl;
  }
}

int soln(int n, int m, int l, int r){
  return 1;
}
