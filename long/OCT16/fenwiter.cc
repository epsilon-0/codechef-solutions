#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		string a, b, c;
		long long n;
		cin >> a >> b >> c >> n;
		long long countA = 0, countB = 0, countC = 1;

		for(char cc : a)
			if(cc == '1')
				countA++;

		for(char cc : b)
			if(cc == '1')
				countB++;
		countB *= n;

		while(*c.rbegin() == '1')
			c.pop_back();
		for(char cc : c)
			if(cc == '1')
				countC++;

		cout << countC + countB + countA << endl;
	}
}