#include <bits/stdc++.h>
#define INF 1000000000
#define blank ' '
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, float> pifl;
typedef pair<int, double> pid;
typedef pair<float, float> pff;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<pll> vll;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<pifl> vif;
typedef vector<pff> vff;
typedef vector<pid> vid;

void yes() {
    cout << "Yes" << endl;
}

void no() {
    cout << "No" << endl;
}

void solve() {
    int n, m; cin >> n >> m;
    vi black(n); vi white(m);

    for(auto &num : black) cin >> num;
    for(auto &num : white) cin >> num;
    
    sort(black.rbegin(), black.rend());
    sort(white.rbegin(), white.rend());

    ll ans = 0;
    vi maxBlack(n + 1, 0);
    vi maxWhite(m + 1, 0);
    for(int i = 0; i < n; i++) {
        maxBlack[i + 1] = black[i] + maxBlack[i];
        cout << "Black : " << maxBlack[i + 1] << endl;
    }

    for(int i = 0; i < m; i++) {
        maxWhite[i + 1] = white[i] + maxWhite[i];
        cout << "White : " << maxWhite[i + 1] << endl;
    }
    cout << maxBlack[n + 1] + maxWhite[m + 1] << endl;
    cout << ans << endl;
}

int main() {    
    ios_base::sync_with_stdio(0); cin.tie(0);
    int testCase = 1;
    while(testCase--) solve();
}

/*
7 = 111
4 = 100
b = 011 = 3

3 = 011
5 = 101
a = 110 = 6

1 = 001
2 = 010
4 = 111
a = 111 = 7
*/