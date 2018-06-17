# include <bits/stdc++.h>
 
# define ll int  
# define fr first 
# define se second
 
using namespace std;
 
multiset<pair<ll, ll> > st;
multiset<pair<ll, ll> >:: iterator it;
 
 
int main()
{
    ios_base::sync_with_stdio(0);
    freopen("painter.in" , "r" , stdin);
    freopen("painter.out" , "w" , stdout);
    ll n , x , y , i , ans = 0;
    char c;
    cin>> n;
    for(i = 1; i <= n; i ++){
        cin>> c>> x>> y;
        y += x;
        if(c == 'W'){
            st.insert(make_pair(x, y));
            it = st.find(make_pair(x, y));
            if(it != st.begin()){
                it--;
                int l = it->fr , r = it->se;
                if(it->se >= x){
                    st.erase(it);
                    ans -= (r - l);
                    if(x - 1 >= l){
                        ans += (x - l);
                        st.insert(make_pair(l , x));
                    }
                }
                if(r > y){
                    ans += (r - y);
                    st.insert(make_pair(y , r));
                }
            }
            it = st.find(make_pair(x, y));
            it++;
            while(it != st.end()){
                int l = it->fr , r = it->se;
                if(r <= y){
                    ans -= (r - l);
                    st.erase(it);
                } else{
                    if(x <= l && y >= l){
                        st.erase(it);
                        ans -= (r - l);
                        st.insert(make_pair(y , r));
                        ans += (r - y);
                    }
                    break;
                }
                it = st.find(make_pair(x, y));
                it++;
            }
            st.erase(make_pair(x , y));
        } else{
            int x1 = x , y1 = y;
            st.insert(make_pair(x, y));
            it = st.find(make_pair(x, y));
            if(it != st.begin()){
                it--;
                if(it->se >= x){
                    x1 = it->fr;
                    y1 = max(it->se , y);
                    ans -= (it->se - it->fr);
                    st.erase(it);
                }
            }
            it = st.find(make_pair(x, y));
            it++;
            while(it != st.end()){
                int l = it->fr , r = it->se;
                if(r <= y1){
                    st.erase(it);
                    ans -= (r - l);
                } else{
                    if(x <= l && y >= l){
                        st.erase(it);
                        ans -= (r - l);
                        y1 = max(y1 , r);
                    }
                    break;
                }
                it = st.find(make_pair(x, y));
                it++;
            }
            st.erase(make_pair(x , y));
            st.insert(make_pair(x1 , y1));
            ans += (y1 - x1);
        }
        /*for(it = st.begin(); it != st.end(); it ++){
            cout << it->fr<<' '<<it->se<<'\n';
        }*/
        cout << st.size()<<' '<<ans<<'\n';
    }
}
