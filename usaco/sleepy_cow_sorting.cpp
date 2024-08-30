#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	list<int> lis;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		lis.push_back(x);
	}
	int ans = 0;
	while (*lis.begin() != 1) {
		int pre = *prev(lis.end(), 1);
		auto idx = lis.end();
		for (auto it = prev(lis.end(), 2); it != prev(lis.begin(), 1); --it) {
			if (*it > pre) {
				if (*lis.begin() < pre) {
					idx = next(it, 1);
					break;
				} else {
					++it;
					for (; it != lis.end(); ++it) {
						if (*lis.begin() < *it) {
							idx = it;
							goto g1;
						}
					}
					idx = lis.end();
					goto g1;
				}
			} else {
				pre = *it;
			}
		}
		g1:;
		lis.insert(idx, *lis.begin());
		lis.erase(lis.begin());
		++ans;
	}
	int tailNum = 1;
	int pre = *prev(lis.end(), 1);
	for (auto it = prev(lis.end(), 2); it != lis.begin(); --it) {
		if (*it < pre) {
			++tailNum;
			pre = *it;
		} else {
			break;
		}
	}
	if (tailNum != n - 1) {
		ans += (n - tailNum);
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("sleepy.in", "r", stdin);
	freopen("sleepy.out", "w", stdout);
	
	int tt = 1;
	// cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;
}