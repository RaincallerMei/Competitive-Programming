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
   int n; string tt;
   cin>>n>>tt;
   vector<int>ans;
   for(int i=0;i<n;i++){
        string t; cin>>t;
        int ok=0;
        if(t.size()==tt.size()){
                int diff=0;
                for(int j=0; j<tt.size(); j++){
                        if(t[j]!=tt[j]) 
                                diff++;
                }
                if(diff<=1)
                        ok=1;
        }else if(abs(int(t.size())-int(tt.size()))==1){
                string l,s;
                if(t.size()>tt.size()){
                        l=t;s=tt;
                }else{
                        l=tt;s=t;
                }
                int lind=0, diff=0, chance=1;
                for(int sind=0;sind<s.size();sind++){
                        if(l[lind]!=s[sind]){
                                //cout<<i+1<<" ";
                                if(chance){
                                        lind++;
                                        if(l[lind]!=s[sind])
                                                diff++;
                                        chance=0;
                                }else diff++;
                                //cout<<l[lind]<<" "<<s[sind]<<" "<<diff<<" | ";
                        }
                        lind++;
                }
                //cout<<"\n";
                if(diff==0){
                        ok=1;
                }
        }
        if(ok){
                ans.push_back(i+1);
        }
   }
   cout<<ans.size()<<"\n";
   for(auto i:ans) cout<<i<<" ";
}
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