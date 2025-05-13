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

const int M = 1e5+2;

int n, m;
vector<pair<ll,int>>g[M];
ll dist[M];
bool seen[M];

void solve(){
   cin>>n>>m;
   memset(seen, 0, sizeof seen);

   for(int i=1; i<=n; i++){
      dist[i] = LLONG_MAX;
   }
   for(int i=0; i<m; i++){
      int a,b; ll c; cin>>a>>b>>c;
      g[a].push_back({c,b});//{dist, city}
   }

   priority_queue<pair<ll,int>> q;//{dist, city}
   dist[1] = 0;
   q.push({0, 1});

   while(q.size()){
      int curr = q.top().s; 
      q.pop();
      if(seen[curr]) continue;
      seen[curr] = 1;

      for (auto u : g[curr]){
         ll dis = u.f; int city = u.s;

         if(dist[curr] + dis < dist[city]){
            dist[city] = dist[curr] + dis;
            q.push({-dist[city], city});
         }
      }
   }
   for(int i=1; i<=n; i++){
      cout<<dist[i]<<" \n"[i==n];
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