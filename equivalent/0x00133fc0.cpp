// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 10/10)
// hulkfight::motion::FallAction::vfunc_3 @ 0x00133fc0
struct V3 {
    float x, y, z;
};
struct Name {
    unsigned int lo, hi;
    void FUN_0027b040(const char* s);
};
struct Xform {
    char data[0x54];
    void FUN_00221be0(const Xform* src);
    float FUN_002220d0();
};
void* FUN_00263ea0(unsigned int size);
void __cdecl FUN_00224d70(float angle, V3* v);

class JointDriver {
public:
    virtual void AddRef();
    char pad4[4];
    Name name;
    char pad10[8];
    Xform xform;
    JointDriver* FUN_002248f0(int a);
};

struct Attach {
    char pad0[0x2c];
    float height;
};
struct Timing {
    int FUN_00035910();
    bool FUN_000356c0(V3* out);
    void FUN_000357a0(V3* v);
    char pad0[0x11c];
    Attach* attach;
    char pad120[0x140 - 0x120];
    int mode;
};
struct Skeleton {
    char pad0[0x10];
    Xform xform;
    void FUN_00222890(JointDriver* d, float a, float b, float c, float e, float f, float g);
};
struct Clock {
    Timing* FUN_00059a30();
    Skeleton* FUN_00059a40();
};
struct Target {
    Clock* FUN_000592a0();
};
struct Config {
    char pad0[0x24];
    char flag24;
    char pad25[3];
    V3 offset;
    float f34;
    char pad38[0x40 - 0x38];
    float f40;
    float f44;
    float f48;
};
struct Sink {
    void FUN_00099d40(struct World* w, Timing* t, float v);
};
struct World {
    char pad0[8];
    Sink* sink;
};
extern World* DAT_004dd700;

class FallAction {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual bool vfunc_3(int a, int b);
    char pad04[0x1c - 4];
    Config* cfg;
    Target* target;
    JointDriver* driver;
    V3 pos;
};

bool FallAction::vfunc_3(int a, int b)
{
    Clock* clock = target->FUN_000592a0();
    Timing* timing = clock->FUN_00059a30();
    Skeleton* skel = clock->FUN_00059a40();
    if (skel == 0)
        return false;
    pos = cfg->offset;
    FUN_00224d70(skel->xform.FUN_002220d0(), &pos);
    if (!cfg->flag24) {
        V3 move;
        move.x = 0.0f;
        move.y = 0.0f;
        move.z = 0.0f;
        timing->FUN_000356c0(&move);
        pos.x = move.x + pos.x;
        pos.y = move.y + pos.y;
        pos.z = move.z + pos.z;
    }
    Config* c = cfg;
    float c44 = c->f44;
    float c48 = c->f48;
    float c40 = c->f40;
    void* mem = FUN_00263ea0(0x70);
    JointDriver* d;
    if (mem != 0)
        d = ((JointDriver*)mem)->FUN_002248f0(0);
    else
        d = 0;
    driver = d;
    d->name.FUN_0027b040("fall");
    driver->AddRef();
    driver->xform.FUN_00221be0(&skel->xform);
    skel->FUN_00222890(driver, -1.0f, c40, 1.0f, c44, c48, -1.0f);
    DAT_004dd700->sink->FUN_00099d40(DAT_004dd700, timing, cfg->f34);
    if (timing->FUN_00035910() == 7 && timing->mode == 1) {
        V3 lift;
        lift.x = 0.0f;
        lift.y = timing->attach->height * 0.5f;
        lift.z = 0.0f;
        timing->FUN_000357a0(&lift);
    }
    return true;
}
