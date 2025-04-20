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
vvi arr(30, vi(30, -1));
vvi arrB(30, vi(30, -1));

int m, n;

int turn(int x, int y, int temp) {
    if(x < 1 || x > m || y < 1 || y > n || arr[x][y] == 0 || arr[x][y] != temp) return 0;

    int cnt = 1;
    arr[x][y] = 0;
    cnt += turn(x + 1, y, temp);
    cnt += turn(x - 1, y, temp);    
    cnt += turn(x, y + 1, temp);
    cnt += turn(x, y - 1, temp);

    return cnt;
}

void fall() {
    for (int j = 1; j <= n; j++) { 
        int fill_pos = m; 
        for (int i = m; i >= 1; i--) {
            if (arr[i][j] > 0) {
                arr[fill_pos][j] = arr[i][j];
                if (fill_pos != i) arr[i][j] = 0; 
                fill_pos--;
            }
        }
        for (int i = fill_pos; i >= 1; i--) {
            arr[i][j] = -1;
        }
    }
}

void turnZero(int x, int y, int temp) {
    if(x < 1 || x > m || y < 1 || y > n) return;
    arr[x][y] = 0;
    if(arr[x + 1][y] == temp) turnZero(x + 1, y, temp);
    if(arr[x - 1][y] == temp) turnZero(x - 1, y, temp);
    if(arr[x][y + 1] == temp) turnZero(x, y + 1, temp);
    if(arr[x][y - 1] == temp) turnZero(x, y - 1, temp);
}

void solve() {
    cin >> m >> n;
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }
    int ans = -1;
    int x, y, temp;
    for(int turn = 0; turn < 2; turn++) {
        ans = -1;
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(arr[x][y] == 0) continue;
                temp = turn(i, j, arr[i][j]);
                ans = max(ans, temp);
            }
        }
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