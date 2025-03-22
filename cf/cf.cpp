#include <bits/stdc++.h>
#define INF 1000000000
#define blank ' '
#define len(x) x.size()
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
    int n; cin >> n;
    vector<int> p, m, pe;

    for(int i = 0; i < n; i++) {
        int num; cin >> num;
        if(num == 1) p.push_back(i + 1);
        if(num == 2) m.push_back(i + 1);
        if(num == 3) pe.push_back(i + 1);
    }
    n = min({len(p), len(m), len(pe)});
    cout << n << endl;
    for(int i = 0; i < n; i++) {
        cout << p[i] << ' ' << m[i] << ' ' << pe[i] << '\n';
    }
}

int main() {    
    ios_base::sync_with_stdio(0); cin.tie(0);
    int testCase = 1;
    while(testCase--) solve();
}

/*
7
1 3 1 3 2 1 2

4
2 1 1 2
*/