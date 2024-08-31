#include <bits/stdc++.h>
using namespace std;

void solve() {
	int m, n, k;
	cin >> m >> n >> k;
	char c;
	string tmp {};
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> c;
			for (int ii = 0; ii < k; ++ii) {
				tmp += c;
			}
		}
		for (int j = 0; j < k; ++j) {
			cout << tmp << "\n";
		}
		tmp = "";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("cowsignal.in", "r", stdin);
	freopen("cowsignal.out", "w", stdout);
	
	int tt = 1;
	// cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;
}