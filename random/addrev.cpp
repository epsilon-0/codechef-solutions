#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

long long rev(long long n){
  long long ans = 0;
  while(n>0){
    ans = ans*10 + n%10;
    n /= 10;
  }
  return ans;
} 

int main(){
  int n;
  long long a, b;
  cin >> n;
  while(n--){
    cin >> a >> b;
    cout << rev(rev(a) + rev(b)) << endl;
  }
}
