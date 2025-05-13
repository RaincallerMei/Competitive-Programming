#include<bits/stdc++.h>

using namespace std;

int n,m,r,c;
void solve(){
	cin>>n>>m>>r>>c;
	char g[n+1][m+1];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			g[i][j]=char('b'+(i+j)%25);
		}
	}
	if(r==n&&m==c-1||r==n-1&&m==c){
		cout<<"IMPOSSIBLE\n";
		return;
	}
	int column=0;
	for(int j=0;j+1<c;j+=2){
		char ch='a';
		g[0][j]=g[0][m-j-1]=ch;
		g[1][j]=g[1][m-j-1]=ch;
		column=j;
	}
	if(c%2){
		int mid=floor(m/2.0);
		for(int i=0;i<n;i++){
			g[i][mid]='a';
		}
	}
	
	if(r==0){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cout<<g[i][j];
			}
			cout<<"\n";
		}	
	}else if(r==1){
		for(int i=0;i<m;i++){
			g[0][i]='a';
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cout<<g[i][j];
			}
			cout<<"\n";
		}
	}else{
		for(int i=0;i<m;i++){
			if(g[1][i]=='a') continue;
			g[1][i]='b';
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cout<<g[i][j];
			}
			cout<<"\n";
		}
	}
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	solve();
	
	return 0;
}
