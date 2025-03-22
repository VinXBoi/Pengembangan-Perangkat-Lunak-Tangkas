#include <bits/stdc++.h>
#define INF 1000000000
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

string s;
vector<char> player, dealer, temp;

int checkCard(char a) {
    if(a == 'A') return 1;
    if(a == 'J') return 2;
    if(a == 'Q') return 3;
    if(a == 'K') return 4;
    return 0;
}

void solve() {
    int turn = 0;
    for(int i = 1; i < (int) len(s); i += 3) {
        if(turn % 2 == 0) player.push_back(s[i]);
        else dealer.push_back(s[i]);
        turn++;
    }
    for(int i = 0; i < 3; i++) {
        getline(cin, s);
        for(int j = 1; j < (int) len(s); j += 3) {
            if(turn % 2 == 0) player.push_back(s[j]);
            else dealer.push_back(s[j]);
            turn++;
        }
    }

    turn = 0;

    while(len(player) > 0 && len(dealer) > 0) {
        char a;
        bool found = false;
        if(turn % 2 == 0) a = *(player.end() - 1), player.pop_back();
        else a = *(dealer.end() - 1), dealer.pop_back();
        
        int take = checkCard(a);
        (take ? found = true : 0);
        turn++;
        
        for(int i = 0; i < take; i++) {
            if(turn % 2 == 0) a = *(player.end() - 1), player.pop_back();
            else a = *(dealer.end() - 1), dealer.pop_back();
            if(checkCard(a)) i = 0, take = checkCard(a), turn++;
        }
        if(found) {
            if(turn % 2 == 0) player.insert(player.begin(), temp.begin(), temp.end());
            else dealer.insert(dealer.begin(), temp.begin(), temp.end());
            temp.clear()
        }
        temp.push_back(a);
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
HA H3 H4 CA SK S5 C5 S6 C4 D5 H7 HJ HQ
D4 D7 SJ DT H6 S9 CT HK C8 C9 D6 CJ C6
S8 D8 C2 S2 S3 C7 H5 DJ S4 DQ DK D9 D3
H9 DA SA CK CQ C3 HT SQ H8 S7 ST H2 D2
#
*/