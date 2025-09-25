#include <bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx2")
#define LOCAL

using namespace std;

void speedInput() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << setprecision(15) << fixed;

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
}

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<vector<int>> dp(n + 1, vector<int> (2, -1));
    vector<vector<int>> sign(n + 1, vector<int> (2, -1));

    dp[1][0] = 0;
    dp[1][1] = 1;

    sign[1][0] = 0;
    sign[1][1] = 1;

    for (int len = 2; len <= n; len++) {
        int prevZ = dp[len - 1][0];
        int prevO = dp[len - 1][1];

        if (s[0] == '0' && prevZ != -1 && dp[len][0] < prevZ) {
            dp[len][0] = prevZ;
            sign[len][0] = 0;
        }
        if (s[1] == '0' && prevZ != -1 && dp[len][0] < prevZ + 1) {
            dp[len][0] = prevZ + 1;
            sign[len][0] = 1;
        }
        if (s[2] == '0' && prevO != -1 && dp[len][0] < prevO) {
            dp[len][0] = prevO;
            sign[len][0] = 0;
        }
        if (s[3] == '0' && prevO != -1 && dp[len][0] < prevO + 1) {
            dp[len][0] = prevO + 1;
            sign[len][0] = 1;
        }

        if (s[0] == '1' && prevZ != -1 && dp[len][1] < prevZ) {
            dp[len][1] = prevZ;
            sign[len][1] = 0;
        }
        if (s[1] == '1' && prevZ != -1 && dp[len][1] < prevZ + 1) {
            dp[len][1] = prevZ + 1;
            sign[len][1] = 1;
        }
        if (s[2] == '1' && prevO != -1 && dp[len][1] < prevO) {
            dp[len][1] = prevO;
            sign[len][1] = 0;
        }
        if (s[3] == '1' && prevO != -1 && dp[len][1] < prevO + 1) {
            dp[len][1] = prevO + 1;
            sign[len][1] = 1;
        }
    }

    if (dp[n][1] == -1) {
        cout << "No solution" << '\n';
        return;
    }

    int curSign = 1;
    vector <int> path;

    for (int i = n - 1; 0 < i; i--) {
        if (s[0] - '0' == curSign && dp[i + 1][curSign] == dp[i][0] && dp[i][0] != -1) {
            path.push_back(0);
            curSign = 0;
        }
        else if (s[1] - '0' == curSign && dp[i + 1][curSign] == dp[i][0] + 1 && dp[i][0] != -1) {
            path.push_back(1);
            curSign = 0;
        }
        else if (s[2] - '0' == curSign && dp[i + 1][curSign] == dp[i][1] && dp[i][1] != -1) {
            path.push_back(0);
            curSign = 1;
        }
        else if (s[3] - '0' == curSign && dp[i + 1][curSign] == dp[i][1] + 1 && dp[i][1] != -1) {
            path.push_back(1);
            curSign = 1;
        }
    }
    path.push_back(curSign);

    ranges::reverse(path.begin(), path.end());

    for (auto i : path) {
        cout << i;
    }
}

signed main() {
    speedInput();

    int32_t t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
