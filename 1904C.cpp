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
        int n,k; cin>>n>>k;
        vector<ll>a(n);
        ll mn = 1e18;
        for(int i=0; i<n; i++){
                cin>>a[i]; 
                mn = min(mn, a[i]);
        }
        if(k>=3){
                cout<<0<<"\n"; return;
        }
        set<ll>diff;
        sort(all(a));
        for(int i=0; i<n; i++){
                for(int j=i+1; j<n; j++){
                        diff.insert(abs(a[i]-a[j]));
                        mn = min(mn, abs(a[i]-a[j]));
                }
        }
        // for(auto i:diff) cout<<i<<" ";
        // cout<<"\n";
        if(k==1){
                cout<<mn<<"\n";
        }else if(k==2){
                for(auto i : diff){
                        for(int i=0; i<n; i++){
                                mn = min(mn, abs(i-a[i]));
                        }
                }
                cout<<mn<<"\n";
        }
        

}
int main(){
        setIO();
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