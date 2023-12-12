#include<bits/stdc++.h>

using namespace std;

int32_t main() {
  int n, k, x;
  string str;
  cin >> n >> k >> x >> str;
  vector<int> pos;
  int cnt = 0;  // to store count of b
  for (int j = n - 1; j >= 0 && cnt < x; j--) {
    if (str[j] == 'b') {
      cnt++;
      pos.push_back(j);
    }
  }
  reverse(pos.begin(), pos.end());
  vector<int> pref(n + 1);  // prefix count of 'a'
  for (int i = 0; i < n; i++) pref[i + 1] = pref[i] + (str[i] == 'a');
  cnt = 0;  // to store count of a
  int prev = -1;
  string ans;
  for (int j = 0; j < x; j++) {
    if (cnt < k - x) {
      int temp = cnt;
      cnt = min(k - x, cnt + pref[pos[j] + 1] - pref[prev + 1]);
      for (int i = 0; i < (cnt - temp); i++) {
        ans.push_back('a');
      }
    }
    prev = pos[j];
    ans.push_back('b');
  }
  cout << ans;
  return 0;
}