# include <bits/stdc++.h>
 
# define ll long long 
# define se second
# define fr first
 
using namespace std;
ll t[500010], a[100010];
pair<ll, ll> p[500000];
void build(ll tv, ll tl, ll tr){
    p[tv] = make_pair(-1, 0);
    if(tl == tr){
        t[tv] = a[tl];
        return;
    }
    ll tm = (tl + tr) / 2;
    t[tv * 2] = 1000000000000000000;
    t[tv * 2 + 1] = 1000000000000000000; 
    build(tv * 2 , tl , tm);
    build(tv * 2 + 1, tm + 1 , tr);
    t[tv] = min(t[tv * 2], t[tv * 2 + 1]);
    //cout <<tl<<' '<<tr<<' '<<t[tv]<<'\n';
}
 
void push(ll tv, ll tl, ll tr){
    if(p[tv].fr == -1){
        return ;
    }
    if(p[tv].fr == 1){
        t[tv] = p[tv].se;
    } else{
        t[tv] += p[tv].se;
    } 
    if(p[tv].fr == 1){
        p[tv * 2] = make_pair(p[tv].fr, p[tv].se);
        p[tv * 2 + 1] = make_pair(p[tv].fr, p[tv].se);
    } else{
        ll x1 = 2 , x2 = 2;
        if(p[tv * 2].fr == 1)
            x1 = 1;
        if(p[tv * 2 + 1].fr == 1)
            x2 = 1;
        p[tv * 2] = make_pair(x1, p[tv * 2].se + p[tv].se);
        p[tv * 2 + 1] = make_pair(x2, p[tv * 2 + 1].se + p[tv].se);
    }
    p[tv] = make_pair(-1, 0);
}
 
void change(ll tv, ll tl, ll tr, ll l, ll r, ll type, ll mi){
    push(tv, tl, tr);
    if(l > r) return ;
    if(tl == l && tr == r){
        p[tv] = make_pair(type , mi);
        push(tv, tl, tr);
        return;
    }   
    ll tm = (tl + tr) / 2;
    change(tv * 2, tl, tm, l, min(r, tm), type, mi);
    change(tv * 2 + 1, tm + 1, tr, max(l , tm + 1), r, type, mi);
    t[tv] = min(t[tv * 2], t[tv * 2 + 1]);
}
 
ll ans(ll tv, ll tl, ll tr, ll l, ll r){
    push(tv, tl, tr);
    if(l > r){
        return 1000000000000000000;
    }
    if(tl == l && tr == r){
        return t[tv];
    }
    ll tm = (tl + tr) / 2;
    return min(ans(tv * 2, tl, tm, l, min(tm, r)) , ans(tv * 2 + 1, tm + 1, tr, max(tm + 1, l) , r));
}   
int main()
{
    ios_base::sync_with_stdio(0);
    freopen("rmq2.in" , "r" , stdin);
    freopen("rmq2.out" , "w" , stdout);
    ll  n, i, l, r;
    ll x;
    string s;
    cin>> n;
    for(i = 1; i <= n; i ++){
        cin>> a[i];
    }
    build(1, 1, n);
    while(cin>> s){
        cin>> l>> r;
        if(s == "min"){
            cout << ans(1, 1, n, l, r)<<'\n';
        } else if(s == "set") {
            cin>> x;
            change(1, 1, n, l, r, 1, x);
        } else if(s == "add") {
            cin>> x;
            change(1, 1, n, l, r, 2, x);
        }
    }
}
