#include<bits/stdc++.h>

using namespace std;

void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0);
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

#define pi pair<int,int>
#define f first
#define s second

const int MM=4000;
const int d4i[4]={0,0,-1,1},d4j[4]={-1,1,0,0};

string g[MM+2];
int h,w,depth[MM+2][MM+2];//depth shows the minimum distance to reach

bool inside(int x,int y){
	return x<h&&x>=0&&y<w&&y>=0&&g[x][y]!='.';
}
void solve(){
	cin>>h>>w;
	for(int i=0;i<h;i++) cin>>g[i];
	
	deque<pi>q; 
	q.push_back({0,0});
	depth[0][0]=1;
	int ans=1;
	
	while(q.size()){
		pi c=q.front();
		q.pop_front();
		ans=max(ans,depth[c.f][c.s]);
		
		for(int i=0;i<4;i++){
			int x=c.f+d4i[i], y=c.s+d4j[i];
			//push_front because
			
			if(inside(x,y)&&depth[x][y]==0){
				if(g[x][y] == g[c.f][c.s]){
					depth[x][y]=depth[c.f][c.s];
					q.push_front({x,y});
				}else{
					depth[x][y]=depth[c.f][c.s]+1;
					q.push_back({x,y});
				}
			}
		}
	}
	cout<<ans<<"\n";
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
