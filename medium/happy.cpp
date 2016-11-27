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

double determinant(vector<vector<double> >& D){
  double det = 1.0, q;
  double eps = 1e-10;
  for(int i = 0; i < D.size(); i++){
    if(abs(D[i][i]) < eps)
      for(int j = i+1; j < D.size(); j++)
        if(abs(D[j][i]) > eps){
          D[j].swap(D[i]);
          det *= -1;
          break;
        }

      if(D[i][i] < eps){
        for(int j = i; j < D.size(); j++)
          D[i][j] *= -1;
        det *= -1;
      }

    det *= D[i][i];
    if(abs(det) < eps)
      return 0.0;

    for(int j = i+1; j < D.size(); j++){
      q = D[j][i]/D[i][i];
      if(abs(q) < eps)
        continue;
      for(int k = i; k < D.size(); k++)
        D[j][k] -= D[i][k]*q;
    }
  }
  return det;
}


int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    
    vector<vector<int> > adj(n, vector<int>());

    for(int i = 0; i < n; i++){
      string nbh;
      cin >> nbh;
      for(int j = 0; j < n; j++)
        if(nbh[j] == '1')
          adj[i].push_back(j);
    }

    int p;
    cin >> p;

    


  }

}