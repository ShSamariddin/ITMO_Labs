# include <bits/stdc++.h>
 
# define ll long long 
# define fr first
# define se second 
 
using namespace std;
 
pair<pair<int, int> , pair<int, int> > t[1000000] , a[200010];
 
int Mod;
 
void mul_mat(int t1, int t2, int t3){
    t[t1].fr.fr = (t[t2].fr.fr * t[t3].fr.fr + t[t2].fr.se * t[t3].se.fr) % Mod;
    t[t1].fr.se = (t[t2].fr.fr * t[t3].fr.se + t[t2].fr.se * t[t3].se.se) % Mod;
    t[t1].se.fr = (t[t2].se.fr * t[t3].fr.fr + t[t2].se.se * t[t3].se.fr) % Mod;
    t[t1].se.se = (t[t2].se.fr * t[t3].fr.se + t[t2].se.se * t[t3].se.se) % Mod;
}
 
pair<pair<int, int> , pair<int, int> > mul(pair<pair<int, int> , pair<int, int> > x , pair<pair<int, int> , pair<int, int> > y){
    pair<pair<int, int> , pair<int, int> > qu;
    /*cout <<"---------------------\n";
    cout << x.fr.fr<<' '<<x.fr.se<<'\n';
    cout<<x.se.fr<<' '<<x.se.se<<'\n';
    cout<<'\n';
    cout<<y.fr.fr<<' '<<y.fr.se<<'\n';
    cout<<y.se.fr<<' '<<y.se.se<<'\n';*/
    qu.fr.fr = (x.fr.fr * y.fr.fr + x.fr.se * y.se.fr) % Mod;
    qu.fr.se = (x.fr.fr * y.fr.se + x.fr.se * y.se.se) % Mod;
    qu.se.fr = (x.se.fr * y.fr.fr + x.se.se * y.se.fr) % Mod;
    qu.se.se = (x.se.fr * y.fr.se + x.se.se * y.se.se) % Mod;
    /*cout << qu.fr.fr<<' '<<qu.fr.se<<'\n';
    cout<<qu.se.fr<<' '<<qu.se.se<<'\n';
    cout <<"---------------------\n";*/
 
 
    return qu;
}
 
void build(int tv, int tl, int tr){
    if(tl == tr){
        t[tv] = a[tl];
        return ;
    }
    int tm = (tl + tr) / 2;
    build(tv * 2, tl, tm);
    build(tv * 2 + 1, tm  + 1, tr);
    //cout <<tv<<' '<<tl<<' '<<tr<<'\n';    
    mul_mat(tv , tv * 2 , tv * 2 + 1);
}
 
pair<pair<int, int> , pair<int, int> > ans(int tv, int tl, int tr, int l, int r){
    if(l > r){
        return make_pair(make_pair(1, 0) , make_pair(0 , 1));
    }
    if(tl == l && tr == r){
        return t[tv];
    }
    int tm = (tl + tr) / 2;
    return mul(ans(tv * 2, tl, tm, l, min(r , tm)) , ans(tv * 2 + 1, tm + 1, tr , max(l, tm + 1) , r));
}
int main()
{
    ios_base::sync_with_stdio(0);
    freopen("crypto.in" , "r" , stdin);
    freopen("crypto.out" , "w" , stdout);
    ll n, m, i , l , r;
    cin>> Mod>> n>> m;
    for(i = 1; i <= n; i++){
        cin>> a[i].fr.fr>> a[i].fr.se>> a[i].se.fr>> a[i].se.se;
    }
    build(1, 1, n);
    for(i = 1; i <= m; i ++){
        pair<pair<int, int> , pair<int, int> > an;
        cin>> l>> r;
        an = ans(1, 1, n, l, r);
        cout << an.fr.fr<<' '<<an.fr.se<<'\n';
        cout << an.se.fr<<' '<<an.se.se<<'\n';
    }
}
