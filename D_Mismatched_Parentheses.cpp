//RAiNcalleER
#include <bits/stdc++.h>
using namespace std;
 
//feels good to be home
 
using ll = long long;
 
void setIO(string name=""){
  ios_base::sync_with_stdio(0); cin.tie(0);
  if((int)name.size() > 0){freopen((name+".in").c_str(), "r", stdin); freopen((name+".out").c_str(), "w", stdout);}
}
const ll mod=1e9+7;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define all(x) (x).begin(), (x).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
 
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
    int n; cin>>n;
    string s; cin>>s;
    string ans="";
    stack<string>st;
    for(int i=0; i<n; i++){
        if(st.empty()){
            st.push(string(1,s[i]));
        }else{
            if(s[i]=='('){
                st.push("(");
            }else if(s[i]==')'){
                if(st.top()[0]=='('){
                    st.pop();
                }else{
                    st.push(")");
                }
            }else{
                st.top()+=s[i];
            }
        }
    }
    while(st.size()){
        string te = st.top();
        reverse(all(te));
        ans += te;
        st.pop();
    }
    reverse(all(ans));
    cout<<ans<<"\n";
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