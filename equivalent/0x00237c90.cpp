// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_00237c90 @ 0x00237c90
// FUN_00237c90: fight::SequenceAction constructor
struct RefObj {
    virtual void AddRef();
    virtual void Release();
};

extern "C" char DAT_00428130[];

struct SequenceAction {
    int vptr;
    char pad04[0x18];
    RefObj *f1c;
    int f20;
    RefObj *f24;
    int f28;
    int f2c;
    int f30;
    RefObj *f34;
    int f38;

    void FUN_00232660();
    SequenceAction *FUN_00237c90(RefObj *a, int b, RefObj *c, int d, int e, int f, RefObj *g);
};

SequenceAction *SequenceAction::FUN_00237c90(RefObj *a, int b, RefObj *c, int d, int e, int f, RefObj *g)
{
    FUN_00232660();
    vptr = (int)DAT_00428130;
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
