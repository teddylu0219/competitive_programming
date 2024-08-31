#include <bits/stdc++.h>
using namespace std;

void solve() {
	int k, n;
	cin >> k >> n;
	int a[11][21];
	for (int i = 1; i <= k; ++i) {
		for (int j = n; j >= 1; --j) {
			int x;
			cin >> x;
			a[i][x] = j;
		}
	}
	int ans = 0;
	int tmp1 = 0;
	int tmp2 = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			for (int ii = 1; ii <= k; ++ii) {
				if (a[ii][i] > a[ii][j]) {
					tmp1++;
				}
				if (a[ii][i] < a[ii][j]) {
					tmp2++;
				}
			}
			if (tmp1 == k || tmp2 == k) {
				++ans;
			}
			tmp1 = 0;
			tmp2 = 0;
		}
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("gymnastics.in", "r", stdin);
	freopen("gymnastics.out", "w", stdout);
	
	int tt = 1;
	// cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;
}