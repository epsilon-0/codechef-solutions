#include<iostream>
#include<algorithm>

using namespace std;

#define pint pair<int,int>
#define mp(a,b) make_pair(a,b)
#define MX 1000001

string str;
pint diff[MX];

int main(){
  int suma=0,sumb=0,sumc=0;
  cin>>str;
  for(int i=0;i<str.length();i++){
    if(str[i]=='A'){
      suma++;
    }
    if(str[i]=='B'){
      sumb++;
    }
    if(str[i]=='C'){
      sumc++;
    }
    diff[i]=mp(suma-sumb,suma-sumc);
    cout<<diff[i].first<<" "<<diff[i].second<<endl;
  }
  sort(diff,diff+str.length());
  int curr=0,solution=0;
  for(int i=1;i<str.length();i++){
    if(diff[i].first!=diff[curr].first || diff[i].second!=diff[curr].second){
      solution+=(i-curr)*(i-curr-1)/2;
    }
  }
  cout<<solution<<endl;
}
