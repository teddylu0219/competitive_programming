#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int n, m, d;

int main() {
    cin >> n >> m >> d;
    int L = n + m - 2;
    vector<string> grid(n, string(m, '#'));
    bool found = false;
    int loop_a = -1, loop_b = -1, loop_k = -1;
    for (int a = 2; a <= n && !found; ++a) {
        for (int b = 2; b <= m && !found; ++b) {
            int s = 2 * (a + b) - 4;
            if ((d - L) % s == 0) {
                int k = (d - L) / s;
                if (k >= 0) {
                    loop_a = a;
                    loop_b = b;
                    loop_k = k;
                    found = true;
                }
            }
        }
    }
    if (!found) {
        // No suitable loop found, use minimal path
        loop_a = 2;
        loop_b = 2;
        loop_k = (d - L) / (2 * (loop_a + loop_b) - 4);
        if (loop_k < 0) loop_k = 0;
    }
    // Build the maze
    // Open the loop area
    for (int i = 0; i < loop_a; ++i) {
        for (int j = 0; j < loop_b; ++j) {
            grid[i][j] = '.';
        }
    }
    // Open the minimal path from (1,1) to (n,m)
    int x = 0, y = 0;
    while (x < n && y < m) {
        grid[x][y] = '.';
        if (x < n - 1) x++;
        else y++;
    }
    // Now simulate the path
    vector<pair<int, int>> path;
    x = 0;
    y = 0;
    path.push_back({x, y});
    // Simulate the loops
    for (int t = 0; t < loop_k; ++t) {
        // Move around the perimeter of the rectangle
        // Top edge
        for (int j = y + 1; j < loop_b; ++j) path.push_back({x, j});
        // Right edge
        for (int i = x + 1; i < loop_a; ++i) path.push_back({i, loop_b - 1});
        // Bottom edge
        for (int j = loop_b - 2; j >= y; --j) path.push_back({loop_a - 1, j});
        // Left edge
        for (int i = loop_a - 2; i > x; --i) path.push_back({i, y});
    }
    // Proceed along the minimal path to (n,m)
    x = 0;
    y = 0;
    while (x < n - 1) {
        x++;
        path.push_back({x, y});
    }
    while (y < m - 1) {
        y++;
        path.push_back({x, y});
    }
    // Adjust the path length to be exactly d
    if (path.size() > d) {
        path.resize(d);
    }
    // Mark the path in the grid
    for (auto p : path) {
        grid[p.first][p.second] = '.';
    }
    // Output the grid
    for (const auto& row : grid) {
        cout << row << endl;
    }
    return 0;
}
