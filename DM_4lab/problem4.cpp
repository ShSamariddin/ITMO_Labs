# include <bits/stdc++.h>
# define MOD 1000000007ll
using namespace std;
 
string s[1100], p[1100], tt;
long long dp[310][310][300];
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("nfc.in", "r", stdin);
    freopen("nfc.out", "w", stdout);
    long long  n, i, j, g;
    string str;
    char c;
    cin>> n>> c;
    for(i = 1; i <= n; i ++){
        cin>> s[i]>> tt>> p[i];
    }
 
    cin>> str;
 
    for(i = 0; i < str.size(); i ++){
        for(j = 1; j <= n; j ++){
            if(p[j].size() == 1 && str[i] == p[j][0]){
                dp[i][i][s[j][0]] ++;
            }
        }
    }
 
    for(i = 1; i < str.size(); i ++){
        for(j = 0; j < str.size() - i; j ++){
            for(g = 1; g <= n; g ++){
                if(p[g].size() == 2){
                    for(int t = j; t < j + i; t ++){
                        dp[j][i + j][s[g][0]] += dp[j][t][p[g][0]] * dp[t + 1][j + i][p[g][1]];
                        dp[j][i + j][s[g][0]] %= MOD;
                    }
                }
            }
        }
    }
 
    cout << dp[0][str.size() - 1][c];
 
}
