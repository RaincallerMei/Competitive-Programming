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


void solve(){
	int n,q;
	cin>>n>>q;
	
	vector<int>g[n];
	int depth[n];
	for(int i=0;i<n-1;i++){
		int u,v;
		cin>>u>>v;
		u--; v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	
	//find depth of each node
	queue<int>node_queue;
	node_queue.push(0);
	memset(depth,-1,sizeof depth);
	depth[0]=0;
	//create a map that finds which nodes are in depth d
	map<int,vector<int>>depth_nodes;
	
	while(node_queue.size()){
		int curr_node=node_queue.front();
		node_queue.pop();
		for(auto next_node:g[curr_node]){
			if(depth[next_node]==-1){
				depth[next_node]=depth[curr_node]+1;
				depth_nodes[depth[next_node]].pb(next_node);
				node_queue.push(next_node);
			}
		}
	}
	//query: bfs everytime 
	for(int i=0;i<q;i++){
		int a,b,d;
		cin>>a>>b>>d;
		a--; b--;
		vector<int>copy_g[n];
		for(int j=0;j<n;j++){
			copy_g[j]=g[j];
		}
		
		vector<int>dist_nodes = depth_nodes[d];
		sort(all(dist_nodes); //so that they are in order
		
		if(dist_nodes.size()>1){
			for(int j=1; j<dist_nodes.size(); j++){
				copy_g[dist_nodes[j]].pb(dist_nodes[j-1]);
				copy_g[dist_nodes[j-1]].pb(dist_nodes[j]);
			}
		}
		//loop through the graph to find depth
		node_queue.push(a);
		memset(depth,0x3f3f3f3f,sizeof depth);
		depth[a]=0;
		
		while(node_queue.size()){
			int curr_node=node_queue.front();
			node_queue.pop();
			for(auto next_node : copy_g[curr_node]){
				if(depth[next_node]>depth[curr_node]+1){
					depth[next_node]=depth[curr_node]+1;
					node_queue.push(next_node);
				}
			}
		}
		cout<<depth[b]<<"\n";
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
