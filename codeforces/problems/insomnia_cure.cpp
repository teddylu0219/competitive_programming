#include <bits/stdc++.h>
using namespace std;

void solve() {
	int k, l, m, n, d;
	cin >> k >> l >> m >> n >> d;
	vector<int> v(d + 1, 0);
	for (int i = k; i <= d; i += k) {
		v[i] = 1;
	}
	for (int i = l; i <= d; i += l) {
		v[i] = 1;
	}
	for (int i = m; i <= d; i += m) {
		v[i] = 1;
	}
	for (int i = n; i <= d; i += n) {
		v[i] = 1;
	}
	int sum = 0;
	for (auto& x : v) {
		sum += x;
	}
	cout << sum << "\n";
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