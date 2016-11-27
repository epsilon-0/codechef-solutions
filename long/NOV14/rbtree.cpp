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

// shortforms
#define FF first
#define SS second
#define LD long double
#define LL long long int
#define UG unsigned

#define REP(i,a,b) for(LL i=a;i<b;i++)

// constants
const int inf=1000000007; //prime
const LD eps=1e-9;

///// MAIN CODE NOW /////

#define level(i) ceil(log2(i+1))

int parent(int i, int j){
  int x=i,y=j;
  int lx=level(x),ly=level(y);
  while(x!=y){
    if(lx>ly){
      x>>=1;
      lx--;
    }
    else if(ly>lx){
      y>>=1;
      ly--;
    }
    else{
      x>>=1;lx--;
      y>>=1;ly--;
    }
  }
  return x;
}

int root=1;

int color(int i){
  int lev=level(i);
  if(lev&1){
    return root;
  }
  return 1-root;
}

int main(){
  int q, x, y, par;
  int lx, ly, lp, col, lgt, blacks;
  string s;
  cin >> q;
  while(q--){
    cin >> s ;
    if(s=="Qi"){
      root = 1-root;
      continue;
    }
    cin >> x >> y;
    if(x<y) swap(x,y);
    // we will calculate the black nodes on this path
    par = parent(x,y);
    lx=level(x);
    ly=level(y);
    lp=level(par);
    lgt = ly-lp+lx-lp+1;
    col=color(par);
    blacks=0;
    if(col==1){
      blacks+=1;
      blacks+=(ly-lp)/2;
      blacks+=(lx-lp)/2;
    }
    else{
      blacks+=(ly-lp+1)/2;
      blacks+=(lx-lp+1)/2;
    }
    if(s=="Qb"){
      cout << blacks << endl;
    }
    else{
      cout << lgt-blacks << endl;
    }
  }
}









