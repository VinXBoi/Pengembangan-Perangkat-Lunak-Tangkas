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
typedef vector<vi> vvi;

void solve() {
    int n, m, x; cin >> n >> m >> x;
    int size = max(n, m);
    vector<vector<int>> arr(size, vector<int> (size, 0));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < x; i++) {
        vvi temp(size, vi(size, 0));
        string s; cin >> s;
        if(s == "90" || s == "270") swap(n, m);
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < m; col++) {
                if(s == "|") temp[row][col] = arr[row][m - col - 1];
                else if(s == "_") temp[row][col] = arr[n - row - 1][col];
                else if(s == "90") temp[row][col] = arr[m - col - 1][row];
                else if(s == "180") temp[row][col] = arr[n - row - 1][m - col - 1];
                else if(s == "270") temp[row][col] = arr[col][n - row - 1];
            }
        }

        arr = temp;
    }
    
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if(arr[i][j] == 0) continue;
            cout << arr[i][j] << ' ';
        } cout << '\n';
    }
}

int main() {    
    ios_base::sync_with_stdio(0); cin.tie(0);
    int testCase = 1;
    // cin >> testCase;
    while(testCase--) solve();
}

/*
3 2
1 2
3 4
5 6

_
5 6 
3 4
1 2

|
2 1
4 3
6 5

90
5 3 1
2 4 6

180
6 5
4 3
2 1

270
2 4 6
1 3 5
*/