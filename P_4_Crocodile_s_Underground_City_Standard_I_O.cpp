//RAiNcalleER
#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
void setIO(string name=""){
   ios_base::sync_with_stdio(0); cin.tie(0);
   if((int)name.size() > 0){freopen((name+".in").c_str(), "r", stdin); freopen((name+".out").c_str(), "w", stdout);}
}

#define f first
#define s second
#define all(x) (x).begin(), (x).end()
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};

//-------------------# Long, long had been my road and far, far was the journey; #---------------------
//-----------------------# I would go up and down to seek my heart's desire. #---------------------

const int MM=
vector<pair<int,int>> g[MM];
// Adjacency list of (neighbour, edge weight)
ll dist[MM];


int travel_plan(int N, int M, int R[][2], int L[], int K, int P[]){
	
}

int main(){
   setIO();
   int n,m,k,r[MM][2],l[MM],p[MN]; cin>>n>>m>>k;
	for(int i=0; i<m; i++) cin>>r[i][0]>>r[i][1]>>l[i];
	for(int i=0; i<k; i++) cin>>p[i];
	cout<<travel_plan(n,m,k,r,l,p);
   return 0;
}
 
/*
stuff you should look for
int overflow, array bounds
special cases (n=1?)
do smth instead of nothing and stay organized
WRITE STUFF DOWN
DON'T GET STUCK ON ONE APPROACH
1. Think Greedy
2. Think Brute Force
3. Think solution in reverse order
4. Think DP [ check constraints carefully ]
5. Check base cases for DP and prove solution for Greedy
6. Think Graph
*/