#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

int determinant(vector<vector<int> > mat) {
  int n = mat.size();
  bool found;
  for(int col = 0; col < n; ++col) {
    found = false;
    for(int row = col; row < n; ++row) {
      if(mat[row][col]) {
        if ( row != col ) {
          mat[row].swap(mat[col]);
        }
        found = true;
        break;
      }
    }

    if(!found) {
      return 0;
    }
    int del;
    for(int row = col + 1; row < n; ++row) {
      while(true) {
        del = mat[row][col] / mat[col][col];
        for (int j = col; j < n; ++j) {
          mat[row][j] -= del * mat[col][j];
        }
        if (mat[row][col] == 0) {
          break;
        }
        else{
          mat[row].swap(mat[col]);
        }
      }
    }
   }

   long long res = 1;

   for(int i = 0; i < n; ++i){
      res *= mat[i][i];
   }
   return abs(res);
}

int main(){
}
