#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	int ans = 0;
	vector<int> v = {100, 20, 10, 5, 1};
	for (int i = 0; i < 5; ++i) {
		if (n >= v[i]) {
			ans += (n / v[i]);
			n -= ((n / v[i]) * v[i]);
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