#include <bits/stdc++.h>
#define INF 1000000000
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

string s;
stack<char> player;
stack<char> dealer;
stack<char> temp;

void solve() {
    int n, m; cin >> n >> m;
    int cnt = 0;
    vector<vector<int>> graph(n + 1);
    vector<bool> visited(n + 1, false);

    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for(int i = 0; i < n; i++) {
        if(!visited[i + 1]) {
            queue<int> q;
            q.push(i + 1);
            visited[i + 1] = true;
            cnt++;
            while(len(q)) {
                int temp = q.front(); q.pop();
                for(int j = 0; j < len(graph[temp]); j++) {
                    if(!visited[graph[temp][j]]) {
                        visited[graph[temp][j]] = true;
                        q.push(graph[temp][j]);
                    }
                }
            }
        }
    }
    cout << m - (n - cnt) << endl;
}

int main() {    
    ios_base::sync_with_stdio(0); cin.tie(0);
    int testCase = 1;
    while(testCase--) solve();
}

/*

*/