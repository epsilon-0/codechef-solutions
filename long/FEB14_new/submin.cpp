#include<iostream>
#include<map>
#include<algorithm>

using namespace std;

int a[51];
map<int,int> mins;

int main(){
  int n,q,m;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
      m=*min_element(a+i,a+j+1);
      if(mins.count(m)){
	mins[m]++;
      }
      else{
	mins[m]=1;
      }
    }
  }
  cin>>q;
  for(int i=0;i<q;i++){
    cin>>m;
    cout<<mins[m]<<endl;
  }
}
