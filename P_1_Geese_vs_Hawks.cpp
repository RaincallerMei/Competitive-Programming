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


void solve(){
   int n; cin>>n;
   string aa,bb; 
   vector<int>a(n+1), b(n+1);
   cin>>aa;
   aa = "." + aa;
   for(int i=1; i<=n; i++) cin>>a[i];

   cin>>bb;
   bb = "." + bb;
   for(int i=1; i<=n; i++) cin>>b[i];
   
   vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
   for(int i=1; i<=n; i++){
      for(int j=1; j<=n; j++){
         dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
         if((a[i]>b[j] && aa[i] == 'W' && bb[j]=='L') ||(a[i]<b[j] && aa[i] == 'L' && bb[j]=='W') ){
            dp[i][j] = max(dp[i][j], dp[i-1][j-1] + a[i] + b[j]);
         }
      }
   }
   cout<<dp[n][n]<<"\n";
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