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
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define pi pair<int,int>

ll trans(ll val,int x){
	if(val>x){
		return 2*x-val;
	}
	return val;
}
void solve(){
	int n,q; cin>>n>>q;
	vector<ll>c(n);
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	sort(all(c));
	vector<ll>pref(n+1,0);
	for(int i=1;i<=n;i++){
		pref[i]=c[i-1]+pref[i-1];
	}
	for(int i=0;i<q;i++){
		int k,m; cin>>k>>m;
		int low=0, high=m;
		while(low<high){
			int mid=(low+high)/2;			
			int right=n-(m-mid);
			
			if (c[mid] > k) {
				high = mid;
			} else if (c[right] <= k) {
				low = mid + 1;
			} else if (trans(c[mid], k) < trans(c[right], k)) {
				low = mid + 1;
			} else {
				high = mid;
			}
		}
		int right=n-(m-low);
		ll ans=pref[low]+(2*k*(m-low)-(pref[n] - pref[right]));
		cout<<ans<<"\n";
	}
}

int main(){
	setIO("");
	//int t; cin>>t; while(t--)
		solve();
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
 Nani the fuck did you just fucking iimasu about watashi, 
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
