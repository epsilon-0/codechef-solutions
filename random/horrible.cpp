#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5+1e5;

long long segtree[10*MAXN];
long long addVal[10*MAXN];

void update(int left, int right, int bot, int top, int node, long long val){
  if(left>top || bot>right){
    return;
  }
  if(left<=bot && top<=right){
    addVal[node] += val;
    return;
  }
  int mid = (bot+top)>>1;
  addVal[2*node+1] += addVal[node];
  addVal[2*node+2] += addVal[node];
  update(left, right, bot, mid, 2*node+1, val);
  update(left, right, mid+1, top, 2*node+2, val);
  segtree[node] += addVal[node]*(top-bot+1) + val*(max(0, min(top, right) - max(left,bot) + 1));
  addVal[node] = 0;
  return;
}

long long query(int left, int right, int bot, int top, int node){
  if(left<=bot && top<=right){
    return segtree[node] + addVal[node]*(top-bot+1);
  }
  if(left>top || bot>right){
    return 0;
  }
  int mid = (bot+top)>>1;
  return query(left, right, bot, mid, 2*node+1) + query(left, right, mid+1, top, 2*node+2);
}

int main(){
  int t;
  cin >> t;
  while(t--){
    for(int i = 0; i < 10*MAXN; i++){
      addVal[i] = 0;
      segtree[i] = 0;
    }
    int n, q;
    cin >> n >> q;
    int t, l, r;
    long long v;
    for(int i = 0; i < q; i++){
      cin >> t;
      if(t == 1){
        cin >> l >> r;
	update(l-1, r-1, 0, n-1, 0, 0);
	cout << query(l-1, r-1, 0, n-1, 0) << endl;
      }
      else{
	cin >> l >> r >> v;
	update(l-1, r-1, 0, n-1, 0, v);
      }
    }
  }
}
