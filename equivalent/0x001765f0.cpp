// STATUS: equivalent (tools/equiv.py level 3: 69 inputs, branch coverage 16/16)
// hulkfight::motion::SurfAction::vfunc_3 @ 0x001765f0
extern "C" double sqrt(double);
void* FUN_00263ea0(unsigned int size);

struct Vec3_1765f0 { float x, y, z; };

struct Name_1765f0 {
    char data[8];
    void FUN_0027b040(const char* s);
};

class JointDriver {
public:
    virtual void v0();
    char pad04[4];
    Name_1765f0 name;
    int f10;
    JointDriver* FUN_002248a0();
};

struct Fighter_1765f0 { char pad[4]; };

struct Controller_1765f0 {
    void FUN_00222890(JointDriver* d, float a, int b, float c, int e, int f, float g);
};

struct Stats_1765f0 {
    char pad00[4];
    bool FUN_000356c0(Vec3_1765f0* out);
    bool FUN_00035550(Vec3_1765f0* out);
    float FUN_000354c0();
};

Fighter_1765f0* __fastcall FUN_000592a0(void* owner);
Stats_1765f0* __fastcall FUN_00059a30(Fighter_1765f0* f);
Controller_1765f0* __fastcall FUN_00059a40(Fighter_1765f0* f);

struct Params {
    char pad00[0x14];
    float limit;
    char pad18[0x3c - 0x18];
    int p3c;
    int p40;
    int p44;
};

class SurfAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual bool vfunc_3(int a, int b);
    char pad04[0x1c - 4];
    Params* params;
    void* owner;
    JointDriver* driver;
    float f28;
    char pad2c[0x34 - 0x2c];
    float f34;
};

bool SurfAction::vfunc_3(int a, int b)
{
    if (owner == 0)
        return false;
    Fighter_1765f0* fighter = FUN_000592a0(owner);
    if (fighter == 0)
        return false;
    Stats_1765f0* stats = FUN_00059a30(fighter);
    if (stats == 0)
        return false;
    Controller_1765f0* ctl = FUN_00059a40(fighter);
    if (ctl == 0)
        return false;
    JointDriver* d = (JointDriver*)FUN_00263ea0(0x70);
    if (d)
        d = d->FUN_002248a0();
    driver = d;
    d->name.FUN_0027b040("surf");
    driver->v0();
    driver->f10 = 0;
    ctl->FUN_00222890(driver, -1.0f, params->p3c, 1.0f, params->p40, params->p44, -1.0f);
    Vec3_1765f0 v;
    v.x = 0.0f;
    v.y = 0.0f;
    v.z = 0.0f;
    stats->FUN_000356c0(&v);
    float len = (float)sqrt((double)(v.x * v.x + v.z * v.z));
    v.y = 0.0f;
    float limit = params->limit;
    if (limit > 0.0f && len < limit) {
        if (len <= 0.0f)
            stats->FUN_00035550(&v);
        f34 = limit;
    } else {
        f34 = len;
    }
    f28 = stats->FUN_000354c0();
    return true;
}
