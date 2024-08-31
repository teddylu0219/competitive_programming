#include <bits/stdc++.h>
using namespace std;

const int N = 8;
int cnt = 0;
vector<string> board(N);
vector<bool> colValid(N, true);
vector<bool> diagValid1(2 * (N - 1) + 1, true);
vector<bool> diagValid2(2 * (N - 1) + 1, true);

void search(int y) {
	if (y == N) {
		++cnt;
		return;
	} else {
		 for (int x = 0; x < N; ++x) {
		 	if (board[y][x] == '.') {
		 		if (!colValid[x] || !diagValid1[x + y] || !diagValid2[x - y + N - 1]) {
		 			continue;
		 		}
		 		colValid[x] = diagValid1[x + y] = diagValid2[x - y + N - 1] = false;
		 		search(y + 1);
		 		colValid[x] = diagValid1[x + y] = diagValid2[x - y + N - 1] = true;
		 	}
		 }
	}
}

void solve() {
	for (int i = 0; i < N; ++i) {
		cin >> board[i];
	}
	search(0);
	cout << cnt << "\n";
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