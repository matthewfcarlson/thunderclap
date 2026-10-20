// FUN_00237c90 @ 0x00237c90
// FUN_00237c90: fight::SequenceAction constructor
#include "compat/ptr.h"
struct RefObj_237c90 {
    virtual void AddRef();
    virtual void Release();
};

extern "C" char DAT_00428130[];

struct SequenceAction {
    hulk_intptr vptr;
    char pad04[0x18];
    RefObj_237c90 *f1c;
    int f20;
    RefObj_237c90 *f24;
    int f28;
    int f2c;
    int f30;
    RefObj_237c90 *f34;
    int f38;

    void FUN_00232660();
    SequenceAction *FUN_00237c90(RefObj_237c90 *a, int b, RefObj_237c90 *c, int d, int e, int f, RefObj_237c90 *g);
};

SequenceAction *SequenceAction::FUN_00237c90(RefObj_237c90 *a, int b, RefObj_237c90 *c, int d, int e, int f, RefObj_237c90 *g)
{
    FUN_00232660();
    vptr = (hulk_intptr)DAT_00428130;
    f1c = 0;
    f20 = 0;
    f24 = 0;
    f28 = d;
    f2c = e;
    f30 = f;
    f34 = 0;
    f38 = 0;
    if (a)
        a->AddRef();
    if (f1c)
        f1c->Release();
    f1c = a;
    f20 = b;
    if (c)
        c->AddRef();
    if (f24)
        f24->Release();
    f24 = c;
    if (g)
        g->AddRef();
    if (f34)
        f34->Release();
    f34 = g;
    return this;
}
