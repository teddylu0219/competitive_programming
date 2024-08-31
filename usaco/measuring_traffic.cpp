#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
	int n;
	cin >> n;
	vector<string> s(n);
	vector<int> l(n);
	vector<int> r(n);
	for (int i = 0; i < n; ++i) {
		cin >> s[i] >> l[i] >> r[i];
	}
	int a = 0, b = INT_MAX;
	for (int i = n - 1; i >= 0; --i) {
		if (s[i] == "on") {
			a -= r[i];
			b -= l[i];
			a = max(0LL, a);
		} else if (s[i] == "none") {
			a = max(a, l[i]);
			b = min(b, r[i]);
		} else if (s[i] == "off") {
			a += l[i];
			b += r[i];
		}
	}
	cout << a << " " << b << "\n";
	
	a = 0; 
	b = INT_MAX;
	for (int i = 0; i < n; ++i) {
		if (s[i] == "on") {
			a += l[i];
			b += r[i];
		} else if (s[i] == "none") {
			a = max(a, l[i]);
			b = min(b, r[i]);
		} else if (s[i] == "off") {
			a -= r[i];
			b -= l[i];
			a = max(0LL, a);
		}
	}
	cout << a << " " << b << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);
	
	int tt = 1;
	// cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;
}