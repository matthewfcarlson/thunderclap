#include "decls/data/game/global.h"
// data: globalV = DAT_004dcf00, zero = DAT_003f335c
#include "gen/owners.h"

struct V {
    int value;
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
    ((owners::Target_27b040 *)&((*(V*)&DAT_004dcf00)))->FUN_0027b040((hulk_uintptr)(&DAT_003f335c));
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
        ((owners::Target_27b040 *)(((V*)(q + 4))))->FUN_0027b040((hulk_uintptr)(&DAT_003f335c));
        ++p;
        q += 8;
    } while (--n);
}