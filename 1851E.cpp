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
    int n,k; cin>>n>>k;
    vector<int>cost(n), unlimit_sup(k);
    for(int i=0; i<n; i++){
        cin>>costc[i];
    }
    for(int i=0; i<k; i++){
        cin>>unlimit_sup[i];
    }
    vector<vector<int>>mix_po;
    //mix potion
    for(int i=0; i<n; i++){
        int x; cin>>x;
        vector<int>temp(x);
        for(int j=0; j<x; j++){
            cin>>temp[j];
        }
    }
    /*
    -check if it's better to buy the potion, or do you have to mix it.
    -if you encounter a cycle, then figure out which potions are causing the cycle; You will have to buy them.

    */
   

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