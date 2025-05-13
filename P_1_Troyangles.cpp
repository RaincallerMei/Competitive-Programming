///RAiNcalleER
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

int n; 
char g[2001][2001];
bool valid(int x,int y){
    return x>=0 && x<n && y>=0 && y<n && g[x][y] == '#';
}
void solve(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>g[i];
    }
    vector<vector<int>>dp(n, vector<int>(n,0)); //number of triangles that start with (i,j)
    ll ans = 0;
    for(int i=n-1; i>=0; i--){
        for(int j=0; j<n; j++){
            if(g[i][j] == '#'){
                dp[i][j]++;
                if(valid(i+1, j-1) && valid(i+1, j) && valid(i+1, j+1)){
                    dp[i][j] += min(dp[i+1][j-1], min(dp[i+1][j], dp[i+1][j+1]));
                }
                ans += dp[i][j];
                //cout<<dp[i][j]<<"\n";
            }
        }
    }
    cout<<ans<<"\n";
}
int main(){
   setIO();
   //int t=5; 
   //cin >> t; 
   //while(t--)
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