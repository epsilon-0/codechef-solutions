#include <bits/stdc++.h>

using namespace std;

int cycS[10] = {1, 1, 4, 4, 2, 1, 1, 4, 4, 2};

int mpow(int a,int b){
  return (b==0)?1:(a*mpow(a, b-1))%10;
}

int main(){
  int t, a;
  long long b;
  cin >> t;
  while(t--){
    cin >> a >> b;
    if(a == 0){ cout << "0\n"; continue; }
    else if(b == 0){ cout << "1\n"; continue; }
    cout << mpow(a%10, b%cycS[a%10] + cycS[a%10]) << endl;
  }
}
