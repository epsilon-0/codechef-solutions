#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>

using namespace std;

int mod_pow(int x,int y,int k);

set<pair<int,int> > sgt;

int main(){
  int n,m,x,y;
  cin>>n>>m;
  while(m--){
    cin>>x>>y;
    sgt.insert(make_pair(x,y));
  }
  int cntr=0;
  pair<int,int> cur,tmp;
  int max;
  while(!sgt.empty()){
    cur=*(sgt.begin());
    sgt.erase(cur);
    max=cur.second;
    while(!sgt.empty() && (*sgt.begin()).first==cur.first){
      tmp=*(sgt.begin());
      sgt.erase(tmp);
      sgt.insert(make_pair(max+1,tmp.second));
      max=tmp.second;
    }
    cntr++;
  }
  cout<<mod_pow(2,cntr,1000000007)<<endl;
}

int mod_pow(int x,int y,int k){
  int tmp=x,ans=1;
  for(;y;y>>=1){
    if(y&1){
      ans=((long long)ans*tmp)%k;
    }
    tmp=((long long)tmp*tmp)%k;
  }
  return ans;
}
