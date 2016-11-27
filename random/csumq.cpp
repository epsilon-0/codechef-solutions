#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5+1e5;

long long arr[MAXN];
long long segtree[10*MAXN];

void makeTree(int left, int right, int node){
  if(left == right){
    segtree[node] = arr[left];
    return;
  }
  int mid = (left+right)>>1;
  makeTree(left, mid, 2*node+1);
  makeTree(mid+1, right, 2*node+2);
  segtree[node] = segtree[2*node+1] + segtree[2*node+2];
}

long long query(int left, int right, int bot, int top, int node){
  if(left<=bot && top<=right){
    return segtree[node];
  }
  if(left>top || bot>right){
    return 0;
  }
  int mid = (bot+top)>>1;
  return query(left, right, bot, mid, 2*node+1) + query(left, right, mid+1, top, 2*node+2);
}

int main(){
  int n, q;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  makeTree(0, n-1, 0);
  cin >> q;
  int l, r;
  for(int i = 0; i < q; i++){
    cin >> l >> r;
    cout << query(l, r, 0, n-1, 0) << endl;
  }
}