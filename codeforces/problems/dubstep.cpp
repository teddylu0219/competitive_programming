#include <bits/stdc++.h>
using namespace std;

void solve() {
	string s;
	getline(cin, s);
	int len = s.size();
	vector<string> ans;
	string tmp;
	for (int i = 0; i < len; ++i) {
		if (s[i] == 'W') {
			if (i + 2 < len && s[i + 1] == 'U' && s[i + 2] == 'B') {
				i += 2;
				if (tmp != "") {
					ans.push_back(tmp);
				}
				tmp = "";
			} else {
				tmp += s[i];
			}
		} else {
			tmp += s[i];
		}
	}
	if (tmp != "") {
		ans.push_back(tmp);
	}
	//for (auto x : ans) cerr << x << endl;
	int len2 = ans.size();
	for (int i = 0; i < len2; ++i) {
		cout << ans[i] << " \n"[i == len2 - 1];
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