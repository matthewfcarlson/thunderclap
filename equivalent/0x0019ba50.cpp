// STATUS: equivalent (tools/equiv.py level 3: 77 inputs, branch coverage 7/8, incomplete)
// hulkfight::motion::FireGroundShockwaveAction::vfunc_5 @ 0x0019ba50
struct V3 { float x, y, z; };
struct Mat { float m[16]; };

struct Xform {
    void FUN_00221f20(V3* in, V3* out);
    void FUN_00221f70(V3* in, V3* out);
};
struct Skeleton {
    char pad0[0x10];
    Xform xf;
};
struct Timing {
    float FUN_0003ec00(int a);
};
struct Clock {
    Timing* FUN_00059a30();
    Skeleton* FUN_00059a40();
};
struct Source {
    char pad0[0x10];
    V3 pos;
    V3 dir;
    char pad28[0x30 - 0x28];
    int id;
};
struct Target {
    char pad0[8];
    int f8;
    Clock* FUN_000592a0();
};
class Child {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(Mat* m, int a);
    char pad4[0xc];
    Mat mat;
};
class Shock {
public:
    virtual void AddRef();
    virtual void Release();
    char pad4[0x14 - 4];
    int id;
    char pad18[4];
    int f1c;
    float f20;
    Child* child;
    V3 aim;
    Shock* FUN_00198990(Source* src);
};
struct Pool {
    void* FUN_0008fe90(unsigned int size);
};
struct Mgr {
    int FUN_001b6b00(int id, V3* pos);
    int FUN_001b6d00(int idx, Shock* s);
};
struct Globals {
    char pad0[0x14];
    Mgr* mgr;
};
extern Globals* DAT_004dd700;
extern Pool DAT_004e2210;

class FireGroundShockwaveAction {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual bool vfunc_5(int a, int b);
    char pad04[0x1c - 4];
    Source* source;
    Target* target;
};

bool FireGroundShockwaveAction::vfunc_5(int a, int b)
{
    if (a != 1)
        return true;
    if (target == 0)
        return false;
    Mgr* mgr = DAT_004dd700->mgr;
    Clock* clock = target->FUN_000592a0();
    Timing* timing = clock->FUN_00059a30();
    Skeleton* skel = clock->FUN_00059a40();
    V3 v;
    V3 local;
    V3 world;
    v = source->pos;
    skel->xf.FUN_00221f20(&v, &local);
    v = source->dir;
    skel->xf.FUN_00221f70(&v, &world);
    int id = source->id;
    int handle = mgr->FUN_001b6b00(id, &local);
    if (handle < 0)
        return false;
    void* mem = DAT_004e2210.FUN_0008fe90(0xc0);
    Shock* s;
    if (mem != 0)
        s = ((Shock*)mem)->FUN_00198990(source);
    else
        s = 0;
    s->AddRef();
    s->f1c = target->f8;
    s->id = id;
    s->f20 = timing->FUN_0003ec00(1);
    Child* c = s->child;
    Mat m = c->mat;
    m.m[12] = local.x;
    m.m[13] = local.y;
    m.m[14] = local.z;
    c->v6(&m, 0);
    s->aim = world;
    mgr->FUN_001b6d00(handle, s);
    s->Release();
    return false;
}
