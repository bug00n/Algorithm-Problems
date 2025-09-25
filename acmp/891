#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <random>
#include <time.h>

class Situation {
public:
    char f1L, f2L, f1R, f2R;
    char l1L, l2L, l1R, l2R;
    char b1L, b2L, b1R, b2R;
    char r1L, r2L, r1R, r2R;
    char u1L, u2L, u1R, u2R;
    char d1L, d2L, d1R, d2R;

    void input() {
        scanf(" %c", &f1L);
        scanf(" %c", &f1R);
        scanf(" %c", &l1L);
        scanf(" %c", &l1R);
        scanf(" %c", &b1L);
        scanf(" %c", &b1R);
        scanf(" %c", &r1L);
        scanf(" %c", &r1R);
        scanf(" %c", &u1L);
        scanf(" %c", &u1R);
        scanf(" %c", &d1L);
        scanf(" %c", &d1R);
        
        scanf(" %c", &f2L);
        scanf(" %c", &f2R);
        scanf(" %c", &l2L);
        scanf(" %c", &l2R);
        scanf(" %c", &b2L);
        scanf(" %c", &b2R);
        scanf(" %c", &r2L);
        scanf(" %c", &r2R);
        scanf(" %c", &u2L);
        scanf(" %c", &u2R);
        scanf(" %c", &d2L);
        scanf(" %c", &d2R);
    }

    void output() {
        printf("\n");
        printf("%c%c %c%c %c%c %c%c %c%c %c%c\n", f1L, f1R, l1L, l1R, b1L, b1R, r1L, r1R, u1L, u1R, d1L, d1R);
        printf("%c%c %c%c %c%c %c%c %c%c %c%c\n", f2L, f2R, l2L, l2R, b2L, b2R, r2L, r2R, u2L, u2R, d2L, d2R);
    }

    bool isSolved() {
        if (f1L == f2L && f1R == f2R && f1L == f1R &&
            l1L == l2L && l1R == l2R && l1L == l1R &&
            b1L == b2L && b1R == b2R && b1L == b1R &&
            r1L == r2L && r1R == r2R && r1L == r1R &&
            u1L == u2L && u1R == u2R && u1L == u1R &&
            d1L == d2L && d1R == d2R && d1L == d1R) {
            return true;
        }
        return false;
    } 

    bool operator< (const Situation& a) const {
        if (f1L == a.f1L) {
            if (f2L == a.f2L) {
                if (f1R == a.f1R) {
                    if (f2R == a.f2R) {

                        if (l1L == a.l1L) {
                            if (l2L == a.l2L) {
                                if (l1R == a.l1R) {
                                    if (l2R == a.l2R) {

                                        if (b1L == a.b1L) {
                                            if (b2L == a.b2L) {
                                                if (b1R == a.b1R) {
                                                    if (b2R == a.b2R) {

                                                        if (r1L == a.r1L) {
                                                            if (r2L == a.r2L) {
                                                                if (r1R == a.r1R) {
                                                                    if (r2R == a.r2R) {

                                                                        if (u1L == a.u1L) {
                                                                            if (u2L == a.u2L) {
                                                                                if (u1R == a.u1R) {
                                                                                    if (u2R == a.u2R) {
                                                                                          
                                                                                        if (d1L == a.d1L) {
                                                                                            if (d2L == a.d2L) {
                                                                                                if (d1R == a.d1R) {
                                                                                                    if (d2R == a.d2R) {
                                                                                                        return false;
                                                                                                    } else {
                                                                                                        return d2R < a.d2R;
                                                                                                    }
                                                                                                } else {
                                                                                                    return d1R < a.d1R;
                                                                                                }
                                                                                            } else {
                                                                                                return d2L < a.d2L;
                                                                                            }
                                                                                        } else {
                                                                                            return d1L < a.d1L;
                                                                                        }

                                                                                    } else {
                                                                                        return u2R < a.u2R;
                                                                                    }
                                                                                } else {
                                                                                    return u1R < a.u1R;
                                                                                }
                                                                            } else {
                                                                                return u2L < a.u2L;
                                                                            }
                                                                        } else {
                                                                            return u1L < a.u1L;
                                                                        }

                                                                    } else {
                                                                        return r2R < a.r2R;
                                                                    }
                                                                } else {
                                                                    return r1R < a.r1R;
                                                                }
                                                            } else {
                                                                return r2L < a.r2L;
                                                            }
                                                        } else {
                                                            return r1L < a.r1L;
                                                        }

                                                    } else {
                                                        return b2R < a.b2R;
                                                    }
                                                } else {
                                                    return b1R < a.b1R;
                                                }
                                            } else {
                                                return b2L < a.b2L;
                                            }
                                        } else {
                                            return b1L < a.b1L;
                                        }

                                    } else {
                                        return l2R < a.l2R;
                                    }
                                } else {
                                    return l1R < a.l1R;
                                }
                            } else {
                                return l2L < a.l2L;
                            }
                        } else {
                            return l1L < a.l1L;
                        }

                    } else {
                        return f2R < a.f2R;
                    }
                } else {
                    return f1R < a.f1R;
                }
            } else {
                return f2L < a.f2L;
            }
        } else {
            return f1L < a.f1L;
        }
    }

