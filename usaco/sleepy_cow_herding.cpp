#include <bits/stdc++.h>
using namespace std;

void solve() {
	vector<int> v(3);
	cin >> v[0] >> v[1] >> v[2];
	sort(v.begin(), v.end());
	int minAns = 2, maxAns = 0;
	if (v[1] - v[0] == 2 || v[2] - v[1] == 2) {
		minAns = 1;
	} else if (v[1] - v[0] == 1 && v[2] - v[1] == 1) {
		minAns = 0;
	}
	int d = max(v[1] - v[0], v[2] - v[1]);
	maxAns = d - 1;
	cout << minAns << "\n" << maxAns << "\n"; 
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("herding.in", "r", stdin);
	freopen("herding.out", "w", stdout);	
	
	int tt = 1;
	// cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;
}