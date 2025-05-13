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
    int n, m; cin>>n>>m;
    vector<pair<int,int>>range(m);
    for(int i=0;i<m;i++){
        int a,b; cin>>a>>b;
        range[i] = {a,b};
    }
    int q; cin>>q;
    vector<int>change(q);
    for(int i=0;i<q;i++){
        cin>>change[i];
    }

    //先看看会不会-1
    vector<int>pre(n+2,0);
    for(int i=0;i<q;i++){
        pre[change[i]] = 1;
        pre[change[i]+1] = -1;
    }
    for(int i=1;i<=n+1; i++){
        pre[i]+=pre[i-1];
    }

    int beauty=0;
    for(int i=0;i<m;i++){
        int temp = pre[range[i].f] - pre[range[i].s-1];
        if(temp>range[i].f-range[i].s+1){
            beauty = 1;
        }
    }
    if(!beauty){
        cout<<-1<<"\n";
        return;
    }

    //Binary Search
    int l=0, r=q-1;
    while(l<r){
        int mid = l+(r-l)/2;

        vector<int>pref(n+2,0);
        for(int i=0;i<=mid;i++){
            pref[change[i]] = 1;
            pref[change[i]+1] = -1;
        }
        for(int i=1;i<=n+1; i++){
            pref[i]+=pref[i-1];
        }

        beauty=0;
        for(int i=0;i<m;i++){
            int temp = pref[range[i].f] - pref[range[i].s-1];
            if(temp>range[i].f-range[i].s+1){
                beauty = 1;
            }
        }
        cout<<l<<" "<<r<<" "<<beauty<<"\n";
        if(beauty){
            r=mid;
        }else{
            l=mid+1;
        }
    }
    cout<<(l+1)+1<<"\n";//counting from 0 && last not-beautiful
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