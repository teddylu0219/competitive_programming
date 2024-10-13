#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")

void debug() { cerr << "\n"; }
template<class T, class ... U> void debug(T a, U ... b) { cerr << a << " ", debug(b ...); }

void solve() {
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	// n = a * x + b * y + c * z
	// Find max of x + y + z
	vector<int> v = {a, b, c};
	sort(v.begin(), v.end());
	a = v[0], b = v[1], c = v[2];
	int ans = 1;
	if (n % a == 0) {
		cout << n / a << "\n";
		return;
	}
	for (int x = 0; x <= 4000 && a * x <= n; ++x) {
		if (a * x == n) ans = max(ans, x);
		for (int y = 0; y <= 4000 && a * x + b * y <= n; ++y) {
			if (a * x + b * y == n) ans = max(ans, x + y);
			for (int z = 0; z <= 4000 && a * x + b * y + c * z <= n; ++z) {
				if (a * x + b * y + c * z == n) ans = max(ans, x + y + z);
			}
		}
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	// freopen("", "r", stdin); freopen("", "w", stdout);
	int tt = 1;
	// int tt; cin >> tt;
	while (tt--) { solve(); }
	return 0;
}