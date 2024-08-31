#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<array<int, 4>> cond;
vector<int> stall(100, 0);
int ans = INT_MAX;

void search(int k, vector<int>& v, int& cost) {
	if (k == m) {
		bool ok = true;
		for (auto& x : v) {
			if (x > 0) {
				ok = false;
				break;
			}
		}
		if (ok) {
			ans = min(ans, cost);
		}
	} else {
		// not add k
		search(k + 1, v, cost);
		
		// add k
		int a = cond[k][0], b = cond[k][1];
		int p = cond[k][2], mi = cond[k][3];
		for (int i = a; i <= b; ++i) {
			v[i] -= p;
		}
		cost += mi;
		search(k + 1, v, cost);
		
		// backtrack
		for (int i = a; i <= b; ++i) {
			v[i] += p;
		}
		cost -= mi;
	}
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		int s, t, e;
		cin >> s >> t >> e;
		--s;
		--t;
		for (int j = s; j <= t; ++j) {
			stall[j] = e;
		}
	}
	cond.resize(m);
	for (int i = 0; i < m; ++i) {
		int a, b, p, mi;
		cin >> a >> b >> p >> mi;
		--a;
		--b;
		cond[i] = {a, b, p, mi};
	}
	vector<int> tmp = stall;
	int cost = 0;
	search(0, tmp, cost);
	cout << ans << "\n";
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