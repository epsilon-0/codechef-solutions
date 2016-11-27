#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	string s;
	cin >> t;
	while(t--){
		int count0, count1;
		count0 = count1 = 0;
		cin >> s;
		for(char c : s){
			if(c=='0'){
				count0++;
			}
			else{
				count1++;
			}
		}
		if(count0==1 || count1==1){
			cout << "Yes\n";
		}
		else{
			cout << "No\n";
		}
	}
}