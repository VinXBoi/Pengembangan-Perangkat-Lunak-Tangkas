#include <bits/stdc++.h>
#define INF 1000000000
#define blank ' '
#define len(x) (int) x.size()
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
vector<char> player, dealer, temp;

int checkCard(char a) {
    if(a == 'A') return 4;
    if(a == 'J') return 1;
    if(a == 'Q') return 2;
    if(a == 'K') return 3;
    return 0;
}

void solve() {
    int turn = 0;
    for(int i = 1; i < len(s); i += 3) {
        if(turn % 2 == 0) player.push_back(s[i]);
        else dealer.push_back(s[i]);
        turn++;
    }
    for(int i = 0; i < 3; i++) {
        getline(cin, s);
        for(int j = 1; j < len(s); j += 3) {
            if(turn % 2 == 0) player.push_back(s[j]);
            else dealer.push_back(s[j]);
            turn++;
        }
    }

    turn = 0;
    cout << "START\n";
    while(true) {
        if(turn % 2 == 0 && player.empty()) break;
        if(turn & 1 == 0 && dealer.empty()) break;
        char a;
        bool found = false;
        cout << "Turn : " << (turn % 2 == 0 ? "Player " : "Dealer ");
        if(turn % 2 == 0) a = *(player.end() - 1), player.pop_back();
        else a = *(dealer.end() - 1), dealer.pop_back();
        cout << a << endl;
        int take = checkCard(a);
        temp.push_back(a);

        (take ? found = true : 0);
        turn++;

        for(int i = 0; i < take; i++) {
            if(player.empty() || dealer.empty()) break;
            if(turn % 2 == 0) a = *(player.end() - 1), player.pop_back();
            else a = *(dealer.end() - 1), dealer.pop_back();
            if(checkCard(a)) i = -1, take = checkCard(a), turn++;
            temp.push_back(a);
        }
        if(found) {
            turn++;
            reverse(temp.begin(), temp.end());
            if(turn % 2 == 0) player.insert(player.begin(), temp.begin(), temp.end());
            else dealer.insert(dealer.begin(), temp.begin(), temp.end());
            temp.clear();
        }
    }
    if(len(player)) cout << 2 << ' ' << len(player) << endl;
    else cout << 1 << ' ' << len(dealer) << endl;
}

int main() {    
    ios_base::sync_with_stdio(0); cin.tie(0);
    while(getline(cin, s)) {
        if(s == "#") break;
        solve();
    }
}

/*
H1 H1 
H1 H1
H1 H1
H1 HJ

p = 4; d = 4;
p = 3; d = 3;
p = 2; d = 6;
d = 5; p = 1;
d = 4; p = 0;
d = 3; p = lose;

*/