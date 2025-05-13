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


int main(){
	setIO("");
	int n,m;
	cin>>n>>m;
	vector<pi>chars(n);
	for(int i=0;i<n;i++){
		cin>>chars[i].f>>chars[i].s;
	}
	ll ans=0, dp[m+2];
	int vis[n+1];
	memset(dp,0x3f3f3f3f,sizeof dp);
	//dp[i][j]->the minimum cost of collecting i characters, where the ith character is j
	dp[0]=0;
	for(int i=1;i<=m;i++){
		int index;
		for(int j=0;j<n;j++){
			if(dp[i]>dp[i-1]+chars[j].f*(i-1)+chars[j].s&&!vis[j]){
				dp[i]=dp[i-1]+chars[j].f*(i-1)+chars[j].s;
				index=i;
			}
		}
		vis[index]=1;
		cout<<dp[i]<<"\n";
	}
	cout<<dp[m]<<"\n";
	return 0;
}
/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */
 
 
 
 
 
 
 
 
 
 
 
 /*
 Nani the f*ck did you just f*cking iimasu about watashi, 
 you chiisai bitch desuka? Watashi¯ll have anata know that 
 watashi graduated top of my class in Nihongo 3, and 
 watashi've been involved in iroirona Nihongo tutoring 
 sessions, and watashi have over sanbyaku perfect test 
 scores. Watashi am trained in kanji, and watashi is the 
 top letter writer in all of southern California. Anata 
 are nothing to watashi but just another weaboo. Watashi 
 will korosu anata the fuck out with vocabulary the likes 
 of which has never been mimasu¡¯d before on this continent, 
 mark watashino fucking words. Anata thinks anata can get 
 away with hanashimasing that kuso to watashi over the 
 intaaneto? Omou again, fucker. As we hanashimasu, watashi 
 am contacting watashino secret netto of otakus across the 
 USA, and anatano IP is being traced right now so you 
 better junbishimasu for the ame, ujimushi. The ame that 
 korosu¡¯s the pathetic chiisai thing anata calls anatano 
 life. You¡¯re fucking shinimashita¡¯d, akachan.
 */
