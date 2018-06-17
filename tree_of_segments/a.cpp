# include <bits/stdc++.h>
 
# define ll long long 
 
using namespace std;
 
int a[10000010] , b[20000010] , n; 
int main()
{
    freopen("sum0.in" , "r" , stdin);
    freopen("sum0.out" , "w" , stdout);
    ll m , x , y , ans = 0 , i;
    cin>> n>> x>> y >> a[0];
    for(i = 1; i <= n; i ++){
        a[i] =  (x * a[i - 1] + y) % (1<<16);
    }
    for(i = 1; i <= n; i ++){
        a[i] += a[i - 1];
    }
     
    cin>> m>> x >> y>> b[0];
    for(i = 1; i < 2 * m; i ++){
        b[i] = (x * b[i - 1] + y) % (1<<30);
        b[i] += (1<< 30);
        b[i] %= (1 << 30);
    }
    for(i = 0; i < 2 * m; i ++){
        b[i] %= n;
    }
 
    for(i = 0; i < 2 * m; i += 2){
        x = min(b[i] , b[i + 1]) , y = max(b[i], b[i + 1]);
        if(x == 0){
            ans += a[y];
        } else{
            ans += (a[y] - a[x - 1]);
        }
    }
    cout << ans;
}
