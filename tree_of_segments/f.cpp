# include <bits/stdc++.h>
  
# define ll int  
# define fr first
# define se second 
  
using namespace std;
 
int dp[200010][23], p[100010];
 
int ans(int l, int r){
    int t = p[(r- l)];
    return min(dp[l][t], dp[r - (1<< t) + 1][t]);
}
  
int main()
{
    ios_base::sync_with_stdio(0);
    freopen("sparse.in" , "r" , stdin);
    freopen("sparse.out" , "w" , stdout);
    ll n, j, i, m;
    cin>> n>> m>> dp[1][0];
    for(i = 2; i <= n; i ++){
        dp[i][0] = (23 * dp[i - 1][0] + 21563) % 16714589;
    }
    for(j = 1; (1<<j) <= n; j ++){
        for(i = 1; i <= n; i ++){
            dp[i][j] = min(dp[i][j - 1], dp[i + (1<<j - 1)][j - 1]);
        } 
    }
     
    int q = 1 , k = 0;
    for(i = 0; i <= n; i ++){
        if(q * 2 <= i){
            q *= 2;
            k++;
        }
        p[i] = k;
    }
    int u, v;   
    cin>> u>> v;
    int an = ans(min(u, v) , max(u, v));
     
    for(i = 1; i <  m; i ++){
        u = (17 * u + 751 + an + i * 2) % n + 1;
        v = (13 * v + 593 + an + 5 * i) % n + 1;
      //  cout << u<<' '<<v<<
        if(u > v){
            an = ans(v, u);
           /* an = 16714589;
            for(int i1 = min(u , v); i1 <= max(u, v); i1 ++){
                an = min(an , dp[i1][0]);
            }*/
        } else{
            an = ans(u, v);
            /*an = 16714589;
            for(int i1 = min(u , v); i1 <= max(u, v); i1 ++){
                an = min(an , dp[i1][0]);
            }*/
        }
    }
    cout <<u<<' '<<v<<' '<<an<<'\n';
}
