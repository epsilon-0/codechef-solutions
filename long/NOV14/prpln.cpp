#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<numeric>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<list>
#include<climits>
#include<cstdlib>
#include<string>
#include<cmath>
#include<cassert>

using namespace std;

// useful functions
#define REV(s,e) reverse(s,e)
#define MSET(s,i) memset(s,i,sizeof(s))
#define MCPY(i,j) memcpy(i,j,sizeof(j))
#define MP(x,y) make_pair(x,y)
#define REP(i,a,b) for(int i=a;i<b;i++)

// shortforms
#define FF first
#define SS second
#define LD long double
#define LL long long int
#define UG unsigned

// constants
const int inf=1000000007; //prime
const LD eps=1e-9;

///// MAIN CODE NOW /////

string pr;

bool ispalin(int st, int nd){
  REP(i, 0, nd+1-st){
    if(pr[st+i] != pr[nd-i]){
      return false;
    }
  }
  return true;
}

int main(){
  int t;
  int st, nd;
  cin >> t;
  while(t--){
    cin >> pr;
    if ( ispalin(0, pr.length()-1) ){
      cout << "YES\n";
      continue;
    }
    st = 0; nd = pr.length() - 1;
    while(pr[st] == pr[nd]){
      st++;
      nd--;
    }
    if ( ispalin(st+1, nd) || ispalin(st,nd-1) ){
      cout << "YES\n";
    }
    else{
      cout << "NO\n";
    }
  }
}







