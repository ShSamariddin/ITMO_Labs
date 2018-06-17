# include <bits/stdc++.h>
  
# define ll long long   
# define fr first
# define se second 
  
using namespace std;
 
long long answ;
long long  mx, mn;
  
pair<long long, pair<ll, ll> > t[4000000];
long long  p[4000010], a[4000010];
 
void build(ll tv, ll tl, ll tr){
    if(tl == tr){
        t[tv].fr = a[tl] * a[tl];
        t[tv].se.fr = a[tl];
        t[tv].se.se = a[tl];
        return ;
    }
    ll tm = (tl + tr) / 2;
    build(tv * 2, tl, tm);
    build(tv * 2 + 1, tm + 1, tr);
    t[tv].fr = t[tv * 2].fr + t[tv * 2 + 1].fr;
    t[tv].se.fr = min(t[tv * 2].se.fr , t[tv * 2 + 1].se.fr);
    t[tv].se.se = max(t[tv * 2].se.se , t[tv * 2 + 1].se.se);
}
 
void iz(ll tv, ll tl, ll tr, ll l, ll r, long long x){
    if(l > r) return ;
    if(tl == l && tr == r){
        t[tv].fr = x * x;
        t[tv].se.fr = x;
        t[tv].se.se = x;
        return ;
    }
 
    ll tm = (tl + tr) / 2;
    iz(tv * 2, tl, tm, l, min(r, tm) , x);
    iz(tv * 2 + 1, tm + 1, tr, max(l, tm + 1) , r , x);
    t[tv].fr = t[tv * 2].fr + t[tv * 2 + 1].fr;
    t[tv].se.fr = min(t[tv * 2].se.fr , t[tv * 2 + 1].se.fr);
    t[tv].se.se = max(t[tv * 2].se.se , t[tv * 2 + 1].se.se);
}
 
void ans(ll tv, ll tl, ll tr, ll l, ll r){
    if(l > r) return ;
    if(tl == l && tr == r){
        answ += t[tv].fr;
        mn = min(mn, t[tv].se.fr);
        mx = max(mx, t[tv].se.se);
        return ;
    }
 
    ll tm = (tl + tr) / 2;
    ans(tv * 2, tl, tm, l, min(tm, r));
    ans(tv * 2 + 1, tm + 1, tr , max(tm + 1, l) , r);
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    freopen("permutation.in", "r", stdin);
    freopen("permutation.out", "w", stdout);
    ll n, i, l, r, t, m;
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> a[i];
    }
    build(1, 1, n);
 
    for(i = 1; i <= n; i++){
        p[i] = p[i - 1] + i * i;
    }
 
 
    cin>> m;
    for(i = 1; i <= m; i ++){
        cin>> t>> l>> r;
        if(t == 1){
            iz(1, 1, n, l, l, r);
        } else{
            answ = 0;
            mn = n + 10;
            mx = 0;
            ans(1, 1, n, l, r);
            if(mx <= (r - l + 1) && answ == p[r - l + 1] && mn == 1){
                cout<<"YES\n";
            }else{
                cout<<"NO\n";
            }
        }
    }
}
