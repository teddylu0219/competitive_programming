#include <bits/stdc++.h>
using namespace std;

struct Shake {
	int x, y, z;
};

bool cmp(Shake a, Shake b) {
	return a.x < b.x;
}

int n, t;
vector<bool> infect;
vector<Shake> shakeData;

bool check(int x, int k) {
	vector<bool> tmp(n, false);
	tmp[x] = true;
	vector<int> kk(n, k);
	for (auto& da : shakeData) {
		if (tmp[da.y] && !tmp[da.z] && kk[da.y]) {
			tmp[da.z] = true;
			--kk[da.y];
		} else if (!tmp[da.y] && tmp[da.z] && kk[da.z]) {
			tmp[da.y] = true;
			--kk[da.z];
		} else if (tmp[da.y] && tmp[da.z]) {
			if (kk[da.y]) kk[da.y]--;
			if (kk[da.z]) kk[da.z]--;
		}
	}
	if (tmp == infect) {
		return true;
	}
	return false;
}

void solve() {
	cin >> n >> t;
	string s;
	cin >> s;
	infect.resize(n);
	for (int i = 0; i < n; ++i) {
		infect[i] = (s[i] == '1');
	}
	for (int i = 0; i < t; ++i) {
		int x, y, z;
		cin >> x >> y >> z;
		--y;
		--z;
		shakeData.push_back({x, y, z});
	}
	sort(shakeData.begin(), shakeData.end(), cmp);
	unordered_set<int> ans;
	int mink = INT_MAX, maxk = -1;
	for (int i = 0; i < n; ++i) {
		for (int k = 0; k <= t; ++k) {
			if (check(i, k)) {
				ans.insert(i);
				mink = min(mink, k);
				maxk = max(maxk, k);
			}
		}
	}
	if (maxk == t) {
		cout << ans.size() << " " << mink << " Infinity\n";
	} else {
		cout << ans.size() << " " << mink << " " << maxk << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("tracing.in", "r", stdin);
	freopen("tracing.out", "w", stdout);	
	int tt = 1;
	// cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;
}