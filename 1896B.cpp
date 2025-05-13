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
   int n; cin>>n;
   string s; cin>>s;
   int ans=0, cnt=0;
   if(s[0]=='A') cnt++;
   for(int i=0;i<n-1;i++){
        if(s[i]=='A' && s[i+1]=='B'){
                int ind=i+1, backind=i-1;
                while(s[ind]=='B' && ind<n){
                        ind++;
                        ans++;
                }
                while(s[backind]=='A' && backind>=0){
                        backind--;
                        ans++;
                }
        }
        if(s[i]!=s[i+1]) cnt++;
   }
   if(cnt>=2)ans+=(cnt/2)-1;
   cout<<ans<<"\n";
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
1. Think Greedy
2. Think Brute Force
3. Think solution in reverse order
4. Think DP [ check constraints carefully ]
5. Check base cases for DP and prove solution for Greedy
6. Think Graph
*/