#include<iostream>
#include<cstring>
#include<map>

using namespace std;

int c1[100],c2[100];

map<char,int> a1,a2;

int main(){
  int t,sum;
  string s;
  cin>>t;
  while(t--){
    sum=0;
    cin>>s;
    for(int i=0;i<s.length();i++){
      if(a1.count(s[i])){
	a1[s[i]]++;
      }
      else{
	a1[s[i]]=1;
      }
    }

    cin>>s;
    for(int i=0;i<s.length();i++){
      if(a2.count(s[i])){
	a2[s[i]]++;
      }
      else{
	a2[s[i]]=1;
      }
    }

    for(map<char,int>::iterator t=a1.begin();t!=a1.end();t++){
      sum+=min((*t).second,a2[(*t).first]);
    }

    a1.clear();a2.clear();

    cout<<sum<<endl;
  }
}
