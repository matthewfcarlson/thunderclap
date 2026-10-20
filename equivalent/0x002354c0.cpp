// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// fight::ParamValueNameList::vfunc_5 @ 0x002354c0
#include "decls/data/engine/fight.h"

extern "C" int atexit(void (*)());

struct Key_2354c0 {
    unsigned lo;
    unsigned hi;
    void FUN_0027af00();
};

void FUN_00364140();

class Sink_2354c0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual int v7(int a, int b, Key_2354c0 *k);
};

namespace fight { class ParamValueNameList {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual int vfunc_5(int a1, int a2, Sink_2354c0 *sink);
    virtual void v6();
    virtual Key_2354c0 *v7(int a1);
    int f4;
    int f8;
    int fc;
}; }

int fight::ParamValueNameList::vfunc_5(int a1, int a2, Sink_2354c0 *sink)
{
    Key_2354c0 *k = v7(a1);
    if (k == 0) {
        if ((DAT_004e5bd8 & 1) == 0) {
            DAT_004e5bd8 |= 1;
            (*(Key_2354c0*)&DAT_004e5bd0).FUN_0027af00();
            atexit(FUN_00364140);
        }
        k = ((Key_2354c0*)&DAT_004e5bd0);
    }
    return sink->v7(f8, fc, k);
}
