#include <bits/stdc++.h>
using namespace std;

void debug() { cerr << "\n"; }
template<class T, class ... U> void debug(T a, U ... b) { cerr << a << " ", debug(b ...); }

void solve() {
	int n;
	cin >> n;
	vector<int> to(n);
	for (int i = 0; i < n; ++i) {
		cin >> to[i];
	}
	vector<string> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	for (int i = 0; i < 3; ++i) {
		auto v_tmp = v;
		for (int j = 0; j < n; ++j) {
			v[j] = v_tmp[to[j] - 1];
		}
	}
	for (auto& id : v) {
		cout << id << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	freopen("shuffle.in", "r", stdin); freopen("shuffle.out", "w", stdout);
	int tt = 1;
	// int tt; cin >> tt;
	while (tt--) { solve(); }
	return 0;
}