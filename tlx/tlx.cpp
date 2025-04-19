#include <bits/stdc++.h>
#define mod 1000000007
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
typedef vector<char> vc;
typedef vector<ii> vii;
typedef vector<ifl> vif;
typedef vector<ff> vff;
typedef vector<id> vid;
typedef vector<vi> vvi;
typedef vector<vc> vvc;

void solve() {
    ll b, c, d; cin >> b >> c >> d;
    int cnt = 0;
    for(ll i = 1; i <= b; i++) {
        if(c % i == d) cnt++;
    }
    cout << cnt << endl;
}

int main() {    
    ios_base::sync_with_stdio(0); cin.tie(0);
    int testCase = 1;
    // cin >> testCase;
    while(testCase--) solve();
}

/*

*/