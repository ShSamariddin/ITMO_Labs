# include <bits/stdc++.h>
using namespace std;
 
vector<pair<int, int> >  v[200000];
queue<char> q;
int us[200000], kol[200000], used[100010];
string s[200010];
char p[200010];
 
int main()
{
    freopen("epsilon.in", "r", stdin);
    freopen("epsilon.out", "w", stdout);
    int n, m, k = 0;
    char c;
    cin>> n>> c;
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
        if(s[i].size() == 0 && us[p[i]] == 0){
            us[p[i]] = 1;
            q.push(p[i]);
        }
        for(int j = 0; j < s[i].size(); j ++){
            if(s[i][j] >= 'A' && s[i][j] <= 'Z'){
                v[s[i][j]].push_back(make_pair(i, j));
            }
        }
    }
 
    while(!q.empty()){
        char st = q.front();
        q.pop();
        //cout << st<<'\n';
        for(pair<int, int> i : v[st]){
            if(s[i.first][i.second] != '#'){
                s[i.first][i.second] = '#';
                kol[i.first]++;
                if(kol[i.first] == s[i.first].size() && us[p[i.first]] == 0){
                    us[p[i.first]] = 1;
                    q.push(p[i.first]);
                }
            }
        }
    }
    int q = 0;
    for(char i = 'A'; i <= 'Z'; i ++){
        if(us[i] == 1){
            if(q){
                cout <<' ';
            }
            q = 1;
            cout <<i;
        }
    }
 
 
 
}
