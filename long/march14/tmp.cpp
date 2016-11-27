#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

#define MP(i,j) make_pair(i,j)
const int inf=1000000009;

pair<int,int> nums(int n){
  int i,j;
  i=log2(n);
  n-=1<<i;
  j=log2(n);
  return make_pair(i,j);
}

int intsize(int k){
  int s=0,n=k;
  while(n){
    if(n&1){
      s++;
    }
    n>>=1;
  }
  return s;
}

vector<pair<int,int> > v;

pair<int,int> qindex(int left,int right){
  int top,bot;
  top=upper_bound(v.begin(),v.end(),MP(right,inf))-v.begin()-1;
  bot=lower_bound(v.begin(),v.end(),MP(left,0))-v.begin();
  return MP(bot,top);
}

int main(){
  int n,t;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>t;
    v.push_back(make_pair(2*i+1,t));
  }
  sort(v.begin(),v.end());
  for(int i=0;i<n;i++){
    cout<<v[i].first<<" "<<v[i].second<<endl;
  }
  int x,y;
  cin>>x>>y;
  pair<int,int> t1=qindex(x,y);
  cout<<t1.first<<" "<<t1.second<<endl;
}
