#include <bits/stdc++.h>

// #include <bits/extc++.h>
#include <ext/pb_ds/assoc_container.hpp> // for any container
#include <ext/pb_ds/tree_policy.hpp> // pbds::tree

/*
	general(set): tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
	multi: less<typename> -> less_equal<typename>
	low version g++: null_type -> null_mapped_type
	map: null_type -> typename
*/



using namespace std;
using namespace __gnu_pbds; // pbds

void solve() {
	int N, Q;
	string T;
	cin >> N >> Q >> T;
	
	tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> tre;
	for (int i = 0; i < N; ++i) {
		if (T[i] == '1') {
			tre.insert(i);
		}
	}
	while (Q--) {
		int c, k;
		cin >> c >> k;
		if (c == 0) { // insert
			tre.insert(k);
		} else if (c == 1) { // delete
			tre.erase(k);
		} else if (c == 2) { // existence
			if (tre.find(k) == tre.end()) {
				cout << "0\n";
			} else {
				cout << "1\n";
			}
		} else if (c == 3) { // successor: the smallest key which is greater than or equal to k
			auto it = tre.lower_bound(k);
			if (it != tre.end()) {
				cout << *it << "\n";
			} else {
				cout << "-1\n";
			}
		} else if (c == 4) { // predecessor: the largest key which is smaller than or equal to k
			auto it = tre.upper_bound(k);
    		if (it != tre.begin()) {
    			cout << *(--it) << "\n";
    		} else {
    			cout << "-1\n";
    		}
		}
	}
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