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
   int n, x; cin>>n>>x;
   vector<int>a(n), aa(n), b(n), bb(n);
   for(int i=0; i<n; i++){
      cin>>a[i]; aa[i] = a[i];
   }
   for(int i=0; i<n; i++){
		cin>>b[i];
   }
   sort(all(aa)); sort(all(b));

	for(int i=0;i<n-x;i++) bb[i] = b[i+x];
	for(int i=0;i<x;i++) bb[i+n-x] = b[i];

	// cout<<x<<"\n";
	// for(int i=0;i<n;i++) cout<<aa[i]<<" \n"[i==n-1];
	// for(int i=0;i<n;i++) cout<<bb[i]<<" \n"[i==n-1];
	int cnt=0;
	for(int i=0;i<n;i++){
		if(aa[i] > bb[i]) cnt++;
	}
	if(cnt==x){
		cout<<"YES\n";
		unordered_map<int,queue<int>>mp;
		for(int i=0;i<n;i++){
			mp[aa[i]].push(bb[i]);
		}
		vector<int>ans(n);
		for(int i=0;i<n;i++){
			ans[i] = mp[a[i]].front();
			mp[a[i]].pop();
		}
		for(int i=0;i<n;i++) cout<<ans[i]<<" \n"[i==n-1];
	}else{
		cout<<"NO\n";
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