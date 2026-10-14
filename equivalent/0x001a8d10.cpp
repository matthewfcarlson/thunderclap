// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_001a8d10 @ 0x001a8d10
extern char DAT_0041cf24[];

struct RefObj_1a8d10 {
    virtual void addRef();
    virtual void release();
};
struct SlotEntry_1a8d10 {
    char b0, b1, b2, b3;
    int v0, v1, v2, v3, v4;
};
struct Holder54_1a8d10 { int FUN_000862a0(); };
struct World { char pad[0x54]; Holder54_1a8d10* holder; };
extern World* DAT_004dd700;

struct NISAnimationAction;
extern NISAnimationAction* DAT_004e1760;

struct NISAnimationAction {
    int vptr;
    char pad04[0x18];
    int f1c;
    RefObj_1a8d10* f20;
    int f24, f28;
    SlotEntry_1a8d10 slots[20];
    int f20c;
    int f210;
    char f214;
    void FUN_00232660();
    NISAnimationAction* FUN_001a8d10(int arg, RefObj_1a8d10* target);
};

NISAnimationAction* NISAnimationAction::FUN_001a8d10(int arg, RefObj_1a8d10* target)
{
    FUN_00232660();
    vptr = (int)DAT_0041cf24;
    f1c = 0;
    f20 = 0;
    f24 = 0;
    f28 = 0;
    for (int i = 0; i < 20; i++) {
        slots[i].b0 = 0;
        slots[i].b1 = 0;
        slots[i].b2 = 0;
        slots[i].b3 = 0;
        slots[i].v0 = 0;
        slots[i].v1 = 0;
        slots[i].v2 = 0;
        slots[i].v3 = 0;
        slots[i].v4 = 0;
    }
    f210 = 0;
    f214 = 0;
    f1c = arg;
    if (target)
        target->addRef();
    if (f20)
        f20->release();
    f20 = target;
    f20c = DAT_004dd700->holder->FUN_000862a0();
    DAT_004e1760 = this;
    return this;
}
