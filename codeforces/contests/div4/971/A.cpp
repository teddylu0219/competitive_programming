#include <bits/stdc++.h>
using namespace std;

void debug(){ cerr << "\n"; }
template<class T, class ... U> void debug(T a, U ... b){ cerr << a << " ", debug(b ...); }

void solve() {
	int a, b;
	cin >> a >> b;
	cout << b - a << "\n";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	// freopen("", "r", stdin); freopen("", "w", stdout);
	int tt;
	cin >> tt;
	while (tt--) { solve(); }
	return 0;
}