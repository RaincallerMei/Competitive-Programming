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


ll avg;
vector<vector<int>>adj;
vector<ll>h, subtree_tot;
struct as{int u, v; ll val;};
vector<as> ans;

void dfs_fill_subtree(int node = 0, int par = 0){
        subtree_tot[node] = h[node] - avg;
        // fill in total bales in each subtree and size of each subtree
                //this way, by looking at the parent of subtree, we know if we need to move hays to this subtree
        for (auto child: adj[node]){
                if(child != par){
                        dfs_fill_subtree(child, node);
                        subtree_tot[node] += subtree_tot[child];//this node has the sum of barns of its childs
                }
        }
}
void distribute(int node = 0, int par = 0){
        //distribute the haybales in x ’s subtree, so that each child is left with 0 haybales. x will be subtree_tot(x)
        // give from +child to node
                // this way, the node will definitely have enough barn to "feed" its child that requires hay
        for (auto child: adj[node]){
                if(child != par){
                        if(subtree_tot[child] >= 0){
                                distribute(child, node);
                                //until the node's child needs hay
                                //at that point, we give hay from node to child
                        }
                        if(subtree_tot[child] > 0){
                                ans.push_back({child, node, subtree_tot[child]});
                        }
                }
        }
        // give from node to -child
                //here, we pass the hay that we got from +childrens to the -childs;
                //then, the -child will pass these hay down to their child who needs these hay.
        for (auto child: adj[node]){
                if(child != par){
                        if(subtree_tot[child] < 0){
                                ans.push_back({node, child, -subtree_tot[child]});
                                distribute(child, node);
                                //
                        }
                }
        }
}
void solve(){
        int n; cin>>n;
        h.resize(n); adj.resize(n);
        avg=0;
        for(int i=0; i<n; i++){
                cin>>h[i]; avg += h[i];
        }
        avg/=n;
        for(int i=0; i<n-1; i++){
                int u, v; cin>>u>>v; u--; v--;
                adj[u].push_back(v);
                adj[v].push_back(u);
        }
        subtree_tot.resize(n);
        dfs_fill_subtree();
        distribute();
        cout<<ans.size()<<"\n";
        for(auto i : ans){
                cout<<i.u + 1<<" "<<i.v + 1<<" "<<i.val<<"\n";
        }
}
int main(){
        setIO();
        //int t; cin >> t; while(t--)
        solve();
        return 0;
}
 
/*
do smth instead of nothing and stay organized
WRITE STUFF DOWN
DON'T GET STUCK ON ONE APPROACH
1. Think Greedy
2. Think Brute Force
3. Think solution in reverse order
4. Think DP [ check constraints carefully ]
5. Check base cases for DP and prove solution for Greedy
6. Think Graph
7. int overflow, array bounds
8. special cases (n=1?)
*/