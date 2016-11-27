#include<iostream>
#include<cstdio>

using namespace std;

int gcd(int a, int b){
  int t = a;
  while(a>0){
    t = a;
    a = b%a;
    b = t;
  }
  return b;
}

int lgcd[100005], rgcd[100005], a[100005];

#define S(n) scanf("%d", &n)
#define P(n) printf("%d\n", n)

int main(){
  int t, n, q, l, r;
  S(t);//cin >> t;
  while(t--){
    cin >> n >> q;
    //    cout << n << q << endl;;
    for(int i = 0; i < n; i++){
      S(a[i]);//cin >> a[i];
    }
    lgcd[0] = a[0];
    rgcd[n-1] = a[n-1];
    for(int i = 1; i < n; i++){
      lgcd[i] = gcd(lgcd[i-1],a[i]);
      rgcd[n-i-1] = gcd(rgcd[n-i], a[n-i-1]);
    }
    for(int i = 0; i < q; i++){
      S(l);S(r);//cin >> l >> r;
      //      cout << l << r << endl;
      l--;r--;
      if(l>0 && r<n-1){
	P(gcd(lgcd[l-1], rgcd[r+1]));// << endl;
      }
      else if(l==0 && r<n){
	P(rgcd[r+1]);// << endl;
      }
      else{
	P(lgcd[l-1]);// << endl;
      }
    }
  }
}
