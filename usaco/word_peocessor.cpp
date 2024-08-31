#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<string> v(n);
	vector<int> len(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		len[i] = v[i].size();
	}
	int tmp = 0;
	for (int i = 0; i < n; ++i) {
		tmp += len[i];
		if (tmp <= k) {
			if (i != n - 1 && tmp + len[i + 1] > k) {
				cout << v[i];
			} else {
				cout << v[i] << " \n"[i == n - 1];
			}
		} else {
			cout << "\n";
			tmp = len[i];
			if (i != n - 1 && tmp + len[i + 1] > k) {
				cout << v[i];
			} else {
				cout << v[i] << " \n"[i == n - 1];	
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt = 1;
	freopen("word.in", "r", stdin);
	freopen("word.out", "w", stdout);
	// cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;
}