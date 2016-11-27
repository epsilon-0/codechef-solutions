#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int indeg[10004] = {0};
vector<int> adj[10004];

int main(){
  ios_base::sync_with_stdio(false);
  int n, m, x, y;
  cin >> n >> m;
  for(int i = 1; i <= m; i++){
    cin >> x >> y;
    adj[x].push_back(y);
    indeg[y]++;
  }
  priority_queue<int, vector<int>, greater<int> > mheap;
  for(int i = 1; i <= n; i++){
    if(indeg[i] == 0){
      mheap.push(i);
    }
  }
  vector<int> order;
  while(!mheap.empty()){
    int next = mheap.top();
    mheap.pop();
    order.push_back(next);
    for(int i = 0; i < adj[next].size(); i++){
      int neigh = adj[next][i];
      indeg[neigh]--;
      if(indeg[neigh] == 0){
	mheap.push(neigh);
      }
    }
  }
  if(order.size() != n){
    cout << "Sandro fails.\n";
  }
  else{
    for(int i = 0; i < n; i++){
      cout << order[i] << " ";
    }
    cout << endl;
  }
}
