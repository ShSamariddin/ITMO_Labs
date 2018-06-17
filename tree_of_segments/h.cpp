# include <bits/stdc++.h>
   
# define ll long long 
   
using namespace std;
  
ll MIN = -(1ll<<31) - 110;
ll MAX = (1ll<<31) + 100;
  
ll t[1000100], p[1000100], a[1000100];
  
void build(int tv, int tl, int tr){
    p[tv] = MIN;
    if(tl == tr){
        t[tv] = MIN;
        return ;
    }
    int tm = (tl + tr) / 2;
    build(tv * 2, tl, tm);
    build(tv * 2 + 1, tm + 1, tr);
    t[tv] = max(t[tv * 2], t[tv * 2 + 1]);
}
void push(int tv){
    if(p[tv] == MIN){
        return ;
    }
    t[tv] = max(t[tv] , p[tv]);
    p[tv * 2] = max(p[tv * 2], p[tv]);
    p[tv * 2 + 1] = max(p[tv], p[tv * 2 + 1]);
    p[tv] = MIN;
}
void iz(int tv, int tl, int tr, int l, int r, ll x){
    push(tv);
    if(l > r) return ;
    if(tl == l && tr == r){
        p[tv] = max(p[tv] , x);
 
        push(tv);
        return ;
    }
    int tm = (tl + tr) / 2;
    iz(tv * 2, tl, tm, l, min(r, tm) , x);
    iz(tv * 2 + 1, tm + 1, tr, max(l, tm + 1), r, x);
    t[tv] = max(t[tv * 2], t[tv * 2 + 1]);
}
  
ll  ans(int tv, int tl, int tr, int l, int r){
    //cout <<tl<<' '<<tr<<' '<<l<<' '<<r<<'\n';
    push(tv);   
    if(l > r) return MIN;
    if(tl == l && tr == r){
        return t[tv];
    }
    int tm = (tl + tr) / 2;
    return max(ans(tv * 2, tl , tm, l, min(tm, r)), ans(tv * 2 + 1, tm + 1, tr, max(tm + 1, l) , r));
}
void newbuild(int tv, int tl, int tr){
    if(tl == tr){
        t[tv] = a[tl];
        return ;
    }
    int tm = (tl + tr) / 2;
    newbuild(tv * 2, tl, tm);
    newbuild(tv * 2 + 1, tm + 1, tr);
    t[tv] = min(t[tv * 2], t[tv * 2 + 1]);
    //cout << tl<<' '<<tr<<' '<<t[tv]<<'\n';
}
  
ll newans(int tv, int tl, int tr, int l, int r){
    if(l > r) return MAX;
    if(tl == l && tr == r){
        return t[tv]; 
    }
    int tm = (tl + tr) / 2;
    return min(newans(tv * 2, tl, tm, l , min(tm , r)), newans(tv * 2 + 1, tm + 1, tr, max(l, tm + 1) , r));
}
ll l[100010], r[100010], x[100010];
int main()
{
    ios_base::sync_with_stdio(0);
    freopen("rmq.in", "r", stdin);
    freopen("rmq.out", "w", stdout);
    ll n, m, i;
    cin>> n>> m;
    build(1, 1, n);
    for(i = 1; i <= m; i ++){
        cin>> l[i]>> r[i]>> x[i];
        iz(1, 1, n, l[i], r[i], x[i]);
    }
    for(i = 1; i <= n; i ++){
        a[i] = ans(1, 1, n, i, i);
        //cout << a[i]<<' ';
    }
    newbuild(1, 1, n);
  
    for(i = 1; i <= m; i ++){
        //cout <<newans(1, 1, n, l[i], r[i])<<' '<<x[i]<<'\n';
        if(newans(1, 1, n, l[i], r[i]) != x[i])
        {
            cout <<"inconsistent";
            return 0;
        }
    }
    cout <<"consistent\n";
    for(i = 1; i <= n; i ++){
        if(a[i] == MIN){
            cout<<0<<' ';
        } else{
            cout << a[i]<<' ';
        }
  
    }
}
