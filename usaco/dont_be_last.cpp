#include <bits/stdc++.h>
using namespace std;

vector<string> names {
	"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"
};

bool cmp(pair<string, int> a, pair<string, int> b) {
	return a.second < b.second;
}

void solve() {
	map<string, int> omap;
	for (int i = 0; i < 7; ++i) {
		omap[names[i]] = 0;
	}
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		int x;
		cin >> x;
		omap[s] += x; 
	}
	vector<pair<string, int>> v;
	for (auto& x : omap) {
		v.push_back(x);
	}
	sort(v.begin(), v.end(), cmp);
	// for (auto& x : v) {
		// cerr << x.first << " " << x.second << "\n";
	// }
	int sz = v.size();
	for (int i = 1; i < sz; ++i) {
		if (v[i].second > v[0].second) {
			if (i + 1 < sz && v[i + 1].second == v[i].second) {
				cout << "Tie\n";
				return;
			} else {
				cout << v[i].first << "\n";
				return;
			}
		}
	}
	cout << "Tie\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("notlast.in", "r", stdin);
	freopen("notlast.out", "w", stdout);	
	
	int tt = 1;
	// cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;
}