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

char g[4][4][3], back[4][4][3], temp[4][4];
int overall[4][4];
int check(){
    memset(overall, 0, sizeof(overall));
    int cnt=0;
    for(int a=0;a<3;a++){
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(g[i][j][a] == '#'){
                    overall[i][j]++;
                }
            }
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(overall[i][j]!=1){
                return 0;
            }
        }
    }
    return 1;
}
void transl(int a, int di, int dj){
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            temp[i][j]='.';

    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(g[i][j][a] == '#'){
                if(i+di>3|| j+dj>3 || i+di<0 || j+dj<0) return;
                temp[i+di][j+dj] = g[i][j][a];
            }
        }
    }
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            g[i][j][a] = temp[i][j];
}
int translatecheck(){
    for(int ai=-3; ai<4; ai++){//g[i][j][0]'s transformation
        for(int aj=-3; aj<4; aj++){
            for(int bi=-3; bi<4; bi++){//g[i][j][1]'s transformation
                for(int bj=-3; bj<4; bj++){
                    for(int ci=-3; ci<4; ci++){//g[i][j][2]'s transformation
                        for(int cj=-3; cj<4; cj++){
                            transl(0, ai, aj);
                            transl(1, bi, bj);
                            transl(2, ci, cj);
                            int ok = check();
                            if(ok) return 1;
                            for(int a=0;a<3;a++)
                                for(int i=0;i<4;i++)
                                    for(int j=0;j<4;j++)
                                        g[i][j][a] = back[i][j][a];
                        }
                    }
                }
            }
        }
    }
    return 0;
}

void rotate(int a){
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            temp[i][j] = g[j][i][a];

    for(int i=0;i<4;i++){
        swap(temp[i][0], temp[i][3]);
        swap(temp[i][1], temp[i][2]);
        for(int j=0;j<4;j++)
            g[i][j][a] = temp[i][j];
    }
}

void solve(){
    for(int k=0;k<3;k++)
        for(int i=0; i<4;i++)
            for(int j=0;j<4;j++)
                cin>>g[i][j][k];
        
    for(int bi=0; bi<4; bi++){
        rotate(1);
        for(int ci=0; ci<4; ci++){
            rotate(2);

            for(int a=0;a<3;a++)
                for(int i=0;i<4;i++)
                    for(int j=0;j<4;j++)
                        back[i][j][a] = g[i][j][a];
                        
            if(translatecheck()){
                cout<<"Yes"; return;
            }
        }
    }
    cout<<"No";
}
int main(){
   setIO();
   //int t; cin >> t; while(t--)
     solve();
   return 0;
}
 
// memset(overall, 0, sizeof(overall));
// for(int a=0;a<3;a++){
//     for(int i=0;i<4;i++){
//         for(int j=0;j<4;j++){
//             if(g[i][j][a] == '#'){ 
//                 overall[i][j]++;
//             }
//         }
//     }
// }
// for(int i=0;i<4;i++){
//     for(int j=0;j<4;j++){
//         cout<<g[i][j][0]<<" \n"[j==3];
//     }
// }
// cout<<"-----------------------------\n";

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
