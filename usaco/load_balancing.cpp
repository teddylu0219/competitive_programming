#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, b;
	cin >> n >> b;
	vector<int> x(n);
	vector<int> y(n);
	set<int> xf;
	set<int> yf;
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
		xf.insert(x[i] + 1);
		yf.insert(y[i] + 1);
	}
	int ans = INT_MAX;
	int c1, c2, c3, c4;
	c1 = c2 = c3 = c4 = 0;
	for (auto& xx : xf) {
		for (auto& yy : yf) {
			for (int i = 0; i < n; ++i) {
				 if (x[i] > xx && y[i] > yy) {
				 	++c1;
				 }
				 if (x[i] < xx && y[i] > yy) {
				 	++c2;
				 }
				 if (x[i] < xx && y[i] < yy) {
				 	++c3;
				 }
				 if (x[i] > xx && y[i] < yy) {
				 	++c4;
				 }
			}
			int tmp = max({c1, c2, c3, c4});
			ans = min(ans, tmp);
			c1 = c2 = c3 = c4 = 0;
		}
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	// freopen("balancing.in", "r", stdin);
	// freopen("balancing.out", "w", stdout);	
	
	int tt = 1;
	// cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;
}