#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> stall(100, 0);
	for (int i = 0; i < n; ++i) {
		int s, t, e;
		cin >> s >> t >> e;
		--s;
		--t;
		for (int j = s; j <= t; ++j) {
			stall[j] = e;
		}
	}
	vector<array<int, 4>> cond(m);
	for (int i = 0; i < m; ++i) {
		int a, b, p, mi;
		cin >> a >> b >> p >> mi;
		--a;
		--b;
		cond[i] = {a, b, p, mi};
	}
	int ans = INT_MAX;
	vector<int> tmp = stall;
	for (int i = 0; i < (1 << m); ++i) {
		stall = tmp;
		int cost = 0;
		for (int j = 0; j < m; ++j) {
			if (i & (1 << j)) {
				int a = cond[j][0];
				int b = cond[j][1];
				int p = cond[j][2];
				int mi = cond[j][3];
				for (int k = a; k <= b; ++k) {
					stall[k] -= p;
				}
				cost += mi;
			}
		}
		bool ok = true;
		for (auto& x : stall) {
			if (x > 0) {
				ok = false;
				break;
			}
		}
		if (ok) {
			ans = min(ans, cost);
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
