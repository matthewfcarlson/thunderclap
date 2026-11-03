#include "gen/owners.h"
struct V {
    float x, y, z;
};
struct M_1af890 {
    char pad[8];
    V* items;
};
struct S_1af890 {
};
struct T_1af890 {
    char p0[0x44];
    M_1af890* mgr;
    char p1[4];
    S_1af890 sub;
    char p2[0x7f];
    char flag;
    V Get(unsigned short i);
};
V T_1af890::Get(unsigned short i) {
    if (flag) {
        V t;
        ((owners::Mat_22c2b0 *)&sub)->FUN_0022c2b0((float *)(V *)(&mgr->items[i]), (float *)(V *)(&t));
        return t;
    }
    return mgr->items[i];
}