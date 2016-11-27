#include <iostream>

using namespace std;

int main(){
  long long n, t;
  cin >> n;
  while(n--){
    cin >> t;
    int count = 0;
    int start = 5;
    while(t >= start){
      count += t/start;
      start *= 5;
    }
    cout << count << endl;
  }
}
