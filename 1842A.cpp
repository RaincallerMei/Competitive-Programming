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
    vector<int>a(n), b(m);
    ll aa=0, bb=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        aa+=a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
        bb+=b[i];
    }
    if(aa>bb){
        cout<<"Tsondu\n";
    }else if(aa<bb){
        cout<<"Tenzing\n";
    }else{
        cout<<"Draw\n";
    }
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