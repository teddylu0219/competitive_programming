#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	int mx = 0, mn = 101;
	int mxi, mni;
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		if (v[i] > mx) {
			mx = v[i];
			mxi = i;
		}
		if (v[i] <= mn) {
			mn = v[i];
			mni = i;
		}
	}
	cerr << mxi << ' ' << mni;
	if (mxi > mni) {
		cout << mxi + (n - 1 - mni - 1) << "\n";
	} else {
		cout << mxi + n - 1 - mni << "\n";
	}
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