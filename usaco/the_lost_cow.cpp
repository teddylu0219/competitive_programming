#include <bits/stdc++.h>
using namespace std;

void debug() { cerr << "\n"; }
template<class T, class ... U> void debug(T a, U ... b) { cerr << a << " ", debug(b ...); }

void solve() {
	int x, y;
	cin >> x >> y;
	int now_x = x;
	int dx = 1;
	int ans = 0;
	int sign = 1;
	while (1) {
		if (sign == 1) {
			if (now_x <= y && y <= x + dx) {
				ans += abs(now_x - y);
				break; 
			}
		}
		if (sign == -1) {
			if (x + dx <= y && y <= now_x) {
				ans += abs(now_x - y);
				break; 
			}
		}
		ans += abs(now_x - (x + dx));
		now_x = x + dx;
		dx *= (-2);
		sign = -sign;
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	freopen("lostcow.in", "r", stdin); freopen("lostcow.out", "w", stdout);
	int tt = 1;
	// int tt; cin >> tt;
	while (tt--) { solve(); }
	return 0;
}