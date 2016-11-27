#include <bits/stdc++.h>

using namespace std;

unsigned long long gcd(unsigned long long a, unsigned long long b){
    if(a == 0)
        return b;
    return gcd(b%a, a);
}

vector<pair<int, unsigned long long> > adj[50005];
bool visited[50005], special[50005];

int n, m;

unsigned long long total = 0;

int dfs(int vert){
    visited[vert] = true;
    int sp = 0;
    if(special[vert])
        sp++;

    for(auto nbhPair : adj[vert])
        if(!visited[nbhPair.first]){
            int nbh = nbhPair.first;
            unsigned long long weight = nbhPair.second;
            int nbhSpecial = dfs(nbh);
            sp += nbhSpecial;
            total += (unsigned long long) weight * nbhSpecial * (m - nbhSpecial);
        }

    return sp;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        for(int i = 0; i < 50005; i++)
            adj[i].clear(), visited[i] = false, special[i] = false, total = 0;

        cin >> n >> m;

        for(int i = 0; i < n-1; i++){
            int x, y;
            unsigned long long w;
            cin >> x >> y >> w;
            adj[x].push_back(make_pair(y, w));
            adj[y].push_back(make_pair(x, w));
        }

        for(int i = 0; i < m; i++){
            int sp;
            cin >> sp;
            special[sp] = true;
        }

        dfs(1);

        unsigned long long mGCD = gcd((unsigned long long) total * 2, (unsigned long long) m * m);

        cout << (unsigned long long) total * 2 / mGCD << " " << (unsigned long long) m * m / mGCD << endl;
    }
}