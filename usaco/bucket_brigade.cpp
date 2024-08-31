#include <bits/stdc++.h>
using namespace std;

bool yAffect(int by, int ly, int ry) {
	if (by < ly) {
		if (ry < by || ry > ly) {
			return false;
		}
	} else {
		if (ry < ly || ry > by) {
			return false;
		}
	}
	return true;
}

bool xAffect(int bx, int lx, int rx) {
	if (bx < lx) {
		if (rx < bx || rx > lx) {
			return false;
		}
	} else {
		if (rx < lx || rx > bx) {
			return false;
		}
	}
	return true;
}

void solve() {
	char grid[10][10];
	int bx, by, lx, ly, rx, ry;
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			cin >> grid[i][j];
			if (grid[i][j] == 'B') {
				bx = i, by = j;
			} else if (grid[i][j] == 'L') {
				lx = i, ly = j;
			} else if (grid[i][j] == 'R') {
				rx = i, ry = j;
			}
		}
	}
	if (rx == bx && rx == lx && yAffect(by, ly, ry)) {
		cout << abs(by - ly) - 1 + 2;
	} else if (ry == by && ry == ly && xAffect(bx, lx, rx)) {
		cout << abs(bx - lx) - 1 + 2;
	} else {
		//cerr << abs(bx - lx) - 1 << endl;
		//cerr << abs(by - ly) - 1 << endl;
		cout << abs(bx - lx) - 1 + abs(by - ly) - 1 + 1;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("buckets.in", "r", stdin);
	freopen("buckets.out", "w", stdout);
	int tt = 1;
	// cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;
}