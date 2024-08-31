#include <bits/stdc++.h>
using namespace std;

void solve() {
	vector<int> v(101);
	int n, m;
	cin >> n >> m;
	int tmp = 1;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		for (int j = tmp; j <= tmp + a - 1; ++j) {
			v[j] = b;
		}
		tmp += a;
	}
	tmp = 1;
	int ans = 0;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		for (int j = tmp; j <= tmp + a - 1; ++j) {
			if (b > v[j]) {
				ans = max(ans, b - v[j]);
			}
		}
		tmp += a;
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("speeding.in", "r", stdin);
	freopen("speeding.out", "w", stdout);
	
	int tt = 1;
	// cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;
}