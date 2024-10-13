#include <bits/stdc++.h>
using namespace std;

void debug() { cerr << "\n"; }
template<class T, class ... U> void debug(T a, U ... b) { cerr << a << " ", debug(b ...); }

void solve() {
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	// n = a * x + b * y + c * z
	// Find max of x + y + z
	int ans = 1;
	for (int x = 0; x <= 4000; ++x) {
		for (int y = 0; y <= 4000; ++y) {
			if (a * x + b * y > n) continue;
			else {
				int rest = n - a * x - b * y;
				if (rest % c == 0) {
					ans = max(ans, x + y + rest / c);
				}
			}
		}
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	// freopen("", "r", stdin); freopen("", "w", stdout);
	int tt = 1;
	// int tt; cin >> tt;
	while (tt--) { solve(); }
	return 0;
}