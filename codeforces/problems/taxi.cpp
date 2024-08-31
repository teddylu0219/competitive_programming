#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> fre(5, 0);
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		++fre[x];
	}
	int sum = fre[4];
	fre[4] = 0;
	int min13 = min(fre[1], fre[3]);
	sum += min13;
	fre[1] -= min13;
	fre[3] -= min13;
	if (fre[3] != 0) {
		sum += fre[3];
		fre[3] = 0;
	}
	if (fre[1] != 0) {
		int min12 = min(fre[1] / 2, fre[2]);
		sum += min12;
		fre[1] -= (min12 * 2);
		fre[2] -= min12;
	}
	if (fre[1] == 0) { // rest 2
		sum += (fre[2] / 2);
		if (fre[2] % 2 != 0) {
			++sum;
		}
		fre[2] = 0;
	} else if (fre[2] == 0) { // rest1
		sum += (fre[1] / 4);
		if (fre[1] % 4 != 0) {
			++sum;
		}
		fre[1] = 0;
	} else { // one 1, many 2
		// 1 2 2 2 -> 2
		// 1 2 2 2 2 -> 3
		sum += (fre[2] / 2 + 1);
	}
	cout << sum << "\n";
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