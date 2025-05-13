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

const int MM=1e5+2;



void solve(){
    int n,m,p; 
    cin>>n>>m>>p; p--;
    vector<int>adj[n], into(n, 0);
    vector<pair<ll,int>>d(n); 
    for(int i=0; i<n; i++){
        ll x; cin>>x;
        d[i] = {x,i};
    }
    sort(all(d));
    //redefine p as the position of the starter planet in the sorted list
    for(int i=0; i<n; i++){
        if(d[i].s == p){
            p = i; break;
        }
    }
    for(int i=0; i<n; i++)
        cout<<d[i].f<<"-"<<d[i].s<<" \n"[i==n-1];
    //b needs to be visited before a
    for(int i=0; i<m; i++){
        int a,b; cin>>a>>b; a--; b--;
        adj[b].push_back(a);
        into[a]++;
    }
    for(auto u : adj[d[p].s]){
        into[u]--;
    }
    if(n<=2){
        cout<<abs(d[0].f-d[n-1].f)<<"\n"; return;
    }
    ll ans=0;
    //问题：可能有时候visit planet的顺序要求先看左边，有时候要先看右边。
    //先iterate一次从p能开始能visit的最left和最right？
    int l=p, r=p, li=l-1, ri=r+1;
    cout<<l<<" "<<r<<" "<<li<<" "<<ri<<"\n";
    
    while(l>0 || r<n-1){
        //to right
        if(r<n-1){
            while(ri<n-1 && into[d[ri].s]>0){
                ri++;
            }
            ans = max(ans, abs(d[r].f - d[ri].f));
            cout<<r<<" -- "<<ri<<" "<<ans<<"\n";
            for(int i=r; i<=ri; i++){
                for(auto u : adj[d[i].s]){
                    into[u]--;
                }
            }
        }
        
        //to left
        if(l>0){
            while(li>0 && into[d[li].s]>0){
                li--;
            }
            ans = max(ans, abs(d[l].f - d[li].f));
            cout<<l<<" oo "<<li<<" "<<ans<<"\n";
            for(int i=li; i<=l; i++){
                for(auto u : adj[d[i].s]){
                    into[u]--;
                }
            }
        }
        l=li, r=ri;
    }
    cout<<ans<<"\n";
}
//Sort the planets. Do a topot-sort like thing where you maintain the in degree of 
//each node and add it to a queue when it becomes reachable.
//To help with this, keep track of the range [l, r] you are currently able to reach 
//and the indices li, ri of the left and rightmost planets within this range. 

//sort the planets by distance then start at P. Maintain an interval [l, r] of the 
//current "visited" planets. Do this repeatedly: greedily visit the closest available 
//planet expanding l and r; then relaxing the force fields in between.  
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