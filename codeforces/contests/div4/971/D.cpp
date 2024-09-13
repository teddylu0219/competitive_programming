#include <bits/stdc++.h>
using namespace std;

#define int long long

void debug(){ cerr << "\n"; }
template<class T, class ... U> void debug(T a, U ... b){ cerr << a << " ", debug(b ...); }

void solve() {
	int n;
	cin >> n;
	vector<bool> y0(n, false);
	vector<bool> y1(n, false);
	int cnt1 = 0;
	int cnt2 = 0;
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		if (y == 0) {
			y0[x] = true;
			++cnt1;
		} else if (y == 1) {
			y1[x] = true;
			++cnt2;
		}
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (y0[i] && y1[i]) {
			ans += (cnt1 + cnt2 - 2);
		}
	}
	for (int i = 0; i < n - 2; ++i) {
		if (y0[i] && y0[i + 2] && y1[i + 1]) {
			++ans;
		}
		if (y1[i] && y1[i + 2] && y0[i + 1]) {
			++ans;
		}
	}
	cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	// freopen("", "r", stdin); freopen("", "w", stdout);
	int tt;
	cin >> tt;
	while (tt--) { solve(); }
	return 0;
}