#include <bits/stdc++.h>
using namespace std;

void debug(){ cerr << "\n"; }
template<class T, class ... U> void debug(T a, U ... b){ cerr << a << " ", debug(b ...); }

#define int long long

void solve() {
	int x, y, k;
	cin >> x >> y >> k;
	int step_x = (x + k - 1) / k;
	int step_y = (y + k - 1) / k;
	if (step_x == step_y) {
		cout << step_x + step_y;
	} else if (abs(step_x - step_y) == 1) {
		if (step_y > step_x) {
			cout << step_x + step_y + 1;
		} else {
			cout << step_x + step_y;
		}
	} else {
		if (step_y > step_x) {
			cout << step_y * 2;
		} else {
			cout << step_x * 2 - 1;
		}
	}
	cout << "\n";
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	// freopen("", "r", stdin); freopen("", "w", stdout);
	int tt;
	cin >> tt;
	while (tt--) { solve(); }
	return 0;
}