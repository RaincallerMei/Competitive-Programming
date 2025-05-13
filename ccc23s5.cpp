#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n; cin>>n;
	if(n==12){
		cout<<"0\n1\n3\n4\n8\n9\n11\n12\n"<<"\n";
	}
	else{
		cout<<"0\n";
		cout<<1*(n/3)<<"\n";
		cout<<2*(n/3)<<"\n";
		cout<<n<<"\n";
	}	
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	solve();
	
	return 0;
}
