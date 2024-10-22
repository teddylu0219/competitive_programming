#include <bits/stdc++.h>
using namespace std;

void debug(){ cerr << "\n"; }
template<class T, class ... U> void debug(T a, U ... b){ cerr << a << " ", debug(b ...); }

struct Milk {
	int s, t, b;
};

void solve() {
	int n;
	cin >> n;
	vector<Milk> v(n);
	for (int i = 0; i < n; ++i) {
		int s, t, b;
		cin >> s >> t >> b;
		v[i] = {s, t, b};
	}
	int ans = -1;
	vector<int> time(1001, 0);
	for (auto& milk : v) {
		for (int i = milk.s; i <= milk.t; ++i) {
			time[i] += milk.b;
		}
	}
	for (int i = 1; i <= 1000; ++i) {
		ans = max(ans, time[i]);
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	freopen("blist.in", "r", stdin); freopen("blist.out", "w", stdout);
	int tt = 1;
	// cin >> tt;
	while (tt--) { solve(); }
	return 0;
}