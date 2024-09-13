#include <bits/stdc++.h>
using namespace std;

void debug(){ cerr << "\n"; }
template<class T, class ... U> void debug(T a, U ... b){ cerr << a << " ", debug(b ...); }

void solve() {
	int n;
	cin >> n;
	string v[n];
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	vector<int> ans;
	for (int i = 0; i < n; ++i) {	
		for (int j = 0; j < 4; ++j) {
			if (v[i][j] == '#') {
				ans.push_back(j + 1);
				break;
			}
		}
	}
	reverse(ans.begin(), ans.end());
	for (auto& x : ans) {
		cout << x << " ";
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	// freopen("", "r", stdin); freopen("", "w", stdout);
	int tt;
	cin >> tt;
	while (tt--) { solve(); }
	return 0;
}