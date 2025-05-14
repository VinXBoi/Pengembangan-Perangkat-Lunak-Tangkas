#include <bits/stdc++.h>
#define mod 1007
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
    string s; getline(cin, s);
    stack<char> bracket;
    stack<int> num;
    stack<char> op;
    bool first = true;
    int ans = 0;
    if(isdigit(s[0])) {
        cout << s << endl;
        return;
    }

    for(int i = 0; i < len(s); i++) {
        if(s[i] == ' ') continue;

        if(s[i] == ')') {
            if(first) {
                first = false;
                ans = num.top();
                num.pop();
            }
            if(op.top() == '+') {
                ans += num.top();
            } else {
                ans -= num.top();
            }
            num.pop();

            
        }
        
        if(isdigit(s[i]) || (s[i] == '-' && isdigit(s[i + 1]))) {
            bool check = false;
            if(s[i] == '-') {
                check = true;
                i++;
            }
            int tmp = 0;
            while(isdigit(s[i])) {
                tmp = tmp * 10 + (s[i] - '0');
                i++;
            }
            i--;
             
            if(check) {num.push(-tmp);
            }
            else {num.push(tmp);}
        }
        
        if(s[i] == '+' || s[i] == '-') op.push(s[i]);
    }
    cout << ans << endl;
}

int main() {    
    ios_base::sync_with_stdio(0); cin.tie(0);
    int testCase = 1;
    // cin >> testCase;
    while(testCase--) solve();
}

/*
Input : (+ 1 (+ (+ (+ 3 4) -2) 5))
Output : 11

*/ 