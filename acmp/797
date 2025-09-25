#include <stdio.h>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

std::vector <int> minX(51, 51);
std::vector <int> maxX(51, 0);
int size;

class Pos {
public:
    int x, y, code;
};

int getCode(int x, int y) {
    int code = 0;
    for (int dy = 0; dy < size; dy++) {
        if (maxX[y + dy] == 0) {
            code |= 3 << (dy * 2);
        } else {
            if (x <= minX[y + dy] && minX[y + dy] < x + size) {
                code |= 1 << (dy * 2);
            }
            if (x <= maxX[y + dy] && maxX[y + dy] < x + size) {
                code |= 2 << (dy * 2);
            }
        }
    }
    return code;
}

int main() {
    int n;
    int maxy = 0;
    scanf("%d %d", &n, &size);

    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);

        minX[y] = std::min(x, minX[y]);
        maxX[y] = std::max(x, maxX[y]);
        maxy = std::max(maxy, y);
    }

    std::vector <std::vector <std::vector <int>>> len(52 - size, std::vector <std::vector <int>>(52 - size, std::vector <int> ((1 << (2 * size)), -1)));
    std::queue <Pos> inProcess;
    
    {
        int code = getCode(1, 1);
        len[1][1][code] = 0;
        inProcess.push({1, 1, code});
    }

    while (!inProcess.empty()) {
        Pos cur = inProcess.front();
        inProcess.pop();

        if ((cur.y >= maxy + 1 - size) && cur.code == (1 << (size << 1)) - 1) {
            printf("%d", len[cur.x][cur.y][cur.code]);
            return 0;
        }

        if (cur.x > 1) {
            int nx = cur.x - 1;
            int ny = cur.y;
            int nc = cur.code | getCode(nx, ny);
            if (len[nx][ny][nc] == -1) {
                len[nx][ny][nc] = len[cur.x][cur.y][cur.code] + 1;
                inProcess.push({nx, ny, nc});
            }
        }
        if (cur.x < 51 - size) {
            int nx = cur.x + 1;
            int ny = cur.y;
            int nc = cur.code | getCode(nx, ny);
            if (len[nx][ny][nc] == -1) {
                len[nx][ny][nc] = len[cur.x][cur.y][cur.code] + 1;
                inProcess.push({nx, ny, nc});
            } 
        }
        if (cur.y < 51 - size && (cur.code & 3) == 3) {
            int nx = cur.x;
            int ny = cur.y + 1;
            int nc = (cur.code >> 2) | getCode(nx, ny);
            if (len[nx][ny][nc] == -1) {
                len[nx][ny][nc] = len[cur.x][cur.y][cur.code] + 1;
                inProcess.push({nx, ny, nc});
            }
        }
    }
    throw 1;
}   