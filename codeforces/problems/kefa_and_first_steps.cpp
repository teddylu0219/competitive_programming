#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	int ans = 0;
	int tmp = 1;
	int prev = v[0];
	for (int i = 1; i < n; ++i) {
		if (v[i] >= prev) {
			++tmp;
		} else {
			ans = max(ans, tmp);
			tmp = 1;
		}
		prev = v[i];
	}
	ans = max(ans, tmp);
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