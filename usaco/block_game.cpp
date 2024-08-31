#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> ans(26, 0);
	while (n--) {
		string a, b;
		cin >> a >> b;
		vector<int> f1(26, 0);
		vector<int> f2(26, 0);
		for (auto& ch : a) {
			++f1[ch - 'a'];
		}
		for (auto& ch : b) {
			++f2[ch - 'a'];
		}
		for (int i = 0; i < 26; ++i) {
			f1[i] = max(f1[i], f2[i]);
		}
		for (int i = 0; i < 26; ++i) {
			ans[i] += f1[i];
		}
	}
	for (auto& x : ans) {
		cout << x << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("blocks.in", "r", stdin);
	freopen("blocks.out", "w", stdout);
	
	int tt = 1;
	// cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;
}