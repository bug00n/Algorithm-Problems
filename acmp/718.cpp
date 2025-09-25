#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
// #pragma GCC target("avx2")
#define LOCAL

void speedInput() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
}

int dp[201][100][200];
std::string types[100];

void solve() {
    int n, l;
    std::cin >> n >> l;

    for (int i = 0; i < n; i++) {
        std::cin >> types[i];
    }

    std::string s;
    std::cin >> s;

    for (int cnt = 1; cnt <= (int) s.size(); cnt++) {
        for (int j = 0; j < l && j + ((int) s.size() / cnt) < l + 1; j++) {
            for (int k = 0; k < std::min((int) s.size(), cnt); k++) {
                for (int i = 0; i < n; i++) {
                    int curJ = j;
                    while (curJ < l && k + (curJ - j) * cnt < (int) s.size() && types[i][curJ] == s[k + (curJ - j) * cnt]) {
                        curJ++;
                    }

                    if ((int) s.size() <= k + (curJ - j) * cnt) {
                        dp[cnt][j][k] = i + 1;
                        break;
                    }
                }
            }

            if (j == l - 1) {
                std::deque <int> ids;

                int len = 0;
                while (len < cnt && dp[cnt][j][len]) {
                    ids.push_back(dp[cnt][j][len]);
                    len++;
                }

                int len2 = len;
                if (j != l - 1) {
                    while (len2 < cnt && dp[cnt][j + 1][len2]) {
                        ids.push_back(dp[cnt][j + 1][len2]);
                        len2++;
                    }
                }

                if (len2 == cnt) {
                    std::cout << cnt << '\n';

                    for (int x = 0; x < len2 - len; x++) {
                        int t = ids.back();
                        ids.pop_back();
                        ids.push_front(t);
                    }

                    for (auto i : ids) {
                        std::cout << i << ' ';
                    }
                    return;
                }
            }

            int sj = j - 1;
            if (0 <= sj) {
                std::deque <int> ids;

                int len = 0;
                while (len < cnt && dp[cnt][sj][len]) {
                    ids.push_back(dp[cnt][sj][len]);
                    len++;
                }

                int len2 = len;
                if (sj != l - 1) {
                    while (len2 < cnt && dp[cnt][sj + 1][len2]) {
                        ids.push_back(dp[cnt][sj + 1][len2]);
                        len2++;
                    }
                }

                if (len2 == cnt) {
                    std::cout << cnt << '\n';

                    for (int x = 0; x < len2 - len; x++) {
                        int t = ids.back();
                        ids.pop_back();
                        ids.push_front(t);
                    }

                    for (auto i : ids) {
                        std::cout << i << ' ';
                    }
                    return;
                }
            }
        }
    }

    std::cout << -1 << '\n';
}

signed main() {
    speedInput();

    solve();

    return 0;
}
