//RAiNcalleER
#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
void setIO(string name=""){
   ios_base::sync_with_stdio(0); cin.tie(0);
   if((int)name.size() > 0){freopen((name+".in").c_str(), "r", stdin); freopen((name+".out").c_str(), "w", stdout);}
}

#define f first
#define s second
#define all(x) (x).begin(), (x).end()
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};

//-------------------# Long, long had been my road and far, far was the journey; #---------------------
//-----------------------# I would go up and down to seek my heart's desire. #---------------------


int n, m; 
bool complete = false;
bool vis[1001][1001];
map<int, vector<pair<int, int>>> mp;
bool valid (int x, int y){
    return x <= n,
}
void check(int a, int b) {
    //cout << a<<' '<<b<< endl;
    if (a == 1 && b == 1){
        complete = true; return;
    }
    vis[a*b] = true;
    for (auto p : mp[a * b]) {
        if(vis[a*b] == false && valid(p.first)){
            check(p.first, p.second);
        }
    }
}
int main()
{
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int t; cin >> t;
            mp[t].push_back({i,j});
        }
    }
    check(m, n);
    if (!complete)
        cout << "no";
    else 
        cout << "yes";
    return 0;
}
 
/*
stuff you should look for
int overflow, array bounds
special cases (n=1?)
do smth instead of nothing and stay organized
WRITE STUFF DOWN
DON'T GET STUCK ON ONE APPROACH
1. Think Greedy
2. Think Brute Force
3. Think solution in reverse order
4. Think DP [ check constraints carefully ]
5. Check base cases for DP and prove solution for Greedy
6. Think Graph
*/