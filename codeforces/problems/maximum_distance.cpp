#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<pair<int, int>> p(n);
	for (int i = 0; i < n; ++i) {
		cin >> p[i].first;
	}
	for (int i = 0; i < n; ++i) {
		cin >> p[i].second;
	}
	int ans = 0;
	for (int i = 0; i < n - 1; ++i) {
		for (int j = i + 1; j < n; ++j) {
			int dx = p[i].first - p[j].first;
			int dy = p[i].second - p[j].second;
			int d = dx * dx + dy * dy;
			ans = max(ans, d);
		}
	}
	cout << ans << "\n";
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