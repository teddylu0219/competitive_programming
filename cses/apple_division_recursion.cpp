#include <bits/stdc++.h>
using namespace std;

vector<long long> g, v;
int n;
long long ans = LONG_LONG_MAX, sum = 0;

long long getSum(vector<long long>& v) {
	long long res = 0;
	for (auto& x : v) {
		res += x;
	}
	return res;
}

void search(int k) {
	if (k == n) {
		long long sum1 = getSum(g);
		long long sum2 = sum - getSum(g);
		ans = min(ans, abs(sum1 - sum2));
	} else {
		search(k + 1);
		
		g.push_back(v[k]);
		search(k + 1);
		
		g.pop_back();
	}
}

void solve() {
	cin >> n;
	v.resize(n);
	for (auto& x : v) {
		cin >> x;
		sum += x;
	}
	search(0);
	cout << ans << "\n";
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