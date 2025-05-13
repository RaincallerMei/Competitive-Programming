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

const pair<int,int> moves[8] = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
int n;
bool valid(int x, int y){
        return x<n && x>=0 && y<n && y>=0;
}
void solve(){
        cin>>n;
        int cnt[n+1][n+1], ans[n+1][n+1];
        memset(cnt, 0, sizeof(cnt));
        memset(ans, 0, sizeof(ans));
        int knights = (n * (n + 3)) / 5;
        int ind=2;
        for(; ind<n; ind+=5){
                for(int j=0; j<n; j++){
                        ans[ind][j] = 1;
                }
        }
        ind-=4;
        if(n%5==2 || n%5==1){
                // cout<<temp<<"\n";
                for(int i=0; i<n%5; i++){
                        for(int j=0; j<n; j++){
                                if(j%4==1 || j%4==2){
                                        ans[ind+i][j] = 1;
                                }
                        }
                        if(n%5==2) ans[ind+i][n-2]=1;
                }
        }
        for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                        cout<<ans[i][j]<<" \n"[j==n-1];
                        // if(ans[i][j]){
                        //         cnt[i][j]++;
                        //         for(int k=0; k<8; k++){
                        //                 int di = i + moves[k].f;
                        //                 int dj = j + moves[k].s;
                        //                 if(valid(di, dj)){
                        //                         cnt[di][dj]++;
                        //                 }
                        //         }
                        // }           
                }   
        }
        // cout<<"\n";
        // for(int i=0; i<n; i++)
        //         for(int j=0; j<n; j++)
        //                 cout<<cnt[i][j]<<" \n"[j==n-1];
}
int main(){
        setIO();
        //int t; cin >> t; while(t--)
        solve();
        return 0;
}
()
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