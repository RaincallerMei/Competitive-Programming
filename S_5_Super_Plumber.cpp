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
const int dx[3] = {1,0,-1}, dy[3] = {0,1,0};

//-------------------# Long, long had been my road and far, far was the journey; #---------------------
//-----------------------# I would go up and down to seek my heart's desire. #---------------------

int n, m; 
int g[103][103];
void solve(){
   memset(g, 0, sizeof(g));
   for(int i=1; i<=n; i++){
        string row;
        cin>>row;
        for(int j=0; j<m; j++){
            if (row[j] == '.'){
                g[i][j+1] = 0;
            }
            else if (row[j] == '*'){
                g[i][j+1] = -1;
            }
            else{
                g[i][j+1] = row[j] - '0'; //Minus by ASCII code
            }
        }
   }
   /*
   for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cout<<g[i][j]<<" \n"[j==m];
        }
   }*/
    int dp[n+5][m+5];
    memset(dp, -1, sizeof(dp));

    dp[n][1] = g[n][1];
    for(int i=n-1; i; i--){
        if(g[i][1] != -1){
            dp[i][1] = dp[i+1][1] + g[i][1];
        }else{
            break;
        }
    }

   for(int j=2; j<=m; j++){
        //go down
        for(int i=1; i<=n; i++){
            if(dp[i][j-1] != -1){
                int prev = dp[i][j-1];

                for(int di = i; di<=n; di++){
                    if(g[di][j] != -1){
                        prev += g[di][j];
                        dp[di][j] = max(dp[di][j],prev);
                    }else{
                        break;
                    }
                }
            }
        }
        //go up
        for(int i=n; i; i--){
            if(dp[i][j-1] != -1){
                int prev = dp[i][j-1];

                for(int di = i; di; di--){
                    if(g[di][j] != -1){
                        prev += g[di][j];
                        dp[di][j] = max(dp[di][j],prev);
                    }else{
                        break;
                    }
                }
            }
        }
   }
   cout<<dp[n][m]<<"\n";
}
int main(){
    setIO();
    while(true){
        cin>>n>>m;
        if(!n&&!m) break;
        solve();
    }
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