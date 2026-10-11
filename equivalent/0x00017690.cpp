// STATUS: equivalent (tools/equiv.py level 3: 71 inputs, branch coverage 6/6)
// CHeadTrackerAction::vfunc_6 @ 0x00017690
struct V3 {
    float x, y, z;
    float FUN_0022d110();
};

struct Matrix {
    char data[0x40];
    void FUN_0022b980();
    void FUN_0022c0b0();
};

struct NameField {
    void FUN_0027b040(const char* s);
};

class HeadTracker {
public:
    virtual void v0();
    char pad4[4];
    NameField name;
    char pad9[0x10 - 0x9];
    unsigned int index;
    int mode;
    char pad18[0x70 - 0x18];
    HeadTracker* FUN_002248a0();
};

struct Table {
    unsigned int FUN_0027b200(int a, int b);
};

struct Pair {
    char pad[8];
    Table* table;
};

struct Mgr {
    Pair* FUN_00059a40();
};

struct Cfg {
    char pad0[0x18];
    int f18;
    int f1c;
    V3 dirSrc;
    V3 upSrc;
};

struct Holder {
    Mgr* FUN_000592a0();
};

struct Tracker {
    char pad[0x64];
    Pair* pair;
};

struct Mgr2 {
    Tracker* FUN_00059a40();
};

struct Holder2 {
    Mgr2* FUN_000592a0();
};

void* FUN_00263ea0(unsigned int size);
int __cdecl FUN_000113e0(int lo, int hi);

class CHeadTrackerAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual bool vfunc_6(int arg);
    virtual void vfunc_7();
    virtual void vfunc_8();
    char pad04[0x1c - 4];
    Holder2* holder;
    Cfg* cfg;
    HeadTracker* tracker;
    V3 dir;
    Matrix basis;
    char pad74[0x8c - 0x74];
    int rnd;
};

bool CHeadTrackerAction::vfunc_6(int arg)
{
    struct Frame {
        V3 b;
        V3 c;
        V3 d;
    } fr;
    Tracker* tr = holder->FUN_000592a0()->FUN_00059a40();
    if (tr == 0)
        return false;
    unsigned int idx = tr->pair->table->FUN_0027b200(cfg->f18, cfg->f1c);
    if (idx == 0xffff)
        return false;
    void* mem = FUN_00263ea0(0x70);
    HeadTracker* o = 0;
    if (mem)
        o = ((HeadTracker*)mem)->FUN_002248a0();
    tracker = o;
    o->name.FUN_0027b040("headTracker");
    tracker->v0();
    tracker->mode = 2;
    tracker->index = idx;
    fr.d = cfg->dirSrc;
    dir = fr.d;
    dir.FUN_0022d110();
    fr.b = cfg->upSrc;
    fr.b.FUN_0022d110();
    fr.c.x = fr.b.z * dir.y - fr.b.y * dir.z;
    fr.c.y = fr.b.x * dir.z - fr.b.z * dir.x;
    fr.c.z = fr.b.y * dir.x - fr.b.x * dir.y;
    fr.c.FUN_0022d110();
    fr.b.x = fr.c.y * dir.z - fr.c.z * dir.y;
    fr.b.y = fr.c.z * dir.x - fr.c.x * dir.z;
    fr.b.z = fr.c.x * dir.y - fr.c.y * dir.x;
    fr.b.FUN_0022d110();
    basis.FUN_0022b980();
    float* m = (float*)&basis;
    m[0] = fr.b.x;
    m[1] = fr.b.y;
    m[2] = fr.b.z;
    m[4] = fr.c.x;
    m[5] = fr.c.y;
    m[6] = fr.c.z;
    m[8] = dir.x;
    m[9] = dir.y;
    m[10] = dir.z;
    basis.FUN_0022c0b0();
    rnd = FUN_000113e0(0, 9);
    return true;
}
