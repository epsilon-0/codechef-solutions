#include <bits/stdc++.h>

using namespace std;

vector<int> getZArray(string str){
    int n = str.length();
    vector<int> Z(n, -1);
    int L, R, k;
    L = R = 0;
    for (int i = 1; i < n; ++i){
        if (i > R){
            L = R = i;
            while (R<n && str[R-L] == str[R])
                R++;
            Z[i] = R-L;
            R--;
        }
        else{
            k = i-L;
            if (Z[k] < R-i+1)
                 Z[i] = Z[k];
            else{
                L = i;
                while (R<n && str[R-L] == str[R])
                    R++;
                Z[i] = R-L;
                R--;
            }
        }
    }
    return Z;
}

const long long MOD = 7 + (1e9);

int main(){
    int t;
    cin >> t;
    while(t--){
        string str, pattern, concatted;
        cin >> str >> pattern;
        concatted = pattern + "$" + str;
        auto Z = getZArray(concatted);
        vector<int> prefixArray(Z.begin() + pattern.length() + 1, Z.end());
        vector<int> patternPositions;
        for(int i = 0; i < prefixArray.size(); i++)
            if(prefixArray[i] == pattern.size())
                patternPositions.push_back(i);

        patternPositions.push_back(pattern.size() + str.size() + 10);

        vector<long long> DP(patternPositions.size(), 0);

        for(int i = patternPositions.size() - 2; i >= 0; i--){
            DP[i] = DP[i+1];
//            cout << "current pos is " << patternPositions[i] << endl;
            int pos = upper_bound(patternPositions.begin(), 
                                  patternPositions.end(), 
                                  patternPositions[i] + pattern.size() - 1
                                  ) - patternPositions.begin();
//            cout << "next pos is " << patternPositions[pos] << endl;
            DP[i] += DP[pos] + 1;
            DP[i] = DP[i] % MOD;
//            cout << "number of ways are " << DP[i] << endl;
        }

        cout << DP[0] << endl;
    }
}