#include <bits/stdc++.h>

using namespace std;

string lexopal(string s){
	string newPalin = s;
	int n = s.length();
	for(int i = 0; i < n; i++){
		if(newPalin[n-1-i]=='.'){
			continue;
		}
		else if(newPalin[i]=='.'){
			newPalin[i] = newPalin[n-1-i];
		}
		else if(newPalin[i]!=newPalin[n-1-i]){
			return newPalin;
		}
	}
	return newPalin;
}

bool isPalindrome(string s){
	for(int i = 0; i < s.length(); i++){
		if(s[i]!=s[s.length()-1-i]){
			return false;
		}
	}
	return true;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		string n = lexopal(s);
		if(!isPalindrome(n)){
			cout << -1;
		}
		else{
			for(char c : n){
				if(c=='.')
					cout << 'a';
				else
					cout << c;
			}
		}
		cout << endl;
	}
}