#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	n *= 2;
	vector<int> w(n);
	for (int i = 0; i < n; ++i) {
		cin >> w[i];
	}
	sort(w.begin(), w.end());
	int ans = INT_MAX;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			vector<int> tmp = w;
			int sum = 0;
			tmp.erase(tmp.begin() + i);
			tmp.erase(tmp.begin() + j - 1);
			for (int k = 0; k < n - 2; k += 2) {
				int dw = abs(tmp[k] - tmp[k + 1]);
				sum += dw;
			}
			ans = min(ans, sum);
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