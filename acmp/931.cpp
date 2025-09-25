#include <bits/stdc++.h>

// #pragma GCC optimize("03")
// #pragma GCC target("avx2")

void speedInput() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
}

class Coord {
 public:
   long double x, y;
   int id;
};
class Vector {
 public:
    long double x, y;

    Vector (Coord from, Coord to) {
        x = to.x - from.x;
        y = to.y - from.y;
    }

    long double operator ^ (const Vector& other) {
        return x * other.y - y * other.x;
    }

    long double len() {
        return sqrt(x * x + y * y);
    }
};

const long double EPS = 1e-8;

bool check(std::vector <Coord>& coords) {
    if ((int) coords.size() < 3) {
        return true;
    }

    Coord A = coords[0], B = coords[1], C = coords[2];
    long double R = Vector(A, C).len() / ((Vector(A, B) ^ Vector(A, C))) * Vector(C, B).len();
    for (int i = 3; i < (int) coords.size(); i++) {
        Coord C_ = coords[i];
        long double R_ = Vector(A, C_).len() / ((Vector(A, B) ^ Vector(A, C_))) * Vector(C_, B).len();
        if (abs(abs(R) - abs(R_)) > EPS) {
            return false;
        }
    }

    return true;
}
bool uniqueCheck(Coord A, Coord B, Coord C, Coord C_) {
    long double R = Vector(A, C).len() * Vector(C, B).len() / ((Vector(A, B) ^ Vector(A, C)));
    long double R_ = Vector(A, C_).len() * Vector(C_, B).len() / ((Vector(A, B) ^ Vector(A, C_)));
    return abs(abs(R) - abs(R_)) <= EPS;
}

void solveC() {
    int n;
    std::cin >> n;

    std::vector <Coord> coords(n);
    for (int i = 0; i < n; i++) {
        std::cin >> coords[i].x >> coords[i].y;
        coords[i].id = i + 1;
    }

    if (n < 5) {
        for (int i = 0; i < n / 2; i++) {
            std::cout << coords[i].id << ' ';
        } std::cout << '\n';
        for (int i = n / 2; i < n; i++) {
            std::cout << coords[i].id << ' ';
        }
        return;
    }

    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            for (int k = j + 1; k < 5; k++) {
                Coord A = coords[i];
                Coord B = coords[j];
                Coord C = coords[k];

                std::vector <Coord> first, second;
                first = {A, B, C};
                for (int index = 0; index < n; index++) {
                    if (coords[index].id != A.id && coords[index].id != B.id && coords[index].id != C.id) {
                        if (uniqueCheck(A, B, C, coords[index])) {
                            first.push_back(coords[index]);
                        } else {
                            second.push_back(coords[index]);
                        }
                    }
                }

                if (check(second)) {
                    if ((int) second.size() < 3) {
                        for (auto x : first) {
                            std::cout << x.id << ' ';
                        } std::cout << '\n';
                        for (auto x : second) {
                            std::cout << x.id << ' ';
                        }
                        return;
                    } else {
                        A = second[0];
                        B = second[1];
                        C = second[2];

                        second.clear();
                        second = {A, B, C};

                        for (int index = 0; index < n; index++) {
                            if (coords[index].id != A.id && coords[index].id != B.id && coords[index].id != C.id) {
                                if (uniqueCheck(A, B, C, coords[index])) {
                                    second.push_back(coords[index]);
                                }
                            }
                        }

                        for (auto x : first) {
                            std::cout << x.id << ' ';
                        } std::cout << '\n';
                        for (auto x : second) {
                            std::cout << x.id << ' ';
                        }
                        return;
                    }
                }
            }
        }
    }
}

signed main() {
    speedInput();

    solveC();

    return 0;
}
