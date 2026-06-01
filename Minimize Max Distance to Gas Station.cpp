#include <bits/stdc++.h>
using namespace std;

#define int long long
const double eps=1e-6;
bool f(double mid,vector<int>& a,int k){
  for(int i=1;i<a.size();i++){
    if(a[i]-a[i-1]>mid){
      int dist=a[i]-a[i-1];
      int cnt=-1;
      int lo=1,hi=k;
      while(lo<=hi){
        int m=lo+(hi-lo)/2;
        if((double)dist/(m+1)<=mid) cnt=m,hi=m-1;
        else lo=m+1;
      }
      if(cnt==-1) return false;
      k-=cnt;
    }
  }
  return k>=0;
}
void solve(){
  int n,k;
  cin>>n>>k;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin>>a[i];
  int max_dist=0;
  for(int i=1;i<n;i++) max_dist=max(max_dist,a[i]-a[i-1]);
  double lo=0,hi=max_dist;
  double ans=0;
  for(int i=0;i<70;i++){
    double mid=lo+(hi-lo)/2;
    if(f(mid,a,k)) ans=mid,hi=mid;
    else lo=mid;
  }
  cout<<fixed << setprecision(6) << ans << "\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) solve();
}