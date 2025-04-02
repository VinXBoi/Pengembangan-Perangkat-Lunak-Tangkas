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

void solve() {
    int n; cin >> n;
    map<int,int> mp;
    for(int i = 0; i < n; i++) {
        int num; cin >> num;
        mp[num] = i;
    }
    for()
}

int main() {    
    ios_base::sync_with_stdio(0); cin.tie(0);
    int testCase = 1; cin >> testCase;
    while(testCase--) solve();
}

/*
1 2 3 4 5 6
1 3 5 2 4 6
*/