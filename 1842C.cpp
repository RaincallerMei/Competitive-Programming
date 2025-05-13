//RAiNcalleER
#include <bits/stdc++.h>
using namespace std;
 
//feels good to be home
 
using ll = long long;
 
void setIO(string name=""){
  ios_base::sync_with_stdio(0); cin.tie(0);
  if((int)name.size() > 0){freopen((name+".in").c_str(), "r", stdin); freopen((name+".out").c_str(), "w", stdout);}
}
const ll mod=998244353;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define all(x) (x).begin(), (x).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
 
 //-------------------#### Long, long had been my road and far, far was the journey; I would go up and down to seek my heart's desire. ####---------------------
/*
1. Think Greedy
2. Think Brute Force
3. Think Solution in Reverse Order
4. Think DP [ check constraints carefully ]
5. Check Base Cases for DP and Prove Solution for Greedy
6. Think Graph
*/
 
void solve(){
    int n; cin>>n;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<int>last(n+1,-1);
    vector<int>dp(n+1,0);
    for(int i=1;i<=n;i++){
        dp[i] = dp[i-1];
        if(last[a[i]] != -1){
            int last_ind = last[a[i]];
            int connect = max(i-last_ind + dp[last_ind], i-last_ind+1 + dp[last_ind-1]);
            ////connecting to form a bigger subarray vs grasping smaller subarray
            dp[i] = max(connect, dp[i]);
        }
        last[a[i]] = i;
    }
    cout<<dp[n]<<"\n";
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