#include <bits/stdc++.h>
using namespace std;

map<string, int> faces = {
	{"Tetrahedron", 4}, {"Cube", 6}, {"Octahedron", 8}, 
	{"Dodecahedron", 12}, {"Icosahedron", 20}
};

void solve() {
	int n;
	cin >> n;
	string s;
	int sum = 0;
	while (n--) {
		cin >> s;
		sum += faces[s];
	}
	cout << sum << "\n";
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