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
    int n,m; cin>>n>>m;
    vector<vector<int>>a(n, vector<int>(m));
    vector<vector<int>>vis(n, vector<int>(m,0));
    for(int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin>>a[i][j];
        }
    }
    int ans=0;
    queue<pair<int,int>>q;
    for(int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if(!vis[i][j] && a[i][j] != 0){
                int temp = a[i][j];
                q.push({i,j});
                vis[i][j] = 1;
                while(q.size()){
                    auto tp_pi = q.front();
                    q.pop();
                    for(int k=0; k<4; k++){
                        int di = tp_pi.f + dx[k];
                        int dj = tp_pi.s + dy[k];
                        if(di<n && di>=0 && dj<m && dj>=0 && a[di][dj]!=0 && !vis[di][dj]){
                            temp += a[di][dj];
                            q.push({di, dj});
                            vis[di][dj] = 1;
                        }
                    }
                }
                ans = max(ans, temp);
            }
        }
    }
    cout<<ans<<"\n";
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