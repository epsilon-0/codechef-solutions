#include <bits/stdc++.h>

using namespace std;

class UnionFind{
public:
  UnionFind(int inputSize) : 
                  maxSize(inputSize)
  { 
    parent.resize(maxSize, 0); 
    treeCount.resize(maxSize, 1); 
    treeHeight.resize(maxSize, 0);
    for(int i = 0; i < maxSize; i++)
      parent[i] = i;
  }

  int find(int vertex){
    int root = vertex;
    while(parent[root] != root)
      root = parent[root];
    int temp1 = vertex, temp2;
    while(parent[temp1] != root){
      temp2 = parent[temp1];
      parent[temp1] = root;
      temp1 = temp2;
    }
    return root;
  }

  void merge(int vertex1, int vertex2){
    int root1 = this->find(vertex1), root2 = this->find(vertex2);
    if(root1 != root2){
      if(treeHeight[root1] > treeHeight[root2])
        swap(root1, root2);
      if(treeHeight[root1] == treeHeight[root2])
        treeHeight[root1]++;
      parent[root1] = root2;
      treeCount[root2] += treeCount[root1];
    }
  }

private:
  const int maxSize;
  vector<int> parent, inputSize, treeCount, treeHeight;

};

tuple<int, int, int> edges[100005];

int main(){
  int n, m;
  cin >> n >> m;
  UnionFind unf(n+10);

  for(int i = 0; i < m; i++){
    int a, b, w;
    cin >> a >> b >> w;
    edges[i] = make_tuple(w, a, b);
  }

  sort(edges, edges + m);

  long long totalWeight = 0;

  for(int i = 0; i < m; i++){
    int w = get<0>(edges[i]);
    int a = get<1>(edges[i]);
    int b = get<2>(edges[i]);
    if(unf.find(a) != unf.find(b)){
      totalWeight += (long long) w;
      unf.merge(a, b);
    }
  }

  cout << totalWeight << endl;
}