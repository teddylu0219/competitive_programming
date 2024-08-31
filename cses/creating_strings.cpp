#include <bits/stdc++.h>
using namespace std;

void solve() {
	string s;
	vector<string> ans;
	cin >> s;
	sort(s.begin(), s.end());
	do {
		ans.push_back(s);
	} while (next_permutation(s.begin(), s.end()));
	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (auto& x : ans) {
		cout << x << "\n";
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