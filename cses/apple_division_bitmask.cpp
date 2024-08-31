#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<long long> v(n);
	long long sum = 0;
	for (auto& x : v) {
		cin >> x;
		sum += x;
	}
	long long ans = LONG_LONG_MAX;
	for (int i = 0; i < (1 << n); ++i) {
		long long subsum = 0;
		for (int j = 0; j < n; ++j) {
			if ((i & (1 << j)) != 0) {
				subsum += v[j];
			}
		}
		long long restsum = sum - subsum;
		ans = min(ans, abs(subsum - restsum));
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