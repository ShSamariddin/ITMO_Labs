# include <bits/stdc++.h>
using namespace std;
 
vector<pair<int, int> >  v[200000];
vector<pair<int, char> > g[100010];
queue<char> q;
int us[200000], used[100010], check[200010];
bool here[200100];
int kol[200000];
string s[200010];
char p[200010];
 
void dfs(char x){
 
    check[x] = 1;
 
    for(pair<int, char> i : g[x]){
        if(check[i.second] == 0 && kol[i.first] == 0){
            dfs(i.second);
        }
    }
 
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("useless.out", "w", stdout);
    freopen("useless.in", "r", stdin);
    int n, m, k = 0;
    char c;
    cin>> n>> c;
    here[c] = true;
    while(cin>> s[++k]){}
    k--;
    n = k;
    for(int i = 1; i <= n ;i ++){
        if(s[i] == "->"){
            used[i - 1] = 1;
            used[i] = -1;
        }
    }
 
    for(int i = 1; i <= n; i ++){
        if(used[i] == 0){
            used[i - 2] = 2;
        }
    }
    k = 0;
    for(int i = 1; i <= n; i ++){
        if(used[i] == 1){
            k++;
            p[k] = s[i][0]; 
            s[k] = "";
        } else if(used[i]  == 2){
            k++;
            p[k] = s[i][0];
            s[k] = s[i + 2];
        }
    }
 
    n = k;
 
    for(int i = 1; i <= n; i ++){
        bool good = false;
 
 
        here[p[i]] = true;
        for(int j = 0; j < s[i].size(); j ++){
            if(s[i][j] >= 'A' && s[i][j] <= 'Z'){
                here[s[i][j]] = true;
                g[p[i]].push_back(make_pair(i, s[i][j]));
                good = true;
                kol[i] ++;
                v[s[i][j]].push_back(make_pair(i, j));
            }
        }
        if(!good){
            us[p[i]] = 1;
            q.push(p[i]);
        }
    }
    while(!q.empty()){
        char st = q.front();
        q.pop();
        //cout << st<<'\n';
        for(pair<int, int> i : v[st]){
            if(s[i.first][i.second] != '#'){
                s[i.first][i.second] = '#';
                kol[i.first]--;
                if(kol[i.first] == 0 && !us[p[i.first]]){
                    us[p[i.first]] = 1;
                    q.push(p[i.first]);
                }
            }
        }
    }
    
    dfs(c);
 
 
    for(char i = 'A'; i <= 'Z'; i ++){
        if(check[i] == 0 && here[i]){
            us[i] = 0;
        }
    }
 
    for(char i = 'A'; i <= 'Z'; i ++){
        if(us[i] == 0 && here[i]){
            cout << i<<' ';
        }
    }
 
}
