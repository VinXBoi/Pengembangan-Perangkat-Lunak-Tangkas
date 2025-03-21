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
stack<char> player;
stack<char> dealer;
stack<char> temp;

void solve() {
    int idx = 0;
    for(int i = 1; i < (int) len(s); i += 3) {
        if(idx % 2 == 0) player.push(s[i]);
        else dealer.push(s[i]);
        idx++;
    }
    for(int i = 0; i < 3; i++) {
        getline(cin, s);
        for(int j = 1; j < (int) len(s); j += 3) {
            if(idx % 2 == 0) player.push(s[j]);
            else dealer.push(s[j]);
            idx++;
        }
    }

    idx = 0;

    while(len(player) > 0 && len(dealer) > 0) {
        char a;
        if(idx % 2 == 0) a = player.top(), player.pop();
        else a = dealer.top(), dealer.pop();
        
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