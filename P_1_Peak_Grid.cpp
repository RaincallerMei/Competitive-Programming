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


void solve(){
        int n, k;
        cin>>n>>k;
        vector<vector<int>> g(n, vector<int>(n, 0));
        int front = 1, back = n*n;
        for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                        if(k > 0){
                                if(i == j){
                                        g[i][j] = back;
                                        back--;
                                        k--;
                                }else{
                                        g[i][j] = front;
                                        front++;
                                }
                        }else{
                                if(j == 0){
                                        g[i][j] = back;
                                        back--;
                                }else{
                                        g[i][j] = front;
                                        front++;
                                }
                        }
                        
                }
        }
        for(int i=0; i<n; i++)
                for(int j=0; j<n; j++)
                        cout<<g[i][j]<<" \n"[j==n-1];
}
int main(){
        setIO();
        //int t; cin >> t; while(t--)
        solve();
        return 0;
}
 
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