#include <bits/stdc++.h>
using namespace std;

#define int long long
bool is_better(int new_len, const string& new_str, int old_len, const string& old_str) {
  if (new_len != old_len) return new_len < old_len;
  int c1 = count(new_str.begin(), new_str.end(), '[');
  int c2 = count(old_str.begin(), old_str.end(), '[');
  return c1 > c2;
}
int valid(string& s, int i, int j, int len){
  int cnt = 0;
  int ii = i;
  while(i + len - 1 <= j && s.substr(i, len) == s.substr(ii, len)) {
    cnt++;
    i += len;
  }
  return cnt;
}
pair<int,string> f(vector<vector<pair<int,string>>>& dp, int i, int j, string& s){
  if(i > j) return {0, ""};
  if(j - i + 1 < 4) return {j - i + 1, s.substr(i, j - i + 1)};
  if(dp[i][j].first != INT_MAX) return dp[i][j];
  int len = j - i + 1;
  pair<int,string> ans = {len, s.substr(i, len)};
  for(int k = i; k < j; k++) {
    pair<int,string> left = f(dp, i, k, s);
    pair<int,string> right = f(dp, k + 1, j, s);
    int new_len = left.first + right.first;
    string new_str = left.second + right.second;
    if(is_better(new_len, new_str, ans.first, ans.second)) {
      ans = {new_len, new_str};
    }
  }
  for(int l = 1; l <= len / 2; l++){
    int t = valid(s, i, j, l);
    if(t > 1){
      pair<int,string> encoded_pattern = f(dp, i, i + l - 1, s);
      string prefix_str = to_string(t) + "[" + encoded_pattern.second + "]";
      pair<int,string> curr_ans = f(dp, i + t * l, j, s);
      int new_len = curr_ans.first + prefix_str.size();
      string new_str = prefix_str + curr_ans.second;
      if(is_better(new_len, new_str, ans.first, ans.second)){
        ans = {new_len, new_str};
      }
    }
  }
  return dp[i][j] = ans;
}

void solve(){
  string s;
  cin >> s;
  int n = s.size();
  vector<vector<pair<int,string>>> dp(n, vector<pair<int,string>>(n, {INT_MAX, ""}));
  cout << f(dp, 0, n - 1, s).second << "\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) solve();
}