///RAiNcalleER
#include <bits/stdc++.h>
using namespace std;
 
 
using ll = long long;
 
void setIO(string name=""){
   ios_base::sync_with_stdio(0); cin.tie(0);
   if((int)name.size() > 0){freopen((name+".in").c_str(), "r", stdin); freopen((name+".out").c_str(), "w", stdout);}
}

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define all(x) (x).begin(), (x).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};

//-------------------# Long, long had been my road and far, far was the journey; #---------------------
//-----------------------# I would go up and down to seek my heart's desire. #---------------------
/*
1. Think Greedy
2. Think Brute Force
3. Think solution in reverse order
4. Think DP [ check constraints carefully ]
5. Check base cases for DP and prove solution for Greedy
6. Think Graph
*/

void solve(){
    int n,m; cin>>n>>m;
    vector<string>board(n);
    for(int i=0; i<n; i++){
        cin>>board[i];
    }

    vector<int>row(n), rowB(n);
    //check if there are odd numbers in row
    for(int i=0; i<n; i++){
        int temp = 0;
        for(int j=0; j<m; j++){
            if(board[i][j] != '.'){
                temp++;
            }
        }
        if(temp%2){
            cout<<-1<<"\n";
            return;
        }
        row[i] = temp;
    }

    vector<int>col(m), colB(m);
    //check if there are odd numbers in column
    for(int j=0; j<m; j++){
        int temp = 0;
        for(int i=0; i<n; i++){
            if(board[i][j] != '.'){
                temp++;
            }
        }
        if(temp%2){
            cout<<-1<<"\n";
            return;
        }
        col[j] = temp;
    }
    //building answer
    vector<string>ans(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            ans[i][j] = '.';
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j] == 'L'){
                if(colB[j]+1 > col[j]/2){
                    ans[i][j] = 'W';
                    ans[i][j+1] = 'B';
                    colB[j+1]++;
                }else{
                    ans[i][j] = 'B';
                    ans[i][j+1] = 'W';
                    colB[j]++;
                }
                rowB[i]++;
            }
            else if(board[i][j] == 'U'){
                if(rowB[i]+1 > row[i]/2){
                    ans[i][j] = 'W';
                    ans[i+1][j] = 'B';
                    rowB[i+1]++;
                }else{
                    ans[i][j] = 'B';
                    ans[i+1][j] = 'W';
                    rowB[i]++;
                }
                colB[j]++;
            }
        }
    }
    //print answer
    // for(int i=0; i<n; i++){
    //     cout<<rowB[i]<<" \n"[i==n-1];
    // }
    // for(int j=0; j<m; j++){
    //     cout<<colB[j]<<" \n"[j==m-1];
    // }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<ans[i][j];
        }
        cout<<"\n";
    }
}
int main(){
    setIO();
    int t; cin >> t; while(t--)
    solve();
    return 0;
}
 
/*
stuff you should look for
int overflow, array bounds
special cases (n=1?)
do smth instead of nothing and stay organized
WRITE STUFF DOWN
DON'T GET STUCK ON ONE APPROACH
*/