#include <stdio.h>
#include <vector>
#include <algorithm>
#include <functional>
#include <ctime>

const int USED = -1;
const int UNDEF = -1;
std::vector <std::vector <int>> MOVE =
                {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};


bool dfs(int n,
         int m,
         int curX,
         int curY,
         int len,
         std::vector <std::vector <short>>& table,
         std::vector <std::vector <short>>& way)
{
    way[curY][curX] = len;
    table[curY][curX] = USED;

    if (n * m == len) { 
        return true; 
    }

    int min = 9;

    for (auto next : MOVE) { // поиск минимума
        int x = next[0];
        int y = next[1];
        if (0 <= curY + y &&
            curY + y < n &&
            0 <= curX + x &&
            curX + x < m) {
            if (table[curY + y][curX + x] < min && table[curY + y][curX + x] != USED) {
                min = table[curY + y][curX + x];
            }
        }
    }
    int nextX = -1, nextY = -1;

    for (auto next : MOVE) { // поиск следующей вершины
        int x = next[0];
        int y = next[1];
        if (0 <= curY + y &&
            curY + y < n &&
            0 <= curX + x &&
            curX + x < m) {
            if (table[curY + y][curX + x] == min) {
                nextX = curX + x;
                nextY = curY + y;
            }
        }
    }

    if (nextX != -1) {
        for (auto next : MOVE) { // уменьшение вариантов хода
            int x = next[0];
            int y = next[1];
            if (0 <= nextY + y &&
                nextY + y < n &&
                0 <= nextX + x &&
                nextX + x < m &&
                table[nextY + y][nextX + x] != USED) {
                table[nextY + y][nextX + x]--;
            }
        }
        return dfs(n, m, nextX, nextY, len + 1, table, way);
    }
    else {
        return false;
    }
}


int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    std::vector <std::vector <short>> table(n, std::vector <short>(m, 0)); // таблица возможностей ходов 
    

    int curX = UNDEF;
    int curY = UNDEF;

    // заполнение таблицы ходов и поиск позиции коня
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < m; j++) {
            char buf;
            scanf(" %c", &buf);

            for (auto next:MOVE) { // добавление вариантов хода
                int x = next[0];
                int y = next[1];
                if (0 <= i + y &&
                    i + y < n &&
                    0 <= j + x &&
                    j + x < m) {
                    table[i + y][j + x]++;
                }
            }

            if (buf != '.') {
                curY = i;
                curX = j;

                for (auto next : MOVE) { // уменьшение вариантов хода
                    int x = next[0];
                    int y = next[1];
                    if (0 <= i + y &&
                        i + y < n &&
                        0 <= j + x &&
                        j + x < m) {
                        table[i + y][j + x]--;
                    }
                }
            }
        }
    }

    srand(time(NULL));
    while (true) {
        std::vector <std::vector <short>> way(n, std::vector <short>(m, UNDEF)); // ответ
        std::vector <std::vector <short>> copy = table;
        std::random_shuffle(begin(MOVE), end(MOVE));
        bool check = dfs(n, m, curX, curY, 1, copy, way);
        
        if (check) {
            
            for (auto i : way) {
                for (auto j : i) {
                    printf("%d ", j);
                }
                printf("\n");
            }
            return 0;
        }
    }
}
