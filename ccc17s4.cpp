#include<bits/stdc++.h>

using namespace std;

void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0);
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

#define ll long long
#define pi pair<int,int>
#define f first
#define s second

const int MM=1e5+2;
int n,m,d;
vector<pi>g[MM];

int main(){
	setIO("");
	cin>>n>>m>>d;
	for(int i=0;i<m;i++){
		int a,b,c; cin>>a>>b>>c;
		a--; b--;
		g[a].push_back({b,c});
		g[b].push_back({a,c});
	}
	
	
	return 0;
}
/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */
 
 
 
 
 
 
 
 
 
 
 
//https://dmoj.ca/problem/tle17c7p3/editorial
