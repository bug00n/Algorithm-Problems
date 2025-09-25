#include <bits/stdc++.h>

void speedInput() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
}

#define int short

class Substring {
public:
    int a, c, g, t;
    int start;

    bool operator < (const Substring& other) const {
        if (a == other.a) {
            if (c == other.c) {
                if (g == other.g) {
                    return t < other.t;
                } return g < other.g;
            } return c < other.c;
        } return a < other.a;
    }
};

signed main() {
    speedInput();

    std::string a, b;
    std::cin >> a >> b;

    int size = std::max((int) a.size(), (int) b.size());

    std::set <Substring> ans;
    std::vector <std::vector <Substring>> dp(2, std::vector <Substring> (size + 1, {0, 0, 0, 0, 0}));

    for (int i = 1; i <= (int) a.size(); i++) {
        for (int j = 0; j < (int) a.size(); j++) {
            if (i + j - 1 >= (int) a.size()) {
                continue;
            }

            dp[1][j] = dp[0][j];

            if (a[j + i - 1] == 'A') {
                dp[1][j].a++;
            }
            if (a[j + i - 1] == 'C') {
                dp[1][j].c++;
            }
            if (a[j + i - 1] == 'G') {
                dp[1][j].g++;
            }
            if (a[j + i - 1] == 'T') {
                dp[1][j].t++;
            }

            dp[1][j].start = j;

            ans.insert(dp[1][j]);
        }

        std::swap(dp[0], dp[1]);
    }

    int first = -1, second = -1;
    int maxLen = 0;

    for (int i = 0; i < size; i++) {
        dp[0][i] = {0, 0, 0, 0, 0};
    }

    for (int i = 1; i <= (int) b.size(); i++) {
        for (int j = 0; j < (int) b.size(); j++) {
            if (i + j - 1 >= (int) b.size()) {
                continue;
            }

            dp[1][j] = dp[0][j];

            if (b[j + i - 1] == 'A') {
                dp[1][j].a++;
            }
            if (b[j + i - 1] == 'C') {
                dp[1][j].c++;
            }
            if (b[j + i - 1] == 'G') {
                dp[1][j].g++;
            }
            if (b[j + i - 1] == 'T') {
                dp[1][j].t++;
            }

            if (ans.find(dp[1][j]) != ans.end()) {
                int curLen = dp[1][j].a + dp[1][j].c + dp[1][j].g + dp[1][j].t;

                Substring x = *ans.find({dp[1][j].a, dp[1][j].c, dp[1][j].g, dp[1][j].t});

                if (maxLen < curLen) {
                    first = x.start;
                    second = j;

                    maxLen = curLen;
                }
            }
        }

        std::swap(dp[0], dp[1]);
    }

    std::cout << maxLen << '\n';

    if (maxLen == 0) {
        return 0;
    }

    std::cout << first + 1 << ' ' << second + 1;
    return 0;
}
