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

pair<double,double> points[2005];

int n;

int answer(pair<double,double> p, pair<double,double> q){
  double x1=p.FF,y1=p.SS,x2=q.FF,y2=q.SS;
  int ad[3]={0};
  // if these were the diagonal points
  double x3,y3,x4,y4;
  x3=(x1+x2+y2-y1)/2;
  y3=(y1+y2+x1-x2)/2;
  x4=(x1+x2+y1-y2)/2;
  y4=(y1+y2+x2-x1)/2;
  if(!binary_search(points,points+n,make_pair(x3,y3))){
    ad[0]++;
  }
  if(!binary_search(points,points+n,make_pair(x4,y4))){
    ad[0]++;
  }
  // now if these were points on a side of the square
  double x5,y5,x6,y6;
  x5=2*x3-x1;
  y5=2*y3-y1;
  x6=2*x3-x2;
  y6=2*y3-y2;
  if(!binary_search(points,points+n,make_pair(x5,y5))){
    ad[1]++;
  }
  if(!binary_search(points,points+n,make_pair(x6,y6))){
    ad[1]++;
  }
  // now we make the square on the other side
  double x7,y7,x8,y8;
  x7=2*x4-x1;
  y7=2*y4-y1;
  x8=2*x4-x2;
  y8=2*y4-y2;
  if(!binary_search(points,points+n,make_pair(x7,y7))){
    ad[2]++;
  }
  if(!binary_search(points,points+n,make_pair(x8,y8))){
    ad[2]++;
  }
//  cout<<x3<<" "<<y3<<endl<<x4<<" "<<y4<<endl<<x5<<" "<<y5<<endl<<x6<<" "<<y6<<endl<<x7<<" "<<y7<<endl<<x8<<" "<<y8<<endl;
  return *min_element(ad,ad+3);
}

int main(){
  int x,y,ans;
  cin>>n;
  REP(i,0,n){
    cin>>x>>y;
    points[i]=make_pair(x,y);
  }
  sort(points,points+n);
  ans=4;
  REP(i,0,n){
    REP(j,i+1,n){
      ans=min(ans,answer(points[i],points[j]));
    }
  }

  if(n==1){
    cout<<"3\n";
  }else{
  cout<<ans<<endl;
  }
}
