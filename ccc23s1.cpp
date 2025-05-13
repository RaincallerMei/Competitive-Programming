#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin>>n;
	int ans=0;
	int tile[2][n+1];
	for(int i=0;i<2;i++){
		for(int j=0;j<n;j++){
			cin>>tile[i][j];
			ans+=tile[i][j]*3;
		}
	}
	
	for(int i=0;i<2;i++){
		for(int j=0;j<n-1;j++){
			if(tile[i][j]&&tile[i][j+1]){
				ans-=2;
			}
		}
	}
	
	for(int j=0;j<n;j++){
		if(tile[0][j]&&tile[1][j]&&j%2==0){
			ans-=2;
		}
	}
	cout<<ans<<"\n";
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	solve();
	
	return 0;
}
