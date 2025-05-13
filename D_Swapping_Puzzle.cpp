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


void solve(){
        int h,w; cin>>h>>w;
        vector<vector<int>>a(h,vector<int>(w)),b(h,vector<int>(w));
        int diff=0;
        for(int i=0; i<h; i++){
                for(int j=0; j<w; j++){
                        cin>>a[i][j];
                }
        }
        for(int i=0; i<h; i++){
                for(int j=0; j<w; j++){
                        cin>>b[i][j];
                        if(a[i][j]!=b[i][j]) diff=1;
                }
        }
        vector<vector<int>>bbrow(h,vector<int>(w)),bbcol(w,vector<int>(h));
        bbrow = b;
        for(int i=0; i<h; i++)
                sort(all(bbrow[i]));
        for(int j=0; j<w; j++){//b
                for(int i=0;i<h;i++){
                        bbcol[j][i] = b[i][j];
                }
                sort(all(bbcol[j]));
        }

        //row-list
        vector<int>rowlist, collist,rowvis(h,0), colvis(w,0);
        for(int i=0; i<h; i++){//a
                vector<int>temp = a[i];
                sort(all(temp));
                for(int ii=0; ii<h; ii++){
                        if(rowvis[ii]) continue;
                        int ok=1;
                        for(int j=0; j<w; j++){
                                if(temp[j] != bbrow[ii][j]){
                                        ok=0;
                                }
                        }
                        if(ok){
                                rowlist.push_back(ii);
                                rowvis[ii]=1;
                                break;
                        }
                }
        }
        //col-list
        for(int j=0; j<w; j++){//b
                vector<int>temp;
                for(int i=0;i<h;i++) temp.push_back(a[i][j]);
                sort(all(temp));
                for(int jj=0; jj<w; jj++){
                        if(colvis[jj]) continue;
                        int ok=1;
                        for(int i=0;i<h;i++){
                                if(temp[i] != bbcol[jj][i]){
                                        ok=0;
                                }
                        }
                        if(ok){
                                collist.push_back(jj); 
                                colvis[jj]=1;
                                break;
                        }
                }
        }
        //analysis
        // for(int i:rowlist) cout<<i<<" ";
        // cout<<"g\n";
        // for(int i:collist) cout<<i<<" ";
        // cout<<"\n";

        int n=rowlist.size(), m=collist.size();
        if(n!=h || m!=w){
                cout<<-1<<"\n"; return;
        }
   
        int ans=0;
        for(int i=0; i<n; i++){
                int swapped=0;
                for(int j=0;j<n-i-1;j++){
                        if(rowlist[j]>rowlist[j+1]){
                                swap(rowlist[j],rowlist[j+1]);
                                ans++;
                                swapped=1;
                        }
                }
                if (swapped == false)
                        break;     
        }      
        for(int i=0; i<m; i++){
                int swapped=0;
                for(int j=0;j<m-i-1;j++){
                        if(collist[j]>collist[j+1]){
                                swap(collist[j],collist[j+1]);
                                ans++;
                                swapped=1;
                        }
                }
                if (swapped == false)
                        break;   
        }
        if(diff&&!ans){
                
        }
        cout<<ans<<"\n";
}
int main(){
        setIO();
        //int t; cin >> t; while(t--)
        solve();
        return 0;
}
 
/*
do smth instead of nothing and stay organized
WRITE STUFF DOWN
DON'T GET STUCK ON ONE APPROACH
1. Think Greedy
2. Think Brute Force
3. Think solution in reverse order
4. Think DP [ check constraints carefully ]
5. Check base cases for DP and prove solution for Greedy
6. Think Graph
7. int overflow, array bounds
8. special cases (n=1?)
*/