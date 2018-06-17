# include <bits/stdc++.h>
  
# define ll int  
# define fr first
# define se second 
  
using namespace std;
 
pair<int, int>  t[6000100];
int p[6000010];
 
void build(int tv, int tl, int tr){
    if(tl == tr){
        t[tv] = make_pair(0 , tl);
        return ;
    }
     
    int tm = (tl + tr) / 2;
    build(tv * 2, tl, tm);
    build(tv * 2 + 1, tm + 1, tr);
    t[tv] = t[tv * 2];
}
 
void push(int tv){
    if(p[tv] == 0){
        return;
    }
    t[tv].fr = max(t[tv].fr , p[tv]);
    p[tv * 2] = max(p[tv], p[tv * 2]);
    p[tv * 2 + 1] = max(p[tv], p[tv * 2 + 1]);
    p[tv] = 0;
}
 
void iz(int tv, int tl, int tr, int l, int r, int x){
    push(tv);
    if(l > r) return;
    if(tl == l && tr == r){
        p[tv] = max(p[tv] , x);
        push(tv);
        return ;
    }
 
    int tm = (tl + tr) / 2;
    iz(tv * 2, tl , tm, l , min(tm, r), x);
    iz(tv * 2 + 1, tm + 1, tr, max(l, tm + 1) , r , x);
    if(t[tv * 2].fr < t[tv * 2 + 1].fr){
        t[tv] = t[tv * 2];
    } else{
        t[tv] = t[tv * 2 + 1];
    }
}
 
int ans(int tv, int tl, int tr, int l, int r){
    push(tv);
    if(l > r) return -1;
    if(tl == l && tr == r){
        return tv;
    }
    int tm = (tl + tr) / 2;
 
    int f = ans(tv * 2, tl , tm , l , min(r, tm));
    int s = ans(tv * 2 + 1, tm + 1, tr, max(tm + 1, l), r);
    if(s == -1){
        return f;
    } 
    if(f == -1)
    {
        return s;
    }
    if(t[f].fr > t[s].fr){
        return s;
    } else{
        return f;
    }
 
}   
  
int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("sparse.in" , "r" , stdin);
    //freopen("sparse.out" , "w" , stdout);
    ll n, m, i, l, r, x;
    string s;
    cin>> n>> m;
    build(1, 1, n);
    for(i = 1; i <= m; i ++){
        cin>> s;
        if(s == "defend"){
            cin>> l>> r>> x;
            iz(1, 1, n, l, r, x);
        } else{
            cin>> l>> r;
            int tv = ans(1, 1, n, l, r);
            cout << t[tv].fr<<' '<<t[tv].se<<'\n';
        }
    }
 
}
