#include <bits/stdc++.h>
using namespace std;

void solve() {
	int x, y, m;
	cin >> x >> y >> m;
	int ans = 0;
	for (int i = 0; i <= 1000; ++i) {
		for (int j = 0; j <= 1000; ++j) {
			int sum = x * i + y * j;
			if (sum <= m) {
				ans = max(ans, sum);
			}
		}
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("pails.in", "r", stdin);
	freopen("pails.out", "w", stdout);
	
	int tt = 1;
	// cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;
}