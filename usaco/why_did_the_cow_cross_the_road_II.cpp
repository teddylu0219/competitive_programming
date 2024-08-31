#include <bits/stdc++.h>
using namespace std;

void solve() {
	string s;
	cin >> s;
	vector<pair<int, int>> v(26, {-1, -1});
	int sz = s.size();
	for (int i = 0; i < sz; ++i) {
		if (v[s[i] - 'A'].first == -1) {
			v[s[i] - 'A'].first = i;
		} else {
			v[s[i] - 'A'].second = i;
		}
	}
	int ans = 0;
	for (int i = 0; i < 26; ++i) {
		for (int j = i + 1; j < 26; ++j) {
			if (v[i].first < v[j].first && v[j].first < v[i].second && v[i].second < v[j].second) {
				++ans;
			}
			if (v[j].first < v[i].first && v[i].first < v[j].second && v[j].second < v[i].second) {
				++ans;
			}
		}
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("circlecross.in", "r", stdin);
	freopen("circlecross.out", "w", stdout);
	
	int tt = 1;
	// cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;
}