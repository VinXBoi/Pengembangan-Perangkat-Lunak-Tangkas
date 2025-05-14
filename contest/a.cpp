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
    int n, m; cin >> n >> m;
    vi arr(m + 1, 0);
    vi temp(n, 0);
    vi temp2(n, 0);
    for(int i = 0; i < n; i++) { 
        cin >> temp[i];
        arr[temp[i]]++;
    }
    temp2 = temp;
    sort(temp.begin(), temp.end());

    int idx = 0;
    for(int i = 0; i < n; i++) {
        if(idx + 1 == temp[i]) idx++;
    }

    if(idx != m) {
        cout << 0 << endl;
        return;
    }

    int cnt = 0;
    for(int i = n - 1; i >= 0; i--) {
        arr[temp2[i]]--;
        cnt++;
        if(arr[temp2[i]] == 0) {
            cout << cnt << endl;
            return;
        }
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