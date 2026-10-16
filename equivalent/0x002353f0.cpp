// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// fight::ParamValueName::vfunc_5 @ 0x002353f0
#include "decls/data/engine/fight.h"

extern "C" int atexit(void (*)());

struct Key_2353f0 {
    unsigned lo;
    unsigned hi;
    void FUN_0027af00();
};

void FUN_00364130();

class Sink_2353f0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7(int a, int b, Key_2353f0 *k);
};

namespace fight { class ParamValueName {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void vfunc_5(int a1, int a2, Sink_2353f0 *sink);
    virtual void v6();
    virtual Key_2353f0 *v7(int a1);
    int f4;
    int f8;
    int fc;
}; }

void fight::ParamValueName::vfunc_5(int a1, int a2, Sink_2353f0 *sink)
{
    if (((*(unsigned*)&DAT_004e5bc8) & 1) == 0) {
        (*(unsigned*)&DAT_004e5bc8) |= 1;
        (*(Key_2353f0*)&DAT_004e5bc0).FUN_0027af00();
        atexit(FUN_00364130);
    }
    Key_2353f0 *k = v7(a1);
    if (k == 0)
        k = ((Key_2353f0*)&DAT_004e5bc0);
    sink->v7(f8, fc, k);
}
