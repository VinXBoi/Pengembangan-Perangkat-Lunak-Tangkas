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
    int n, m, x; cin >> n >> m >> x;
    int size = max(n, m);
    vvi arr(size, vi (size, 0));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    n--; m--;
    for(int i = 0; i < x; i++) {
        vii temp(size, vi(size, 0));
        string s; cin >> s;
        if(s == "90" || s == "270") swap(n, m);
        for(int row = 0; row < size; row++) {
            for(int col = col; col < size; col++) {
                if(s == "|") temp[row][col] = arr[row][m - col];
                else if(s == "_") temp[row][col] = arr[n - row][col];
                else if(s == "90") temp[row][col] = arr
            }
        }
    }


    for(int i = 0; i < max(n, m); i++) {
        for(int j = 0; j < max(n, m); j++) {
            if(arr[i][j] == 0) continue;
            cout << arr[i][j] << ' ';
        } cout << '\n';
    }
}

int main() {    
    ios_base::sync_with_stdio(0); cin.tie(0);
    int testCase = 1;
    cin >> testCase;
    while(testCase--) solve();
}

/*

*/