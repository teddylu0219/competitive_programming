#include <bits/stdc++.h>
using namespace std;

void solve() {
	vector<int> v(7);
	for (int i = 0; i < 7; ++i) {
		cin >> v[i];
	}
	sort(v.begin(), v.end(), greater<int>());
	vector<int> ans;
	ans.push_back(v[0] - v[1]); // A
	ans.push_back(v[0] - v[2]); // B
	ans.push_back(v[0] - ans[0] - ans[1]);
	for (int i = 0; i < 3; ++i) {
		cout << ans[i] << " \n"[i == 2];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt = 1;
	// cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;
}