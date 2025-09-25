#include <bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx2")

void speedInput() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

class Point {
 public:
    int x, y, id;

    long long operator %(Point other) {
        return 1ll * x * other.y - 1ll * y * other.x;
    }

    Point operator -(Point other) const {
        return {x - other.x, y - other.y, -1};
    }

    long long getLen() {
        return 1ll * x * x + 1ll * y * y;
    };
};

int color[1000], timer = 0; // 0 - red; 1 - blue; 2 - green
int nxt[1000][1000], used[1000][1000];
std::vector <int> from[1000][1000];
std::bitset<1000> arr[1000][1000];

const long double EPS = 1e-7;
const long double PI = 3.141592653589793;

inline void merging(int cur, int next) {
    if (used[cur][next] == timer) {
        int a = next, b = nxt[cur][next];
        color[cur] = 2;
        while (a != cur || b != next) {
            color[a] = 2;
            std::swap(a, b);
            b = nxt[b][a];
        }
        return;
    }
    if (used[cur][next] > 0) return;
    used[cur][next] = timer;
    arr[cur][next][cur] = 0;
    for (auto prev : from[cur][next]) {
        merging(prev, cur);
        arr[cur][next] |= arr[prev][cur];
    }
    if (arr[cur][next][cur]) color[cur] = std::max(color[cur], 1);
    arr[cur][next][cur] = 1;
}

int sign(int x) {
    if (x >= 0) return 1;
    return -1;
}

bool cmp(Point f, Point s) {
    if (sign(f.y) != sign(s.y)) return sign(f.y) > sign(s.y);

    if (sign(f.x) != sign(s.x)) {
        if (sign(f.y) == 1) return sign(f.x) > sign(s.x);
        if (sign(f.y) == -1) return sign(f.x) < sign(s.x);
    }

    if (f % s == 0) return f.getLen() < s.getLen();

    return f % s > 0;
}

bool cmp_(Point f, Point s) {
    if (sign(f.y) != sign(s.y)) return sign(f.y) > sign(s.y);

    if (sign(f.x) != sign(s.x)) {
        if (sign(f.y) == 1) return sign(f.x) > sign(s.x);
        if (sign(f.y) == -1) return sign(f.x) < sign(s.x);
    }

    if (f % s == 0) return true;

    return f % s > 0;
}

void solve() {
    int n, t;
    std::cin >> n >> t;

    std::vector <Point> points(n);
    for (int i = 0; i < n; i++) {
        std::cin >> points[i].x >> points[i].y;
        points[i].id = i;
    }

    for (int i = 0; i < n; i++) {
        std::vector <Point> curOrient;
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            curOrient.push_back(points[j]);
        }

        Point center = points[i];
        std::sort(curOrient.begin(), curOrient.end(), [&center](const Point& left, const Point& right){
            Point f = left - center, s = right - center;
            return cmp(f, s);
        });

        for (int j = 0; j < n; j++) {
            if (i == j) continue;

            Point ray = center - points[j];

            int l = -1, r = n - 1;
            while (r - l - 1) {
                int m = (l + r) / 2;

                Point mid = curOrient[m] - center;

                if (cmp_(ray, mid)) {
                    r = m;
                } else {
                    l = m;
                }
            }

            nxt[points[j].id][points[i].id] = curOrient[(r + t - 1) % (n - 1)].id;
            from[points[i].id][nxt[points[j].id][points[i].id]].push_back(points[j].id);
            arr[points[j].id][points[i].id][points[j].id] = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j || used[i][j]) continue;
            timer++;
            merging(i, j);
        }
    }

    for (int i = 0; i < n; i++) {
        if (color[i] == 0) std::cout << 'R';
        if (color[i] == 1) std::cout << 'B';
        if (color[i] == 2) std::cout << 'G';
    }
}

signed main() {
    speedInput();

    solve();

    return 0;
}
