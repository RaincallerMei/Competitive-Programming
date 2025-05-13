///RAiNcalleER
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

ll dist[502][502], g[502][502];
int n, m, q;
void solve(){
    cin>>n>>m>>q;
    for(int i=0; i<m; i++){
        int a,b; ll c;
        cin>>a>>b>>c;
        if(g[a][b]){
            g[a][b] = min(c, g[a][b]);
        }else{
            g[a][b] = c;
        }
        if(g[b][a]){
            g[b][a] = min(c, g[b][a]);
        }else{
            g[b][a] = c;
        }
        
    }
    
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            if(i == j) dist[i][j] = 0;
            else if(g[i][j]) dist[i][j] = g[i][j];
            else dist[i][j] = 1e18;
            //cout<<dist[i][j]<<" \n"[j==n];
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }

    for(int i=0; i<q; i++){
        int x,y; cin>>x>>y;
        if(dist[x][y] == 1e18){
            dist[x][y] = -1;
        }
        cout<<dist[x][y]<<"\n";
    }
}
int main(){
   setIO();
   //int t; cin >> t; while(t--)
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
1. Think Greedy
2. Think Brute Force
3. Think solution in reverse order
4. Think DP [ check constraints carefully ]
5. Check base cases for DP and prove solution for Greedy
6. Think Graph
*/