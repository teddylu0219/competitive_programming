#include <bits/stdc++.h>
using namespace std;

void debug(){ cerr << "\n"; }
template<class T, class ... U> void debug(T a, U ... b){ cerr << a << " ", debug(b ...); }

void solve() {
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	int cnt = 0;
	bool flag = false;
	for (int i = 0; i < n; ++i) {
		if (a[i] == b[i]) {
			flag = false;
		} else if (!flag) {
			++cnt;
			flag = true;
		}
	}
	cout << cnt << "\n";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	freopen("breedflip.in", "r", stdin); freopen("breedflip.out", "w", stdout);
	int tt = 1;
	// cin >> tt;
	while (tt--) { solve(); }
	return 0;
}

