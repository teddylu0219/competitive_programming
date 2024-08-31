#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	set<int> s;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		s.insert(x);
	}
	cout << s.size() << "\n";
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