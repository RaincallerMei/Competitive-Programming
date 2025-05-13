//RAiNcalleER
#include <bits/stdc++.h>
using namespace std;
 
//feels good to be home
 
using ll = long long;
 
void setIO(string name=""){
  ios_base::sync_with_stdio(0); cin.tie(0);
  if((int)name.size() > 0){freopen((name+".in").c_str(), "r", stdin); freopen((name+".out").c_str(), "w", stdout);}
}
const ll mod=1e9+7;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define all(x) (x).begin(), (x).end()
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
 
 //-------------------#### Long, long had been my road and far, far was the journey; I would go up and down to seek my heart's desire. ####---------------------
/*
1. Think Greedy
2. Think Brute Force
3. Think solution in reverse order
4. Think DP [ check constraints carefully ]
5. Check base cases for DP and prove solution for Greedy
6. Think Graph
*/

char a[11][11], b[11][11], x[31][31];
bool valid(int di, int dj){
    return di<=30 && dj<=30;
}
void solve(){
    int ha,wa,hb,wb,hx,wx; 
    cin>>ha>>wa;
    for(int i=0; i<ha; i++)for(int j=0; j<wa; j++)cin>>a[i][j];
    cin>>hb>>wb;
    for(int i=0; i<hb; i++)for(int j=0; j<wb; j++)cin>>b[i][j];
    cin>>hx>>wx;
    for(int i=0; i<hx; i++) for(int j=0; j<wx; j++){
        char q; cin>>q;
        if(q=='#') x[i+10][j+10]=q;
    }

    for(int addi=0; addi<=30; addi++) {
        for(int addj=0; addj<=30; addj++){
            for(int bddi=0; bddi<=30; bddi++) {
                for(int bddj=0; bddj<=30; bddj++){
                    char paint[31][31];
                    int no=0;

                    for(int ai=0; ai<ha; ai++) {
                        for(int aj=0; aj<wa; aj++){
                            int di = ai+addi, dj = aj+addj;
                            if(!valid(di, dj)){
                                no=1;
                                break;
                            }
                            if(a[ai][aj]=='#' && x[di][dj]=='#')
                                paint[di][dj]='#';
                        }
                    }
                    if(no) break; 

                    for(int bi=0; bi<hb; bi++) {
                        for(int bj=0; bj<wb; bj++){
                            int dbi = bi+bddi, dbj = bj+bddj;
                            if(!valid(dbi, dbj)){
                                no=1;
                                break;
                            }
                            if(b[bi][bj]=='#' && x[dbi][dbj]=='#')
                                paint[dbi][dbj]='#';
                        }
                    }
                    if(no) break;

                    for(int i=0;i<=30;i++){
                        for(int j=0;j<=30;j++){
                            if(paint[i][j]=='#' && paint[i][j]!=x[i][j] || x[i][j]=='#' && paint[i][j]!=x[i][j]){
                                no=1; break;
                            }
                        }
                    }
                    // if(addi==11&&addj==10&&bddi==10&&bddj==10){
                    //     for(int i=0;i<=30;i++){
                    //         for(int j=0;j<=30;j++){
                    //             if(paint[i][j]=='#'){
                    //                 cout<<i<<" "<<j<<"\n";
                    //             }
                    //         }
                    //     }
                    //     for(int i=0;i<=30;i++){
                    //         for(int j=0;j<=30;j++){
                    //             if(x[i][j]=='#'){
                    //                 cout<<i<<" "<<j<<"\n";
                    //             }
                    //         }
                    //     }
                    // }

                    if(!no){
                        cout<<"Yes\n"; return;
                    }
                }
            }
        }
    }
    cout<<"No\n";
}
int main(){
    setIO();
    //int t; cin >> t; while(t--)
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