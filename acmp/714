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

const long double EPS = 1e-10;

class Point {
 public:
    long double x, y;

    Point operator - (Point other) {
        return {x - other.x, y - other.y};
    }

    long double operator % (Point other) {
        return x * other.y - y * other.x;
    }

    long double getDist(Point other) {
        return sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
    }
};
class Circle {
 public:
    long double r;
    Point center;
};

Circle get(vector <Point> points) {
    Point f = {(points[0].x + points[1].x) / 2, (points[0].y + points[1].y) / 2};
    Point s = {(points[2].x + points[1].x) / 2, (points[2].y + points[1].y) / 2};

    Point orf = {-(points[0].y - points[1].y), (points[0].x - points[1].x)};
    Point ors = {-(points[2].y - points[1].y), (points[2].x - points[1].x)};

    long double k = -((f - s) % ors) / (orf % ors);
    Point center = {f.x + orf.x * k, f.y + orf.y * k};

    return {center.getDist(points[0]), center};
}

void solve() {
    vector <Point> points(4);
    for (int i = 0; i < 4; i++) {
        cin >> points[i].x >> points[i].y;
    }

    Circle o = get(points);

    if (fabs(o.center.getDist(points[3]) - o.center.getDist(points[0])) <= EPS) {
        cout << "Infinity" << '\n';
        cout << o.center.x << ' ' << o.center.y << ' ' << 0 << '\n';
        return;
    }

    int cnt = 0;
    Circle min = {INT_MAX, {0, 0}};

    for (int i = 1; i < 15; i++) {
        vector <Point> f, s;
        for (int j = 0; j < 4; j++) {
            if ((i >> j) & 1) {
                f.push_back(points[j]);
            } else {
                s.push_back(points[j]);
            }
        }
        if (f.size() == 3) {
            Circle x = get(f);
            if (x.center.getDist(s[0]) - EPS > x.center.getDist(f[0])) {
                cnt++;
                long double r = (x.center.getDist(s[0]) + x.center.getDist(f[0])) / 2;
                if (r < min.r) {
                    min = {r, x.center};
                }
            }
        } else if (f.size() == 2) {
            Point f_ = {(f[0].x + f[1].x) / 2, (f[0].y + f[1].y) / 2};
            Point s_ = {(s[0].x + s[1].x) / 2, (s[0].y + s[1].y) / 2};

            Point orf = {-(f[0].y - f[1].y), (f[0].x - f[1].x)};
            Point ors = {-(s[0].y - s[1].y), (s[0].x - s[1].x)};

            long double k = -((f_ - s_) % ors) / (orf % ors);
            Point center = {f_.x + orf.x * k, f_.y + orf.y * k};

            if (center.getDist(s[0]) - EPS > center.getDist(f[0])) {
                cnt++;
                long double r = (center.getDist(s[0]) + center.getDist(f[0])) / 2;
                if (r < min.r) {
                    min = {r, center};
                }
            }
        } else {
            Circle x = get(s);
            if (x.center.getDist(s[0]) - EPS > x.center.getDist(f[0])) {
                cnt++;
                long double r = (x.center.getDist(s[0]) + x.center.getDist(f[0])) / 2;
                if (r < min.r) {
                    min = {r, x.center};
                }
            }
        }
    }

    cout << cnt << '\n';
    cout << min.center.x << ' ' << min.center.y << ' ' << min.r << '\n';
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
