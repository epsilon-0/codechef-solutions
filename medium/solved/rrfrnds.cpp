#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>

using namespace std;

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define Mx 2001

bool graph[Mx][Mx]={false};
vector<int> adjm[Mx];

int main(){
  int n;
  cin>>n;
  string sc;
  REP(i,0,n) adjm[i].clear();
  REP(i,0,n){
    cin>>sc;
    REP(j,0,n){
      if(sc[j]=='1'){
        graph[i][j]=true;
        adjm[i].push_back(j);
        adjm[j].push_back(i);
      }
    }
  }
  int count=0;
  REP(i,0,n){
    REP(j,i+1,n){
      if(graph[i][j]){
        continue;
      }
      REP(k,0,adjm[i].size()){
        if(graph[i][adjm[i][k]] && graph[j][adjm[i][k]]){
          count++;
          count++;
          break;
        }
      }
    }
  }
  cout<<count<<endl;
}
