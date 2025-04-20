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
    vvi dishes(m);
    vvi ingredients(n);
    vi cnt(m);
    for(int i = 0; i < m; i++) {
        int k; cin >> k;
        cnt[i] = k;
        for(int j = 0; j < k; j++) {
            int num; cin >> num;
            ingredients[--num].push_back(i);
        }
    }
    
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int safe; cin >> safe;
        for(auto dish : ingredients[--safe]) {
            cnt[dish]--;
            if(cnt[dish] == 0) ans++;
        }
        cout << ans << endl;
    }

    
}

int main() {    
    ios_base::sync_with_stdio(0); cin.tie(0);
    int testCase = 1;
    // cin >> testCase;
    while(testCase--) solve();
}

/*

*/