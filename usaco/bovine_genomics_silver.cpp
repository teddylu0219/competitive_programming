#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<string> v(n * 2);
	for (int i = 0; i < n * 2; ++i) {
		cin >> v[i];
	}
	set<tuple<char, char, char>> s[m][m][m];
	for (int i = 0; i < m; ++i) {
		for (int j = i + 1; j < m; ++j) {
			for (int k = j + 1; k < m; ++k) {
				for (int ii = 0; ii < n; ++ii) {
					s[i][j][k].insert({v[ii][i], v[ii][j], v[ii][k]});
				}
			}
		}
	}
	
	int ans = 0;
	bool ok[m][m][m];
	memset(ok, true, sizeof(ok));
	for (int i = 0; i < m; ++i) {
		for (int j = i + 1; j < m; ++j) {
			for (int k = j + 1; k < m; ++k) {
				for (int ii = n; ii < n * 2; ++ii) {
					if (s[i][j][k].count({v[ii][i], v[ii][j], v[ii][k]}) == 1) {
						ok[i][j][k] = false;
					}
				}
			}
		}
	}
	for (int i = 0; i < m; ++i) {
		for (int j = i + 1; j < m; ++j) {
			for (int k = j + 1; k < m; ++k) {
				if (ok[i][j][k]) {
					++ans;
				} 
			}
		}
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	// freopen("cownomics.in", "r", stdin);
	// freopen("cownomics.out", "w", stdout);	
	
	int tt = 1;
	// cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;
}