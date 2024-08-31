#include <bits/stdc++.h>
using namespace std;

void solve() {
	int Q, op;
	long long k, v;
	cin >> Q;
	unordered_map<long long, long long> ump;
	while (Q--) {
		cin >> op;
		if (op == 0) {
			cin >> k >> v;
			ump[k] = v;
		} else if (op == 1) {
			cin >> k;
			cout << ump[k] << "\n";
		}
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