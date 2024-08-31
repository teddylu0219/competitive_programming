#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (int k = 1; k <= n; ++k) {
		set<string> oset;
		bool ok = true;
		for (int i = 0; i < n; ++i) {
			if (i + k - 1 >= n) {
				break;
			}
			string tmp{};
			for (int j = i; j < i + k; ++j) {
				tmp += s[j];
			}
			if (oset.count(tmp)) {
				ok = false;
				break;
			} else {
				oset.insert(tmp);
			}
		}
		// cerr << "k: " << k << "\n";
		// for (auto& x : oset) {
			// cerr << x << " ";
		// }
		// cerr << "\n";
		if (ok) {
			cout << k << "\n";
			return;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("whereami.in", "r", stdin);
	freopen("whereami.out", "w", stdout);	
	
	int tt = 1;
	// cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;
}