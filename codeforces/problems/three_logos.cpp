#include <bits/stdc++.h>
using namespace std;

void solve() {
	vector<pair<int, int>> length(3);
	int area = 0;
	for (int i = 0; i < 3; ++i) {
		cin >> length[i].first >> length[i].second;
		area += (length[i].first * length[i].second);
	}
	int len = 1;
	while (len * len < area) {
		++len;
	}
	if (len * len > area) {
		cout << "-1\n";
		return;
	}
	// len * len == area
	for (int i = 0; i < (1 << 3); ++i) {
		vector<string> ans(len, string(len, '*'));
		int idx = 0;
		for (int j = 0; j < len; ++j) {
			for (int k = 0; k < len; ++k) {
				if (ans[j][k] == '*') {
					int w = length[idx].first;
					int h = length[idx].second;
					if (i & (1 << idx)) {
						swap(w, h);
					}
					for (int r = j; r < j + w; ++r) {
						for (int c = k; c < k + h; ++c) {
							if (r >= len || c >= len || ans[r][c] != '*') {
								goto outside;
							}
							ans[r][c] = 'A' + idx;
						}
					}
					++idx;
				}
			}
		}
		cout << len << "\n";
		for (auto& str : ans) {
			cout << str << "\n";
		}
		return;
		outside:;
	}
	cout << "-1\n";
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