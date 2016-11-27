#include<iostream>
#include<map>
#include<cstring>
#include<algorithm>

using namespace std;

int apples[500010],maxs[1000010],mins[1000010];

int main(){
  for(int i=0;i<1000010;i++){
    maxs[i]=-1;
    mins[i]=1000011;
  }
  int n,k,dist,x1,x2,flag=0;
  cin>>n>>k;
  for(int i=0;i<n;i++){
    cin>>apples[i];
    maxs[apples[i]]=i;
    mins[apples[i]]=min(i,mins[apples[i]]);
  }

  dist=2*n+1;

  for(int i=0;i<n;i++){
    if(k<apples[i] || 2*apples[i]==k){
      continue;
    }
    x1=maxs[k-apples[i]];x2=mins[k-apples[i]];
    if(x1!=-1){
      flag=1;
      dist=min(dist,max(n-x1,i+1));
      dist=min(dist,n-min(x1,i));
    }
    if(x2!=1000011){
      flag=1;
      dist=min(dist,max(i+1,x2+1));
      dist=min(dist,max(n-i,x2+1));
    }
  }

  if(flag){
    cout<<dist<<endl;
  }
  else{
    cout<<-1<<endl;
  }
}
