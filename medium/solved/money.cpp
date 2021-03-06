#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#define ug unsigned
#define pb(x) push_back(x)

using namespace std;

bool comp[64000];
vector<ug> fact,primes,dp;
ug store[100000];

void preprocess(){
  comp[0]=true;
  comp[1]=true;
  for(ug i=2;i<252;i++){
    if(!comp[i]){
      for(ug j=i*i;j<64000;j+=i){
	comp[j]=true;
      }
    }
  }
  for(ug i=2;i<64000;i++){
    if(!comp[i]){
      primes.pb(i);
    }
  }
}

void factors(ug k){
  ug n=k;
  fact.clear();
  fact.pb(1);
  ug s,t;
  for(ug i=0;i<primes.size();i++){
    if(primes[i]*primes[i]>n){
      break;
    }
    else{
      s=fact.size();
      while(n%primes[i]==0){
	n/=primes[i];
	t=fact.size();
	for(ug j=t-s;j<t;j++){
	  fact.pb(fact[j]*primes[i]);
	}
      }
    }
  }
  if(n-1){
    s=fact.size();
    for(ug i=0;i<s;i++){
      fact.pb(fact[i]*n);
    }
  }
}

ug solve(ug k){
  ug n=k+1;
  dp.clear();
  factors(n);
  dp.resize(fact.size(),0);
  dp[0]=1;
  for(ug i=1;i<dp.size();i++){
    if(fact[i]<100000 && store[fact[i]]){
      dp[i]=store[fact[i]];
    }
    else{
      for(ug j=0;j<i;j++){
	if(fact[i]%fact[j]==0){
	  dp[i]+=dp[j];
	}
      }
      if(fact[i]<100000){
	store[fact[i]]=dp[i];
      }
    }
  }
  return dp[dp.size()-1];
}

int main(){
  memset(store,0,sizeof(store));
  preprocess();
  ug t,n;
  cin>>t;
  for(ug i=1;i<=t;i++){
    cin>>n;
    cout<<solve(n)<<endl;
    }
}
