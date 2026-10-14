// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00123260 @ 0x00123260
extern "C" char DAT_0040fc60[];

struct RefObj {
    virtual void addRef();
    virtual void release();
};
struct Name {
    char data[8];
    void FUN_0027af00();
};

struct PathAction {
    int vptr;
    char pad04[0x4c];
    int f50;
    int f54;
    int f58;
    char pad5c[4];
    int f60;
    char pad64[0x7c - 0x64];
    int f7c;
    char pad80[0x8c - 0x80];
    int f8c;
    RefObj *f90;
    int f94;
    char pad98[4];
    int f9c;
    int fa0;
    int fa4;
    char padA8[4];
    int fac;
    char padB0[0xd0 - 0xb0];
    Name name;                  // 0xd0
    char fd8;
    char padD9[3];
    int fdc;
    char padE0[8];
    int fe8;
    int fec;
    void FUN_00232660();
    PathAction *FUN_00123260(int a, RefObj *target);
};

PathAction *PathAction::FUN_00123260(int a, RefObj *target)
{
    FUN_00232660();
    vptr = (int)DAT_0040fc60;
    f50 = 0;
    f54 = 0;
    f58 = 0;
    f60 = 0;
    f7c = -1;
    f8c = 0;
    f90 = 0;
    f94 = 0;
    f9c = 0;
    fa0 = 0;
    fa4 = 0;
    fac = 0;
    name.FUN_0027af00();
    fd8 = 0;
    fdc = 0;
    fe8 = 0;
    fec = 0;
    f8c = a;
    if (target)
        target->addRef();
    if (f90)
        f90->release();
    f90 = target;
    return this;
}
