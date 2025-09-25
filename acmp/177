#include <bits/stdc++.h>

// #pragma GCC optimize("03")
// #pragma GCC target("avx2")

inline void speedInput() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

class Event {
 public:
     int id, time, type;

     bool operator < (const Event& other) {
        return time < other.time;
     }
};

inline void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector <int> count(n);
    for (int i = 0; i < n; i++) {
        std::cin >> count[i];
    }

    std::vector <Event> events;
    std::vector <int> sizes(m);

    for (int i = 0; i < m; i++) {
        int s, a, d;
        std::cin >> s >> a >> d;

        events.push_back({i, a, 0});
        events.push_back({i, d, 1});

        sizes[i] = s;
    }

    std::sort(events.begin(), events.end());

    std::vector <int> cell(m, -1);

    for (auto i : events) {
        if (i.type == 0) {
            int to0 = -1, val = INT_MAX;
            for (int j = 0; j < n; j++) {
                if (sizes[i.id] <= count[j] && count[j] < val) {
                    val = count[j];
                    to0 = j;
                }
            }

            if (val != INT_MAX) {
                std::cout << "put cargo " << i.id + 1 << " to cell " << to0 + 1 << '\n';
                cell[i.id] = to0;
                count[to0] -= sizes[i.id];
                continue;
            }

            int id = -1, from = -1, to = -1;
            for (int id_ = 0; id_ < m; id_++) {
                if (cell[id_] == -1) {
                    continue;
                }

                int from_ = cell[id_];

                for (int to_ = 0; to_ < n; to_++) {
                    if (from_ == to_) {
                        continue;
                    }

                    if (sizes[i.id] <= count[from_] + sizes[id_] && sizes[id_] <= count[to_]) {
                        if (id == -1) {
                            id = id_;
                            from = from_;
                            to = to_;
                            continue;
                        }

                        if (sizes[id_] < sizes[id]) {
                            id = id_;
                            from = from_;
                            to = to_;
                        } else if (sizes[id_] == sizes[id]) {
                            if (count[from_] + sizes[id_] < count[from] + sizes[id]) {
                                id = id_;
                                from = from_;
                                to = to_;
                            } else if (count[from_] + sizes[id_] == count[from] + sizes[id]) {
                                if (count[to_] - sizes[id_] < count[to] - sizes[id]) {
                                    id = id_;
                                    from = from_;
                                    to = to_;
                                } else if (count[to_] - sizes[id_] == count[to] - sizes[id]) {
                                    if (id_ < id) {
                                        id = id_;
                                        from = from_;
                                        to = to_;
                                    } else if (id_ == id) {
                                        if (to_ < to) {
                                            id = id_;
                                            from = from_;
                                            to = to_;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }

            if (id == -1) {
                std::cout << "cargo " << i.id + 1 << " cannot be stored" << '\n';
            } else {
                std::cout << "move cargo " << id + 1 << " from cell " << from + 1 << " to cell " << to + 1 << '\n';
                count[from] += sizes[id];
                count[to] -= sizes[id];
                cell[id] = to;

                std::cout << "put cargo " << i.id + 1 << " to cell " << from + 1 << '\n';
                count[from] -= sizes[i.id];
                cell[i.id] = from;
            }
        } else {
            if (cell[i.id] == -1) {
                continue;
            }
            std::cout << "take cargo " << i.id + 1 << " from cell " << cell[i.id] + 1 << '\n';
            count[cell[i.id]] += sizes[i.id];
            cell[i.id] = -1;
        }
    }
}

signed main() {
    speedInput();

    solve();

    return 0;
}
