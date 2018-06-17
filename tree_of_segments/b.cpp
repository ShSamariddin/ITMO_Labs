# include <bits/stdc++.h>
 
# define ll long long 
 
using namespace std;
ll f[500010] , n , a[500010];
void add(int i , int x){
    int j = i;
    while(j <= n){
        f[j] += x;
        j = j|(j + 1);
    }
}
ll sum(int r){
    int i = r;//sum += a[i] где i от 0 ... i
    ll s = 0;
    while(i > 0){
        s += f[i];
        i = (i & (i + 1)) - 1;
    }
    return s;
}
int main()
{
    ios_base::sync_with_stdio(0);
    freopen("rsq.in" , "r" , stdin);
    freopen("rsq.out" , "w" , stdout);
    int x , y , c , m;
    string s;
    cin>> n;
    for(int i = 1; i <= n; i ++){
        cin>> a[i];
        add(i , a[i]);
    }
    while(cin>> s){
        cin>> x >> y;
        if(s == "sum"){
            cout << sum(y) - sum(x - 1)<<'\n';
        } else{
            add(x , y - a[x]);
            a[x] = y;
        }
    }
}
