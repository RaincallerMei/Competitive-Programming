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

const int di[4]={0,0,-1,1}, dj[4]={1,-1,0,0};
int n, s, dist[802][802], ans; 
string g[802];
pi home, start;
queue<pi>bees;

bool valid(int x,int y){
	return x>=0&&x<n&&y>=0&&y<n&&(g[x][y]=='G'||g[x][y]!='M');
}

int main(){
	setIO("");
	//initialize the problem
	cin>>n;
	memset(dist,0x3f3f3f,sizeof dist);
	for(int i=0;i<n;i++){
		cin>>g[i];
		for(int j=0;j<n;j++){
			if(g[i][j]=='M'){
				start={i,j};
			}else if(g[i][j]=='H'){
				bees.push({i,j});
				dist[i][j]=0;
			}else if(g[i][j]=='D'){
				home={i,j};
			}
		}
	}
	//  First, flood fill the graph using bees' initial locations, to find 
	//how long it takes for each grassy cell to be occupied by a bee.
	while(q.size()){
		pi c=bees.front();
		bees.pop();
		for(int i=0;i<4;i++){
			int x=c.f+di[i], y=c.s+dj[i];
			
			if(valid(x,y) && dist[x][y]>dist[c.f][c.s]+1){
				dist[x][y] = dist[c.f][c.s]+1;
			}
		}
	}
	//  Next, binary search the distance that Mecho will need to get back home.
	//In more detail, as Mecho travels back home, keep on checking if it's possible
	//to make it to home without needing to touch a cell with (dist[i][j] > ans), 
	//where "ans" is the binary searched value, also the answer.
	q.push(start);
	while(q.size()){
		pi c=bees.front();
		bees.pop();
		for(int i=0;i<4;i++){
			int x=c.f+di[i], y=c.s+dj[i];
			
			if(valid(x,y) && {
				
				
			}
		}
	}
	
	
	cout<<ans<<"\n";
	
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
