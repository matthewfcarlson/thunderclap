#include "gen/hulkfight.h"

struct A_10d770 {
    A_10d770* f0();
    int f1();
};
struct B_10d770 {
    char pad[0x14];
    int a14;
    int a18;
    int a1c;
    int a20;
};

bool hulkfight::ai::ButtonAction::vfunc_5(int p, int q) {
    if (p == 0) {
        if (!(*(A_10d770 * *)&this->f_20))
            return (bool)(0);
        A_10d770* r = (*(A_10d770 * *)&this->f_20)->f0();
        int base = r->f1();
        int* d = (int*)(base + 0x1f58);
        d = d + (*(B_10d770 * *)&this->f_1c)->a14 * 3;
        d[0] = (*(B_10d770 * *)&this->f_1c)->a18;
        d[1] = (*(B_10d770 * *)&this->f_1c)->a1c;
        d[2] = (*(B_10d770 * *)&this->f_1c)->a20;
    }
    return (bool)(1);
}
