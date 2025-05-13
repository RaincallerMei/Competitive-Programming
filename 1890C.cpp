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
   int n; string s;
   cin>>n>>s;
   int O=0, I=0;
    for(int i=0; i<n; i++){
        if(s[i]=='0'){
            O++;
        }else{
            I++;
        }
    }
    if(O!=I){
        cout<<"-1\n"; return;
   }
   vector<int>ans;
    int l=0, r=n-1;
    while(l<r){
    // for(int o=0;o<4;o++){
        if(s[l]!=s[r]){
            l++; r--;
        }else{
            if(s[l] == '0'){                
                if(r+1!=s.size()){
                    s = s.substr(0,r+1)+"01"+s.substr(r+1);
                }else{
                    s = s.substr(0,r+1)+"01";
                }
                ans.push_back(r+1);
                r+=2;
            }else if(s[l] == '1'){
                s = s.substr(0,l)+"01"+s.substr(l);
                ans.push_back(l);
                r+=2;
            }
        }
    }
    cout<<ans.size()<<"\n";
    for(int i:ans) cout<<i<<" ";
    cout<<"\n";
}

            // int temp=0;
            // for(int i=0;i<s.size();i++){
            //     temp+=s[i]-'0';
            // }
            // if(temp%int(s.size())==0){
            //     cout<<"-1\n"; return;
            // }
            // //----
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