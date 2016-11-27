#include<iostream>
#include<algorithm>

using namespace std;

typedef pair<int,int> intv;

intv inv[100005];

bool comp(intv a, intv b){
  if(a.second == b.second){
    return a.first < b.first;
  }
  return a.second < b.second;
}

int main()
{
  ios_base::sync_with_stdio(false);
  int t, n, l, r, cnt;
  cin >> t;
  while(t--)
    {
      cin >> n;
      for(int i = 0; i < n; i++)
	{
	  cin >> l >> r;
	  inv[i] = intv(l,r);
	}
      sort(inv, inv+n, comp);
      r = inv[0].second;
      cnt = 1;
      for(int i = 0; i < n; i++){
	if(inv[i].first > r){// || inv[i].second < r){
	  r = inv[i].second;
	  cnt++;
	}
      }
      cout << cnt << endl;
    }
}
