// STATUS: equivalent (tools/equiv.py level 3: 71 inputs, branch coverage 14/14)
// hulkfight::motion::FlyingAttackAction::vfunc_3 @ 0x00135520
struct V3 {
    float x, y, z;
    float FUN_0022d110();
};

struct Name {
    unsigned int lo, hi;
    void FUN_0027b040(const char* s);
};

struct Matrix {
    void FUN_0022c3b0(const V3* in, V3* out);
};

struct Xform {
    char data[0x54];
    void FUN_00221be0(const Xform* src);
    void FUN_00221d20(float v);
    void FUN_00222180(const V3* v);
    Matrix* FUN_00221c40();
};

class FlyDriver {
public:
    virtual void AddRef();
    char pad4[4];
    Name name;
    char pad10[8];
    Xform xform;
    FlyDriver* FUN_002248f0(int a);
};

struct Linked {
    void FUN_0003ee70(int handle);
};

class RefObj {
public:
    virtual void AddRef();
    virtual void Release();
    char pad4[4];
    Linked* linked;
    int kind;
};

struct Tracker {
    char pad0[0x10];
    Xform xf;
    void FUN_00222890(FlyDriver* d, float a, float b, float c, float e, float f, float g);
};

struct Stats {
    char pad0[0x12c];
    int handle;
    char pad130[0x328 - 0x130];
    RefObj* body;
    void FUN_000350c0(V3* out);
};

struct Fighter {
    Stats* FUN_00059a30();
    Tracker* FUN_00059a40();
};

struct Holder {
    Fighter* FUN_000592a0();
};

struct Config {
    char pad0[0x14];
    V3 vec14;
    int f20;
    char pad24[0x30 - 0x24];
    char flag30;
    char pad31[0x34 - 0x31];
    float f34;
    float f38;
    float f3c;
};

void* __cdecl FUN_00263ea0(unsigned int size);
float __cdecl FUN_00224f10(V3* v);
void __cdecl FUN_00096a90(RefObj* r, V3* out);

class FlyingAttackAction {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool vfunc_3(int a, int b);
    char pad04[0x1c - 4];
    Config* cfg;
    Holder* holder;
    FlyDriver* driver;
    RefObj* ref;
    int f2c;
    V3 dir;
};

bool FlyingAttackAction::vfunc_3(int a, int b)
{
    struct Frame {
        float f3c;
        float f38;
        float f34;
        V3 pos;
        V3 tmp;
    } fr;
    Fighter* fighter = holder->FUN_000592a0();
    Stats* stats = fighter->FUN_00059a30();
    Tracker* tr = fighter->FUN_00059a40();
    if (tr == 0)
        return false;
    Config* c = cfg;
    fr.f34 = c->f34;
    fr.f38 = c->f38;
    fr.f3c = c->f3c;
    void* mem = FUN_00263ea0(0x70);
    FlyDriver* d;
    if (mem != 0)
        d = ((FlyDriver*)mem)->FUN_002248f0(0);
    else
        d = 0;
    driver = d;
    d->name.FUN_0027b040("flyingAttack");
    driver->AddRef();
    driver->xform.FUN_00221be0(&tr->xf);
    tr->FUN_00222890(driver, -1.0f, fr.f34, 1.0f, fr.f38, fr.f3c, -1.0f);

    fr.tmp = cfg->vec14;
    tr->xf.FUN_00221c40()->FUN_0022c3b0(&fr.tmp, &dir);
    dir.FUN_0022d110();

    fr.pos.x = 0.0f;
    fr.pos.y = 0.0f;
    fr.pos.z = 0.0f;
    stats->FUN_000350c0(&fr.pos);
    RefObj* r = stats->body;
    if (r)
        r->AddRef();
    if (ref)
        ref->Release();
    ref = r;
    if (r) {
        FUN_00096a90(r, &dir);
        dir.x = dir.x - fr.pos.x;
        dir.y = dir.y - fr.pos.y;
        dir.z = dir.z - fr.pos.z;
        dir.FUN_0022d110();
        if (r->kind == 1)
            r->linked->FUN_0003ee70(stats->handle);
    }
    if (cfg->flag30) {
        driver->xform.FUN_00222180(&dir);
    } else {
        driver->xform.FUN_00221d20(FUN_00224f10(&dir));
    }
    f2c = cfg->f20;
    return true;
}
