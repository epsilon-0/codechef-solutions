#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>

#define ff first
#define ss second

using namespace std;

bool open[50001],visited[50001];
vector<int> graph[50001];
int cntr,win;

pair<int,int> dfs(int v);

int main(){

  // Taking input /////////
  int n,m,temp,x,y;
  scanf("%d %d",&n,&m);
  for(int i=0;i<n;i++){
    scanf("%d",&temp);
    open[i]=false;
    if(temp){
      open[i]=true;
    }
  }
  for(int i=0;i<m;i++){
    scanf("%d %d",&x,&y);
    x--;y--;
    graph[x].push_back(y);
    graph[y].push_back(x);
  }
  //////////////////////////

  long long int pairs=0,tmp;
  int drght=0;
  pair<int,int> p;

  for(int i=0;i<n;i++){
    if(open[i] && !visited[i]){
      p=dfs(i);
      if(p.ff>1){
	tmp=p.ff;
	pairs+=((tmp*(tmp-1))/2);
	drght+=p.ss;
      }
    }
  }
  cout<<pairs<<" "<<drght<<endl;
}

pair<int,int> dfs(int v){
  visited[v]=true;
  int op=0,drght=0;
  if(open[v]){
    op++;
  }
  pair<int,int> p;
  for(int i=0;i<graph[v].size();i++){
    if(!visited[graph[v][i]]){
      p=dfs(graph[v][i]);
      op+=p.ff;
      drght+=p.ss;
    }
  }
  if(drght || open[v]){
    drght++;
  }
  p.ff=op;p.ss=drght;
  return p;
}
