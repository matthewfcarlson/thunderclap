#include "decls/data/game/global.h"
// data: globalV = DAT_004dcf00, zero = DAT_003f335c

struct V {
    int value;
    void set(const float*);
};
struct Elem {
    int a, b, c, d, e;
    char pad[4];
    V val;
    char tail[4];
};
struct X {
    char pad[8];
    int first[64];
    Elem elems[64];
    void run();
};
void X::run() {
    (*(V*)&DAT_004dcf00).set(&DAT_003f335c);
    int* p = first;
    volatile int* q = &elems[0].c;
    int n = 64;
    do {
        *p = 0;
        q[-2] = 0;
        q[1] = 0;
        q[0] = 0;
        q[-1] = 0;
        q[2] = 0;
        ((V*)(q + 4))->set(&DAT_003f335c);
        ++p;
        q += 8;
    } while (--n);
}