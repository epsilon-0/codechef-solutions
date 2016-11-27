#include <bits/stdc++.h>

using namespace std;

const long long MOD = 7 + (1e9);

//////////// DOESNT  WORK

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long> nums;
        for(int i = 0; i < n; i++){
            long long k;
            cin >> k;
            nums.push_back(k);
        }
        long long ans = nums[0];
        for(int i = 1; i < n; i++){
            ans = (ans + ans^nums[i] + nums[i] + MOD) % MOD;
        }
        cout << ans << endl;
    }
}