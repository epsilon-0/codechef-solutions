#include<iostream>
#include<cstring>

using namespace std;

bool isp[100005] = {false};

int main(){
  int t, n, val, cnt;
  cin >> t;
  while(t--){
    memset(isp, false, sizeof(isp));
    cin >> n;
    for(int i = 0; i< n; i++){
      cin >> val;
      isp[val] = true;
    }
    cnt = 0;
    for(int i = 0; i < 100003; i++){
      if(isp[i]){
	cnt++;
      }
    }
    cout << cnt << endl;
  }
}
