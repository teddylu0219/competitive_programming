#include <bits/stdc++.h>
using namespace std;

void debug(){ cerr << "\n"; }
template<class T, class ... U> void debug(T a, U ... b){ cerr << a << " ", debug(b ...); }

vector<string> names = {
	"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"
};

bool check(string s1, string s2) {
	for (int i = 0; i < 7; ++i) {
		if (s1 == names[i] && s2 == names[i + 1]) {
			return true;
		}
		if (s2 == names[i] && s1 == names[i + 1]) {
			return true;
		}
	}
	return false;
}

void solve() {
	int n;
	cin >> n;
	vector<pair<string, string>> constraints(n);
	for (int i = 0; i < n; ++i) {
		string a, tmp, b;
		cin >> a;
		for (int j = 0; j < 4; ++j) {
			cin >> tmp;
		}
		cin >> b;
		constraints[i] = {a, b};
	}
	vector<vector<string>> ans;
	sort(names.begin(), names.end());
	do {
		bool ok = true;
		for (int i = 0; i < n; ++i) {
			if (!check(constraints[i].first, constraints[i].second)) {
				ok = false;
				break;
			}
		}
		if (ok) {
			ans.push_back(names);
		}
	} while(next_permutation(names.begin(), names.end()));
	sort(ans.begin(), ans.end());
	for (auto& name : ans[0]) {
		cout << name << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	// freopen("lineup.in", "r", stdin); freopen("lineup.out", "w", stdout);
	int tt = 1;
	// cin >> tt;
	while (tt--) { solve(); }
	return 0;
}