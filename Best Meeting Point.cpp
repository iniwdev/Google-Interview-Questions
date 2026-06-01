#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
  int n,m;
  cin>>n>>m;
  vector<vector<int>> a(n,vector<int> (m));
  for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>a[i][j];
  vector<int> x,y;
  for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(a[i][j]==1) x.push_back(i),y.push_back(j);
  sort(x.begin(),x.end());
  sort(y.begin(),y.end());
  vector<int> px(x.size()),py(y.size());
  px[0]=x[0];
  for(int i=1;i<x.size();i++) px[i]=px[i-1]+x[i];
  py[0]=y[0];
  for(int i=1;i<y.size();i++) py[i]=py[i-1]+y[i];
  int ans=INT_MAX;
  int l=x.size();
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      int cntx=upper_bound(x.begin(),x.end(),i)-x.begin();
      int cnty=upper_bound(y.begin(),y.end(),j)-y.begin();
      int distx=i*(2*cntx-l)+px[l-1]-2*(cntx > 0 ? px[cntx-1] : 0);
      int disty=j*(2*cnty-l)+py[l-1]-2*(cnty > 0 ? py[cnty-1] : 0);
      ans=min(ans,distx+disty);
    }
  }
  cout<<ans<<"\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) solve();
}