    bool operator== (const Situation& a) const {
        return f1L == a.f1L && f2L == a.f2L && f1R == a.f1R && f2R == a.f2R &&
            l1L == a.l1L && l2L == a.l2L && l1R == a.l1R && l2R == a.l2R &&
            b1L == a.b1L && b2L == a.b2L && b1R == a.b1R && b2R == a.b2R &&
            r1L == a.r1L && r2L == a.r2L && r1R == a.r1R && r2R == a.r2R &&
            u1L == a.u1L && u2L == a.u2L && u1R == a.u1R && u2R == a.u2R &&
            d1L == a.d1L && d2L == a.d2L && d1R == a.d1R && d2R == a.d2R;
    }

    void reverseF() { // clock
        { // F
            char if1L = f1L;
            f1L = f2L;
            f2L = f2R;
            f2R = f1R;
            f1R = if1L;
        }

        char ir1L = r1L;
        char ir2L = r2L;

        { // R
            r1L = u2L;
            r2L = u2R;
        }
        { // U
            u2L = l2R;
            u2R = l1R;
        }
        { // L
            l1R = d1L;
            l2R = d1R;
        }
        { // D
            d1L = ir2L;
            d1R = ir1L;
        }
    }
    void reverseL() { // clock
        { // L
            char il1L = l1L;
            l1L = l2L;
            l2L = l2R;
            l2R = l1R;
            l1R = il1L;
        }

        char if1L = f1L, if2L = f2L;

        { // F
            f1L = u1L;
            f2L = u2L;
        }
        { // U
            u1L = b2R;
            u2L = b1R;
        }
        { // B
            b1R = d2L;
            b2R = d1L;
        }
        { // D
            d2L = if2L;
            d1L = if1L;
        }
    }
    void reverseU() { // clock
        { // U
            char iu1L = u1L;
            u1L = u2L;
            u2L = u2R;
            u2R = u1R;
            u1R = iu1L;
        }

        char if1L = f1L, if1R = f1R;

        { // F
            f1L = r1L;
            f1R = r1R;
        }
        { // R
            r1L = b1L;
            r1R = b1R;
        }
        { // B
            b1L = l1L;
            b1R = l1R;
        }
        { // L
            l1L = if1L;
            l1R = if1R;
        }
    }
    void reverseB() { // clock
        { // B
            char ib1L = b1L;
            b1L = b2L;
            b2L = b2R;
            b2R = b1R;
            b1R = ib1L;
        }

        char ir1R = r1R, ir2R = r2R;

        { // R
            r1R = d2R;
            r2R = d2L;
        }
        { // D
            d2R = l2L;
            d2L = l1L;
        }
        { // L
            l1L = u1R;
            l2L = u1L;
        }
        { // U
            u1L = ir1R;
            u1R = ir2R;
        }
    }
    void reverseR() { // clock
        { // R
            char ir1L = r1L;
            r1L = r2L;
            r2L = r2R;
            r2R = r1R;
            r1R = ir1L;
        }

        char if1R = f1R, if2R = f2R;

        { // F
            f1R = d1R;
            f2R = d2R;
        }
        { // D
            d1R = b2L;
            d2R = b1L;
        }
        { // B
            b1L = u2R;
            b2L = u1R;
        }
        { // U
            u1R = if1R;
            u2R = if2R;
        }
    }
    void reverseD() { // clock
        { // D
            char id1L = d1L;
            d1L = d2L;
            d2L = d2R;
            d2R = d1R;
            d1R = id1L;
        }

        char if2L = f2L, if2R = f2R;

        { // F
            f2L = l2L;
            f2R = l2R;
        }
        { // L
            l2L = b2L;
            l2R = b2R;
        }
        { // B
            b2L = r2L;
            b2R = r2R;
        }
        { // R
            r2L = if2L;
            r2R = if2R;
        }
    }
};

