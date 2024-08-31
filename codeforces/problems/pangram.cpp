#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> fre(26, 0);
	for (auto ch : s) {
		ch = tolower(ch);
		fre[ch - 'a']++;
	}
	//for (auto x : fre) cerr << x << endl;
	bool ok = true;
	for (auto x : fre) {
		if (x == 0) {
			ok = false;
			break;
		}
	}
	cout << (ok ? "YES" : "NO") << "\n";
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