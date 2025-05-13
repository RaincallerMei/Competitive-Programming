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
        int n, m, k; 
        cin>>n>>m>>k;
        set<int>a,b;
        for(int i=0; i<n; i++){
                int x; cin>>x; a.insert(x);
        }
        for(int i=0; i<m; i++){
                int x; cin>>x; b.insert(x);
        }

        vector<int>numk(k+2,0);
        for(int i:a) {
                if(i<=k) numk[i]++;
        }
        for(int i:b) {
                if(i<=k) numk[i]+=2;
        }

        int cnt1=0, cnt2=0, cnt3=0;
        for(int i=1; i<=k; i++){
                if(numk[i] == 0){
                        cout<<"NO\n"; return;
                }
                if(numk[i]==1){
                        cnt1++;
                }else if(numk[i]==2){
                        cnt2++;
                }else{
                        cnt3++;
                }
        }
        //cout<<cnt1<<" "<<cnt2<<" "<<cnt3<<"\n";
        if(cnt1==cnt2 || (cnt1<=k/2 && cnt2<=k/2)){
                cout<<"YES\n";
        }else{
                cout<<"NO\n";
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