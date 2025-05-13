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

const int MM = 5e6+2;
bool prime [MM] = {false};
int rounds [MM] = {0, 1};
int mx_mod4 [4] = {0, 1, 0, 3};
void solve(){
        int n; cin>>n;
        int ans = MM;
        for(int i=0; i<n; i++){
                int a; cin>>a;
                if(rounds[a]/2 < ans/2){//先到先得。因为每轮都走两次，所以3次=4次
                        ans = rounds[a];
                }
        }
        if(ans & 1){
                cout<<"Farmer John\n";
        }else{
                cout<<"Farmer Nhoj\n";
        }  
}
int main(){
        setIO();
        for(int i = 2; i <= MM; i++){
                if(!prime[i]){
                        for(int j = i; j <= MM; j += i){
                                prime[j] = true;
                        }
                        mx_mod4[i % 4] = i;
                }
                if(i % 2) rounds[i] = (i - mx_mod4[i % 4]) / 2 + 1;
                else rounds[i] = i/2;
        }
        int t; cin >> t; while(t--)
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