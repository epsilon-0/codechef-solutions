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

// important functions

LL modpow(LL x, LL y, LL k){ // returns x^y mod k // all of them are long long integers
  if( y == 0){
    return 1%k;
  }
  LL tmp = x, ans = 1ll;
  for( ; y; y >>= 1){
    if (y & 1){
      ans = (ans*tmp) % k;
    }
    tmp = (tmp*tmp) % k;
  }
  return ans;
}

LL mgcd(LL a, LL b){
  LL t;
  while(a!=0){
    t=b%a;
    b=a;
    a=t;
  }
  return b;
}

LL modinverse(LL a, LL b){ // returns the inverse of a mod b if it exists else gives 0// returns n such that a*n % b = 1 if possible else returns 0
  if(mgcd(a,b)!=1) return 0;
	LL b0 = b, t, q;
	LL x0 = 0, x1 = 1;
	if (b == 1) return 1;
	while (a > 1) {
		q = a / b;
		t = b, b = a % b, a = t;
		t = x0, x0 = x1 - q * x0, x1 = t;
	}
	if (x1 < 0) x1 += b0;
	return x1;
}

// end of important functions don't fucking delete them



int main(){
  cout << mgcd(12,24) << endl;
  cout << modinverse(2,4) << endl;
}










