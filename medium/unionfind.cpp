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

int main(){
  
}
