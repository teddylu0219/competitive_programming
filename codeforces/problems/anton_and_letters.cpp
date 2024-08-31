#include <bits/stdc++.h>
using namespace std;

void solve() {
	char c;
	set<char> s;
	while (cin >> c) {
		if (isalpha(c)) {
			s.insert(c);
		}
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