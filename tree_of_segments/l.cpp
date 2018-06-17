# include <bits/stdc++.h>
  
# define ll int  
# define fr first
# define se second 
  
using namespace std;
  
set<int> st;
set<int>::iterator it;
int main()
{
        ios_base::sync_with_stdio(0);
    freopen("parking.in" , "r" , stdin);
    freopen("parking.out" , "w" , stdout);
    ll n, m , x , i;
    string s;
    cin>> n>> m;
    for(i = 1; i <= n; i ++) st.insert(i);
    for(i = 1; i <= m; i ++){
        cin>> s>> x;
        if(s == "enter"){
            it = st.find(x);
            if(it != st.end()){
                cout <<*it<<'\n';
                st.erase(x);
            } else{
                it = st.upper_bound(x);
                if(it == st.end()){
                    cout << *st.begin()<<'\n';
                    st.erase(st.begin());
                } else{
                    cout<< *it<<'\n';
                    st.erase(it);
                }
            }
        } else{
            st.insert(x);
        }
    }
}
