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


using ll = long long;
int maximumLength(string s) {
        int n = s.size();
        vector<int>lenn(n, 1);
        map<char, vector<int>>mp;
        for(int i=1; i<n; i++){
            if(s[i] == s[i-1]){
                lenn[i] = lenn[i-1] + 1;
            }else{
                mp[s[i-1]].push_back(lenn[i-1]);
            }
        }
        int mx = 0;
        for(int i=0; i<26; i++){
            mp.sort(mp['a'+i].begin(), mp['a'+i].end(), greater<int>());
            int cnt = 1;
            for(int j=1; j<mp['a'+i].size(); j++){
                if(mp['a'+i][j] == mp['a'+i][j-1]){
                    cnt++;
                }else{
                    cnt=1;
                }
                if(cnt == 3){
                    mx = max(mx, mp['a'+i][j]);
                    break;
                }
            }
        }
        return mx;
    }
int main() {
    cout<<maximumLength("aaaa")<<"\n";
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