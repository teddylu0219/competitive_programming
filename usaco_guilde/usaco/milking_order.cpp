#include <bits/stdc++.h>
using namespace std;

void debug(){ cerr << "\n"; }
template<class T, class ... U> void debug(T a, U ... b){ cerr << a << " ", debug(b ...); }

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> v(n + 1, -1);
	vector<int> order(m);
	vector<pair<bool, int>> isPut(n + 1, {false, -1}); // cow i is (not) put, index
	bool hasOne = false;
	for (int i = 0; i < m; ++i) {
		cin >> order[i];
		if (order[i] == 1) {
			hasOne = true;
		}
	}
	for (int i = 0; i < k; ++i) {
		int c, p;
		cin >> c >> p;
		v[p] = c;
		isPut[c] = {true, p};
	}
	if (isPut[1].first) {
		cout << isPut[1].second << "\n";
		return;
	}

	int tmpIdx = -1;
	int j = n;
	int l = 1, r = n;
	for (int i = m - 1; i >= 0; --i) {
		if (order[i] == 1) {
			tmpIdx = i;
			break;
		}
		if (isPut[order[i]].first) {
			j = isPut[order[i]].second - 1;
			r = j;
			continue;
		} 
		for (; j >= 1; --j) {
			if (v[j] == -1) {
				v[j] = order[i];
				isPut[order[i]] = {true, j};
				r = j - 1;
				break;
			}
		}
	}
	
	if (tmpIdx != -1) {
		j = 1;
		for (int i = 0; i < tmpIdx; ++i) {
			if (isPut[order[i]].first) {
				j = isPut[order[i]].second + 1;
				l = j;
				continue;
			} 
			for (; j <= n; ++j) {	
				if (v[j] == -1) {
					v[j] = order[i];
					isPut[order[i]] = {true, j};
					l = j + 1;
					break;
				}
			}
		}
	}

	// debug("test");
	// for (int i = 1; i <= n; ++i) {
		// cerr << v[i] << " ";
	// }
	// debug();
	// debug("hasOne", hasOne);
	if (!hasOne) {
		l = 1;
		r = n;
	} 
	// debug("l,r", l, r);
	for (int i = l; i <= r; ++i) {
		if (v[i] == -1) {
			cout << i << "\n";
			break;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	freopen("milkorder.in", "r", stdin); freopen("milkorder.out", "w", stdout);
	int tt = 1;
	// cin >> tt;
	while (tt--) { solve(); }
	return 0;
}