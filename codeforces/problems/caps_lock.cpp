#include<bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	int sz = s.size();
	bool flip = true;
	for (int i = 1; i < sz; ++i) {
		if (islower(s[i])) {
			flip = false;
		}
	}
	if (flip) {
		for (char& ch : s) {
			if (islower(ch)) ch = toupper(ch);
			else if (isupper(ch)) ch = tolower(ch);
		}
	}
	cout << s << "\n";
	return 0;
}
