#include <bits/stdc++.h>
using namespace std;

vector<char> tmp;
string s;
vector<bool> chosen;
int n;
set<string> ans;

void search() {
	if ((int)tmp.size() == n) {
		string p {};
		for (auto& x : tmp) {
			p += x;
		}
		ans.insert(p);
	} else {
		for (int i = 0; i < n; ++i) {
			if (chosen[i]) continue;
			chosen[i] = true;
			tmp.push_back(s[i]);
			search();
			chosen[i] = false;
			tmp.pop_back();
		}
	}
}

void solve() {
	cin >> s;
	n = s.size();
	chosen.resize(n, false);
	search();
	cout << ans.size() << "\n";
	for (auto& x : ans) {
		cout << x << "\n";
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