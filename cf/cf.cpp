#include <bits/stdc++.h>
#define blank ' '
#define len(x) x.size()
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, float> ifl;
typedef pair<int, double> id;
typedef pair<float, float> ff;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<ii> vii;
typedef vector<ifl> vif;
typedef vector<ff> vff;
typedef vector<id> vid;
typedef vector<vector<int>> vvi;

void solve() {
    int n, m; cin >> n >> m;
    vi cnt(n + 1, 0);
    vvi graph(n + 1);

    for(int x, y; m--; ){
        cin >> x >> y;
        cnt[x]++;
        cnt[y]++;
        graph[x].emplace_back(y);
        graph[y].emplace_back(x);
    }

    bool found = true;
    int ans = 0;
    while(found) {
        found = false;
        for(int i = 1; i <= n; i++) {
            if(cnt[i] == 1) {
                found = true;
                queue<int> q;
                q.push(i);
                while(!q.empty()) {
                    int temp = q.front(); q.pop();
                    cnt[temp]--;
                    for(auto neighbour : graph[temp]) {
                        cnt[neighbour]--;
                        q.push(neighbour);
                    }
                }
            }
        }
        if(found) ans++;
    }
    
    cout << ans << endl;
}   

int main() {    
    ios_base::sync_with_stdio(0); cin.tie(0);
    int testCase = 1;
    // cin >> testCase;
    while(testCase--) solve();
}

/*

*/