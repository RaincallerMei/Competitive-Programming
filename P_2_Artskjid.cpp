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


const int Mx = 1<<18;

int n, m;
int dist[20][Mx+2];
vector<pair<int,int>> adj[20];//{city, dist}
queue<pair<int,int>>qu;//{city, path}
/*
more like a bitwise + [(bfs + dp) or Dijkstra]
*/
void solve(){
   cin>>n>>m;
   memset(dist, -1, sizeof(dist));
   for(int i=0; i<m; i++){
      int a,b,c; cin>>a>>b>>c;
      adj[a].push_back({b,c}); //{city, dist}
   }

   qu.push({0, 1}); //{city, path}
   dist[0][1] = 0;

   while(qu.size()){
      auto curr = qu.front(); 
      int cur_city = curr.f;
      int cur_path = curr.s;
      qu.pop();
      for(auto u: adj[cur_city]){
         int rn_city = u.f;
         int rn_dist = u.s;
         if((1<<rn_city) & cur_path) continue; // if already been to this city

         int rn_path = cur_path + (1<<rn_city);
         if(dist[rn_city][rn_path] < dist[cur_city][cur_path] + rn_dist){
            dist[rn_city][rn_path] = dist[cur_city][cur_path] + rn_dist;
            qu.push({rn_city, rn_path});
         }
      }
   }

   int ans = *max_element(dist[n - 1], dist[n - 1] + (1 << n));
   cout<<ans<<"\n";
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