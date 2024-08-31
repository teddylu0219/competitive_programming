#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	int sum = 0;
	for (auto& x : v) {
		cin >> x;
		sum += x;
	}
	if (sum == 0) {
		cout << "0\n";
		return;
	}
	for (int i = 1; i <= sum; ++i) {
		bool ok = true;
		if (sum % i != 0) {
			continue;
		}
		int now = 0;
		for (auto& x : v) {
			now += x;
			if (now > i) {
				ok = false;
				break;
			} else if (now == i) {
				now = 0;
			}
		}
		if (ok) {
			cout << n - sum / i << "\n";
			break;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt;
	cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;
}