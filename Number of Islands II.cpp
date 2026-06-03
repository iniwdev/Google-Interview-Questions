#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;

// Union-Find Disjoint Sets Library written in OOP manner, using both path compression and union by rank heuristics
class UnionFind {                                              // OOP style
private:
  vi p, rank, setSize;                       // remember: vi is vector<int>
  int numSets;
public:
  UnionFind(int N) {
    setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
    p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) { 
    if (!isSameSet(i, j)) { numSets--; 
    int x = findSet(i), y = findSet(j);
    // rank is used to keep the tree short
    if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
    else { p[x] = y; setSize[y] += setSize[x]; if (rank[x] == rank[y]) rank[y]++; } 
      } 
    }
  int numDisjointSets() { return numSets; }
  int sizeOfSet(int i) { return setSize[findSet(i)]; }
};
void solve(){
  int n,m;
  cin>>n>>m;
  vector<vector<int>> a(n,vector<int> (m,0));
  int l;
  cin>>l;
  UnionFind u(n*m);
  vector<int> ans;
  int cnt=0;
  int dr[]={-1, 1, 0, 0};
  int dc[]={0, 0, -1, 1};
  while(l--){
    int i,j;
    cin>>i>>j;
    if(a[i][j]==1){
      ans.push_back(cnt);
      continue;
    }
    a[i][j]=1;
    cnt++;
    int idx1=i*m+j;
    for(int k=0;k<4;k++){
      int ni=dr[k]+i,nj=dc[k]+j;
      if(ni<0 || ni>=n || nj<0 || nj>=m || a[ni][nj] == 0) continue;
      int idx2=ni*m+nj;
      if(!u.isSameSet(idx1,idx2)){
        u.unionSet(idx1,idx2);
        cnt--;
      }
    }
    ans.push_back(cnt);
  }
  for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
  cout<<"\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) solve();
}