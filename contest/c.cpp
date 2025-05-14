#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAXN = 1000;

int h, w;
vector<vector<char>> grid(MAXN, vector<char>(MAXN));
vector<vector<int>> dist(MAXN, vector<int>(MAXN, INF));
vector<vector<char>> dir(MAXN, vector<char>(MAXN));


const vector<tuple<int, int, char>> directions = {
    {-1, 0, 'v'},
    {1, 0, '^'},
    {0, -1, '>'},
    {0, 1, '<'}
};

void solve() {
    cin >> h >> w;

    queue<pair<int, int>> q;

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'E') {
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (auto [dx, dy, arrow] : directions) {
            int nx = x + dx, ny = y + dy;
            if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
            if (grid[nx][ny] != '.') continue;
            if (dist[nx][ny] != INF) continue;

            dist[nx][ny] = dist[x][y] + 1;
            dir[nx][ny] = arrow;
            q.push({nx, ny});
        }
    }

    // Fill in arrows
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (grid[i][j] == '.') {
                grid[i][j] = dir[i][j];
            }
        }
    }

    // Output the modified grid
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cout << grid[i][j];
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
