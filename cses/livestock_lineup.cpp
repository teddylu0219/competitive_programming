#include <bits/stdc++.h>
using namespace std;

vector<string> names = {
	"Bessie", "Buttercup", "Belinda", "Beatrice", 
	"Bella", "Blue", "Betsy", "Sue"
};

bool check(vector<pair<string, string>>& constraints) {
	for (auto& constraint : constraints) {
		string name1 = constraint.first;
		string name2 = constraint.second;
		int i = 0;
		while (i < 8 && names[i] != name1) {
			++i;
		}
		if (i == 0) {
			if (names[i + 1] != name2) {
				return false;
			}
		} else if (i == 7) {
			if (names[i - 1] != name2) {
				return false;
			}
		} else {
			if (names[i + 1] != name2 && names[i - 1] != name2) {
				return false;
			}
		}
	}
	return true;
}

void solve() {
	int n;
	cin >> n;
	vector<pair<string, string>> constraints(n);
	for (int i = 0; i < n; ++i) {
		string name1, name2, tmp;
		cin >> name1;
		for (int j = 0; j < 4; ++j) {
			cin >> tmp;
		}
		cin >> name2;
		constraints[i] = {name1, name2};
	}
	sort(names.begin(), names.end());
	do {
		if (check(constraints)) {
			for (auto& name : names) {
				cout << name << "\n";
			}
			break;
		}
	} while (next_permutation(names.begin(), names.end()));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("lineup.in", "r", stdin);
	freopen("lineup.out", "w", stdout);	
	
	int tt = 1;
	// cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;
}