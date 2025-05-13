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
   int n; cin>>n;
   vector<int>a(n);
   unordered_map<int,int>mpa;
   for(int i=0; i<n; i++){
        cin>>a[i];
        mpa[a[i]]++;
   }
   if(mpa.size()==2){
        int pp=-1;
        for(auto i:mpa){
            if(pp==-1){
                pp=i.s;
            }else{
                if(abs(pp-i.s)<=1){
                    cout<<"Yes\n";
                }else{
                    cout<<"No\n";
                }
            }
        }
        return;
   }else if(mpa.size()==1){
        cout<<"Yes\n";
        return;
   }

//    if(n==2){
//         cout<<"Yes\n"; return;
//    }
//    sort(all(a));
//    vector<int>ver1, ver2;//ver1=小大小大
//     for(int i=0;i<n;i++){
//         if(i%2){
//             ver1.push_back(a[i]);
//             ver2.push_back(a[n-i-1]);
//         }else{
//             ver2.push_back(a[i]);
//             ver1.push_back(a[n-i-1]);
//         }
//     }
//     for(int i=1;i<n-1;i++){
//         if(a[i-1]+a[i] == )
//     }
//------
//    for(int i=0;i<n;i++){
//         for(int j=i+1; j<n; j++){
//             if((sum*2-a[i]-a[j])%(n-1)){
//                 cout<<a[i]<<" "<<a[j]<<" ";
//                 cout<<"Yes\n"; return;
//             }
//         }
//    }
   cout<<"No\n";
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
1. Think Greedy
2. Think Brute Force
3. Think solution in reverse order
4. Think DP [ check constraints carefully ]
5. Check base cases for DP and prove solution for Greedy
6. Think Graph
*/