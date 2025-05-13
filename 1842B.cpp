//RAiNcainteER
#include <bits/stdc++.h>
using namespace std;
 
//feels good to be home
 
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
 
 //-------------------#### Long, long had been my road and far, far was the journey; I would go up and down to seek my heart's desire. ####---------------------
/*
1. Think Greedy
2. Think Brute Force
3. Think solution in reverse order
4. Think DP [ check constraints carefully ]
5. Check base cases for DP and prove solution for Greedy
6. Think Graph
*/
 
void solve(){
    int n, x; cin>>n>>x;
    vector<int>a(n), b(n), c(n);
    vector<vector<int>> index_of_digit (3,vector<int>(60, 0x3f3f3f3f));
    vector<int> min_no(3,0x3f3f3f3f);

    for(int i=0;i<n;i++){
        cin>>a[i];
        for (int j = 0; (1<<j)<=a[i]; j++){
            if(a[i]&(1<<j)) 
                index_of_digit[0][j] = min(index_of_digit[0][j], i);
        }
    }
    for(int i=0;i<n;i++) {
        cin>>b[i];
        for (int j = 0; (1<<j)<=b[i]; j++){
            if(b[i]&(1<<j)) 
                index_of_digit[1][j] = min(index_of_digit[1][j], i);
        }
    }
    for(int i=0;i<n;i++) {
        cin>>c[i];
        for (int j = 0; (1<<j)<=c[i]; j++){
            if(c[i]&(1<<j)) 
                index_of_digit[2][j] = min(index_of_digit[2][j], i);
        }
    }
    for(int k=0;k<60; k++){
        if((x&(1<<k))==0){//bad digit
            //cout<<k<<"\n";
            for(int i=0;i<n;i++){
                if((a[i]&(1<<k))) 
                    min_no[0] = min(i, min_no[0]);
                if((b[i]&(1<<k))) 
                    min_no[1] = min(i, min_no[1]);
                if((c[i]&(1<<k))) 
                    min_no[2] = min(i, min_no[2]);
            }
        }
    }
    //for(int j=0;j<3;j++) cout<<min_no[j]<<" \n"[j==2];

    for (int i = 0; (1<<i)<=x; i++){
        if((x&(1<<i))==0) continue;
        int ok=0;
        for(int j=0;j<3;j++){
            if(index_of_digit[j][i] < min_no[j]){
                ok=1;
            }
        }
        if(!ok){
            cout<<"No\n"; return;
        }
    }
    cout<<"Yes\n";
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