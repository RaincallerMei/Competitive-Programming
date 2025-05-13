//RAiNcalleER
#include <bits/stdc++.h>
using namespace std;
 
//feels good to be home
 
using ll = long long;
 
void setIO(string name=""){
  ios_base::sync_with_stdio(0); cin.tie(0);
  if((int)name.size() > 0){freopen((name+".in").c_str(), "r", stdin); freopen((name+".out").c_str(), "w", stdout);}
}

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define all(x) (x).begin(), (x).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};

//-------------------# Long, long had been my road and far, far was the journey; #---------------------
//-----------------------# I would go up and down to seek my heart's desire. #---------------------
/*
1. Think Greedy
2. Think Brute Force
3. Think solution in reverse order
4. Think DP [ check constraints carefully ]
5. Check base cases for DP and prove solution for Greedy
6. Think Graph
*/


void solve(){
    int n,m; 
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    for(int i=0; i<m; i++){
        int a,b; 
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    int x, y, temp;
    vector<int>nono(n+1, 0);
    for(int i=1; i<=n; i++){
        if(adj[i].size() == 1){
            nono[i] = 1;
            temp = adj[i][0];
            //cout<<i<<" "<<temp<<"\n";
        }
    }
    for(int i: adj[temp]){
        if(nono[i] == 0){
            x = adj[i].size();
            y = adj[temp].size() - 1;
            break;
        }
    }
    cout<<x<<" "<<y<<"\n";
}
int main(){
    setIO("");
    int t; cin >> t; while(t--)
    solve();
    return 0;
}
 
/*
stuff you should look for
int overflow, array bounds
special cases (n=1?)
do smth instead of nothing and stay organized
WRITE STUFF DOWN
DON'T GET STUCK ON ONE APPROACH
*/