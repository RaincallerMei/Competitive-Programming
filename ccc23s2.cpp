#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define pi pair<ll,ll>

bool cmp(pi a,pi b){
	return a.first<b.first;
}
void solve(){
	int n; cin>>n;
	vector<int>h(n);
	for(int i=0;i<n;i++){
		cin>>h[i];
	}
	ll stored_val[n+1][n+1];
	
	for(int size=0;size<n;size++){
		
		pi pear={1e18,-1};
		for(int i=0;i+size<n;i++){
			int prev_val  = 0;
			if(size>=2) {
				prev_val = stored_val[i+1][size-2];
			}
			int value = abs (h[i+size] - h[i]) + prev_val;
			if(pear.first>value){
				pear = {value, i};
			}
			stored_val[i][size] = value;
		}
		cout<<pear.first<<" \n"[size==n-1];
	}
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	
	solve();
	return 0;
}
