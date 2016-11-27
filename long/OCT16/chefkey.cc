#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		long long n, m, c;
		cin >> n >> m >> c;
		int cnt = 0;
		for(long long i = 1; i <= n; i++){
			long long k = c/i;
			if((k <= m) && (k*i == c))
				cnt++;
		}
		cout << cnt << endl;
	}
}