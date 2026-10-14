// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_0001f6c0 @ 0x0001f6c0
extern "C" char DAT_003f3390[];
extern "C" char DAT_003f3a5c[];

struct RefObj_1f6c0 {
    virtual void addRef();
    virtual void release();
};

struct CEffectAction {
    int vptr;
    char pad04[0x18];
    RefObj_1f6c0 *f1c;
    int f20;
    RefObj_1f6c0 *f24;
    int f28;
    void FUN_00232660();
    CEffectAction *FUN_0001f6c0(int a, RefObj_1f6c0 *b, RefObj_1f6c0 *c);
};

CEffectAction *CEffectAction::FUN_0001f6c0(int a, RefObj_1f6c0 *b, RefObj_1f6c0 *c)
{
    FUN_00232660();
    vptr = (int)DAT_003f3390;
    f1c = 0;
    if (b)
        b->addRef();
    if (f1c)
        f1c->release();
    f1c = b;
    vptr = (int)DAT_003f3a5c;
    f24 = 0;
    f28 = 0;
    f20 = a;
    if (c)
        c->addRef();
    if (f24)
        f24->release();
    f24 = c;
    return this;
}
