///RAiNcalleER
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
   int n; cin>>n;
   set<string>ans;
   vector<int>snow(12);
   int num = 0;

   for(int i=0;i<n;i++){
      int mini = 1e9;
      for(int j=0; j<6; j++){
         cin>>snow[j];
         if(mini > snow[j]){
            mini = snow[j];
         }
      }
      int ok=1; string fnl;
      for(int j=0; j<6 && ok; j++){//starting position of this "snow"
         if(snow[j] == mini){
            string forw = ".", back = ".";
            for(int k=0; k<6; k++){
               forw += to_string(snow[(j+k)%6]) + ".";
               back += to_string(snow[(j-k+6)%6]) + ".";
            }
            fnl = min(forw, back);
            if (ans.count(fnl)){
               ok = 0;
            }
         }
      }
      if(ok) ans.insert(fnl);
   }
   if(ans.size() == n){
      cout<<"No two snowflakes are alike.\n";
   }else{
      cout<<"Twin snowflakes found.\n";
   }
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
*/