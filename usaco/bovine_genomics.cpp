#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<string> v(n * 2);
	for (auto& str : v) {
		cin >> str;
	}
	vector<set<char>> f(m);
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j <= n - 1; ++j) {
			f[i].insert(v[j][i]);
		}
	}
	vector<bool> ans(m, true);
	for (int i = 0; i < m; ++i) {
		for (int j = n; j < n * 2; ++j) {
			if (f[i].count(v[j][i]) == 1) {
				ans[i] = false;
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < m; ++i) {
		if (ans[i]) {
			++cnt;
		}
	}
	cout << cnt << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("cownomics.in", "r", stdin);
	freopen("cownomics.out", "w", stdout);
	
	int tt = 1;
	// cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;
}