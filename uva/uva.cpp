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

int checkCard(char a) {
    if(a == 'A') return 4;
    if(a == 'J') return 1;
    if(a == 'Q') return 2;
    if(a == 'K') return 3;
    return 0;
}

void solve() {
    deque<char> player, dealer, heap;
    int turn = 0;
    for(int i = 1; i < len(s); i += 3) {
        if(turn % 2 == 0) player.push_back(s[i]);
        else dealer.push_back(s[i]);
        turn++;
    };
    for(int i = 0; i < 3; i++) {
        getline(cin, s);
        for(int j = 1; j < len(s); j += 3) {
            if(turn % 2 == 0) player.push_back(s[j]);
            else dealer.push_back(s[j]);
            turn++;
        }
    }

    turn = 0;
    bool gameWon = false;
    while(!gameWon) {
        int winner;
        char a;
        if(heap.empty() || heap.back() == 0) {
            if(turn % 2 == 0) {
                if(player.empty()) {
                    gameWon = true;
                    break;
                }
                a = player.back(); player.pop_back();
            } else {
                if(dealer.empty()) {
                    gameWon = true;
                    break;
                }
                a = dealer.back(); dealer.pop_back();
            }
            if(checkCard(a)) winner = turn % 2;
            heap.push_back(a);
        } else {
            if(turn % 2 == 0) {
                int penalty = checkCard(heap.back());
                for(int i = 0; i < penalty; i++) {
                    if(player.empty()) {
                        gameWon = true;
                        break;
                    }
                    a = player.back(); player.pop_back();
                    heap.push_back(a);
                    if(checkCard(a)) {winner = turn % 2; break;}
                }
                if(!gameWon && turn != winner) {
                    while(!heap.empty()) {
                        player.push_front(heap.front());
                        heap.pop_front();
                    }
                }
            } else {
                int penalty = checkCard(heap.back());
                for(int i = 0; i < penalty; i++) {
                    if(dealer.empty()) {
                        gameWon = true;
                        break;
                    }
                    a = dealer.back(); dealer.pop_back();
                    heap.push_back(a);
                    if(checkCard(a)) {winner = turn % 2; break;}
                }   
                if(!gameWon && turn != winner) {
                    while(!heap.empty()) {
                        dealer.push_front(heap.front());
                        heap.pop_front();
                    }
                }             
            }
        } turn++;
    }
    if(len(player)) cout << 2 << ' ' << len(player);
    else cout << 1 << ' ' << len(dealer);
}

int main() {    
    ios_base::sync_with_stdio(0); cin.tie(0);
    int testCase = 1;
    while(getline(cin, s)) {
        if(s == "#") break;
        if(testCase >= 2) cout << endl;
        testCase++;
        solve();
    }
}

/*
HA H3 H4 CA SK S5 C5 S6 C4 D5 H7 HJ HQ
D4 D7 SJ DT H6 S9 CT HK C8 C9 D6 CJ C6
S8 D8 C2 S2 S3 C7 H5 DJ S4 DQ DK D9 D3
H9 DA SA CK CQ C3 HT SQ H8 S7 ST H2 D2
HA H3 H4 CA SK S5 C5 S6 C4 D5 H7 HJ HQ
D4 D7 SJ DT H6 S9 CT HK C8 C9 D6 CJ C6
S8 D8 C2 S2 S3 C7 H5 DJ S4 DQ DK D9 D3
H9 DA SA CK CQ C3 HT SQ H8 S7 ST H2 D2
#
*/