void bfs(Situation& start) {
    std::queue <Situation> inProcess;
    std::map <Situation, short> from;
    inProcess.push(start);

    Situation finish;

    std::vector <char> move = {'F', 'L', 'B', 'R', 'U', 'D'};
    srand(time(0));
    std::random_shuffle(move.begin(), move.end());

    int count = 0;

    while (!inProcess.empty()) {
        Situation cur = inProcess.front();
        inProcess.pop();

        if (cur.isSolved()) {
            finish = cur;
            break;
        }

        // Повороты
        {
            Situation next;
            for (char i : move) {
                next = cur;

                for (int j = 0; j < 3; j++) {
                    if (i == 'F') {
                        next.reverseF();
                        if (j == 0 || j == 2) {
                           
                            if (from.find(next) == from.end()) {
                                if (j == 0) {
                                    from[next] = 0;

                                }
                                else {
                                    from[next] = 1;

                                }
                                inProcess.push(next);
                            }
                        }
                    }
                    if (i == 'L') {
                        next.reverseL();
                        if (j == 0 || j == 2) {

                            if (from.find(next) == from.end()) {
                                if (j == 0) {
                                    from[next] = 2;

                                } else {
                                    from[next] = 3;

                                }
                                inProcess.push(next);
                            }
                        }
                    }

                    if (i == 'B') {
                        next.reverseB();
                        if (j == 0 || j == 2) {
                            if (from.find(next) == from.end()) {
                                if (j == 0) {
                                    from[next] = 4;

                                } else {
                                    from[next] = 5;

                                }
                                inProcess.push(next);
                            }
                        }
                    }
                    if (i == 'R') {
                        next.reverseR();
                        if (j == 0 || j == 2) {
                            if (from.find(next) == from.end()) {
                                if (j == 0) {
                                    from[next] = 6;

                                } else {
                                    from[next] = 7;

                                }
                                inProcess.push(next);
                            }
                        }
                    }
                    if (i == 'U') {
                        next.reverseU();
                        if (j == 0 || j == 2) {
                            if (from.find(next) == from.end()) {
                                if (j == 0) {
                                    from[next] = 8;

                                } else {
                                    from[next] = 9;

                                }
                                inProcess.push(next);
                            }
                        }
                    }
                    if (i == 'D') {
                        next.reverseD();
                        if (j == 0 || j == 2) {
                            if (from.find(next) == from.end()) {
                                if (j == 0) {
                                    from[next] = 10;

                                } else {
                                    from[next] = 11;

                                }
                                inProcess.push(next);
                            }
                        }
                    }
                }
            }
        }
    }

    std::string ans;

    while (!(finish == start)) {
        short prev = from[finish];

        if (prev == 0) {
            for (int j = 0; j < 3; j++) {
                finish.reverseF();
            }
            ans += 'F';
        }

        if (prev == 1) {
            finish.reverseF();
            ans += "'F";
        }


        if (prev == 2) {
            for (int j = 0; j < 3; j++) {
                finish.reverseL();
            }
            ans += 'L';
        }

        if (prev == 3) {
            finish.reverseL();
            ans += "'L";
        }


        if (prev == 4) {
            for (int j = 0; j < 3; j++) {
                finish.reverseB();
            }
            ans += 'B';
        }

        if (prev == 5) {
            finish.reverseB();
            ans += "'B";
        }

        if (prev == 6) {
            for (int j = 0; j < 3; j++) {
                finish.reverseR();
            }
            ans += 'R';
        }

        if (prev == 7) {
            finish.reverseR();
            ans += "'R";
        }

        if (prev == 8) {
            for (int j = 0; j < 3; j++) {
                finish.reverseU();
            }
            ans += 'U';
        }

        if (prev == 9) {
            finish.reverseU();
            ans += "'U";
        }

        if (prev == 10) {
            for (int j = 0; j < 3; j++) {
                finish.reverseD();
            }
            ans += 'D';
        }

        if (prev == 11) {
            finish.reverseD();
            ans += "'D";
        }
    }

    std::reverse(ans.begin(), ans.end());
    printf("%s", ans.c_str());
    return;
}

int main() {
    Situation start; start.input(); // start position of cube

    if (start.isSolved()) { // if start position is a solve
        printf("Solved");
        return 0;
    }

    bfs(start);
    return 0;
}   
