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
   int n,m; cin>>n>>m;
   string s,t; cin>>s>>t;
   int tt=-2;//status; bad->-1; 01->0, 10->1, 00->2, 11->3;

   for(int i=0;i<m-1;i++){
        if(t[i]==t[i+1]){
                tt=-1;
        }
   }
   if(tt==-2){
        if(t[0]=='0'&&t[m-1]=='0'){
                tt=2;
        }else if(t[0]=='1'&&t[m-1]=='0'){
                tt=1;
        }else if(t[0]=='0'&&t[m-1]=='1'){
                tt=0;
        }else{
                tt=3;
        }
   }
        int s0=0, s1=0;
   for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1]){
                if(s[i]=='0'){
                        s0++;
                }else{
                        s1++;
                }
        }
   }
   if(tt<2){
        if(s0+s1==0){
                cout<<"Yes\n";
        }else{
                cout<<"No\n";
        }
   }else if(tt==2){
        if(s0==0){
             cout<<"Yes\n";   
        }else{
             cout<<"No\n";   
        }
   }else if(tt==3){
        if(s1==0){
             cout<<"Yes\n";   
        }else{
             cout<<"No\n";   
        }
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
1. Think Greedy
2. Think Brute Force
3. Think solution in reverse order
4. Think DP [ check constraints carefully ]
5. Check base cases for DP and prove solution for Greedy
6. Think Graph
*/