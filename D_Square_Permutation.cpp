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


int main(){
    setIO();
    int n; string s; 
    cin>>n>>s;
    vector<int>sspace(11,0), currspace(11,0);
    for(int j=0; j<s.size(); j++){
        sspace[s[j]-'0']++;
    }
    int ans=0;
    for(int i=1; i*i<1e13; i++){
        string curr=to_string(i*i);
        if(curr.size()>n) 
            break;
        for(int j=1; j<=9; j++) 
            currspace[j] = 0;
        for(int j=0; j<curr.size(); j++){
            currspace[curr[j]-'0']++;
        }
        int ok=1;
        for(int j=1; j<=9; j++){
            if(currspace[j] != sspace[j]) ok=0;
        }
        if(ok){
            ans++;
            //cout<<i*i<<"\n";
        }
    }
    cout<<ans<<"\n";
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