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
    vector<int>a(n+2);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    vector<int>xorray(n+2);
    int max_bit = 0;
    for(int i=n-1; i>=0; i--){
        xorray[i] = a[i];
        if(i < n-1){
            xorray[i] ^= xorray[i+1];
        }
        for(int j=0; j<=8; j++){
            if((xorray[i] & (1<<j))) 
                max_bit = max(max_bit, j);
        }
    }

    for(int i=0;i<n;i++){
        cout<<xorray[i]<<" \n"[i==n-1];
    }

    vector<vector<int>>dp(max_bit+2, vector<int>(n+2,0));//dp[i][j]：在 index j 上确保 digit i 为 1
    int ans = 0;
    // for(int i=max_bit; i>=0; i--){
    //     if((xorray[0] & (1<<i))){
    //         dp[i][0] = xorray[0];
    //     }
    //     cout<<dp[i][0]<<" ";
    //     for(int j=1; j<n; j++){
    //         dp[i][j] = dp[i][j-1];
    //         if(((dp[i+1][j-1]^xorray[j]) & (1<<i))){
    //             dp[i][j] = max(dp[i][j], dp[i+1][j-1]^xorray[j]);
    //         }
    //         ans = max(ans, dp[i][j]);
    //         cout<<dp[i][j]<<" \n"[j==n-1];
    //     }
    // }
    for(int i=0; i<=max_bit; i++){
        if((xorray[0] & (1<<i))){
            dp[i][0] = xorray[0];
        }
        cout<<dp[i][0]<<" ";
        if(i){
            for(int j=1; j<n; j++){
                dp[i][j] = dp[i][j-1];
                // if(((xorray[j]) & (1<<i))){
                //     dp[i][j] = max(dp[i][j], xorray[j]);
                // }
                if(((dp[i-1][j-1]^xorray[j]) & (1<<i))){
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1]^xorray[j]);
                }
                ans = max(ans, dp[i][j]);
                cout<<dp[i][j]<<" \n"[j==n-1];
            }
        }else{
            for(int i=1;i<n;i++){
                dp[0][i] = max(dp[0][i-1], xorray[i]);
                ans = max(ans, dp[0][i]);
                cout<<dp[0][i]<<" \n"[i==n-1];
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