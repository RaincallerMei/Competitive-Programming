//RAiNcalleER
#include <bits/stdc++.h>
using namespace std;
 
 
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
    int n; cin>>n;
    vector<vector<int>>adj(n+1);
    for(int i=0; i<n-1; i++){
        int a,b; cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vector<ll> ans(n+1, 0);
    vector<bool> vis(n+1, 0);
    vector<int> parent(n+1,-1);
    //从一开始bfs到树根，然后从树根往回计算
    queue<int>q, end;
    q.push(1);
    while(q.size()){
        int curr = q.front();
        q.pop();
        vis[curr] = 1;
        if(curr != 1 && adj[curr].size() == 1){
            end.push(curr);
            ans[curr] = 1;

        }else{
            for(int u : adj[curr]){
                if(!vis[u]){
                    q.push(u);
                    parent[u] = curr;

                }
                
            }
        }
    }
    vector<int> vis_cnt(n+1, 0);
    while(end.size()){
        int u = end.front();
        end.pop();
        while(adj[u].size() <= 2 && parent[u] != -1){
            ans[parent[u]] += ans[u];
            u = parent[u];
        }
        if(vis_cnt[u] < adj[u].size() - 1){
            vis_cnt[u]++;
        }
        if(parent[u] != -1 && vis_cnt[u] == adj[u].size() - 1){
            end.push(parent[u]);
            ans[parent[u]] += ans[u];
        }
        //for(int i=1;i<=n;i++) cout<<ans[i]<<" \n"[i==n];
    }

    int Q; cin>>Q;
    for(int i=0; i<Q; i++){
        int x,y; cin>>x>>y;
        cout<<ans[x] * ans[y]<<"\n";
    }
}
int main(){
  setIO();
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