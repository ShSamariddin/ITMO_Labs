# include <bits/stdc++.h>
using namespace std;
 
vector<char>  ma[200][200];
 
bool dp[170][10010];
 
void calc(int x, char ch){
    for(int i = 'A'; i <= 'Z'; i ++){
        for(char j : ma[i][ch]){
            dp[i][x] = (dp[i][x]|dp[j][x - 1]);
        }
    }
 
    for(char j : ma['-'][ch]){
        dp['-'][x] = (dp['-'][x]|dp[j][x - 1]);
    }
 
}
 
void clear(int x){
    for(int i = 0; i <= 'Z'; i ++){
        for(int j = 0; j <= x; j ++){
            dp[i][j] = false;
        }
    }
}
 
int main()
{
    freopen("automaton.in", "r", stdin);
    freopen("automaton.out", "w", stdout);
    int n, m;
    char c;
    cin>> n>> c;
    char s;
    string p, q;
    for(int i = 1; i <= n; i ++){
        cin>> s>> p>> q;
        if(q.size() == 1){
            ma['-'][q[0]].push_back(s); 
        } else{
            ma[q[1]][q[0]].push_back(s);
        }
    }
 
    cin>> m;
    string sr;
    for(int i = 1; i <= m; i ++){
        cin>> sr;
        dp[c][0] = true;
        for(int j = 0; j < sr.size(); j ++){
            char ch = sr[j];
            calc(j + 1, ch);
        }
 
        cout << (dp['-'][sr.size()] ? "yes\n" : "no\n");
        clear(sr.size());
    }
 
}
