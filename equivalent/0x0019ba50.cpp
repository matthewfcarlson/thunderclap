// STATUS: equivalent (tools/equiv.py level 3: 77 inputs, branch coverage 7/8, incomplete)
// hulkfight::motion::FireGroundShockwaveAction::vfunc_5 @ 0x0019ba50
struct V3_19ba50 { float x, y, z; };
struct Mat_19ba50 { float m[16]; };

struct Xform_19ba50 {
    void FUN_00221f20(V3_19ba50* in, V3_19ba50* out);
    void FUN_00221f70(V3_19ba50* in, V3_19ba50* out);
};
struct Skeleton {
    char pad0[0x10];
    Xform_19ba50 xf;
};
struct Timing_19ba50 {
    float FUN_0003ec00(int a);
};
struct Clock_19ba50 {
    Timing_19ba50* FUN_00059a30();
    Skeleton* FUN_00059a40();
};
struct Source_19ba50 {
    char pad0[0x10];
    V3_19ba50 pos;
    V3_19ba50 dir;
    char pad28[0x30 - 0x28];
    int id;
};
struct Target_19ba50 {
    char pad0[8];
    int f8;
    Clock_19ba50* FUN_000592a0();
};
class Child_19ba50 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(Mat_19ba50* m, int a);
    char pad4[0xc];
    Mat_19ba50 mat;
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
    Child_19ba50* child;
    V3_19ba50 aim;
    Shock* FUN_00198990(Source_19ba50* src);
};
struct Pool_19ba50 {
    void* FUN_0008fe90(unsigned int size);
};
struct Mgr_19ba50 {
    int FUN_001b6b00(int id, V3_19ba50* pos);
    int FUN_001b6d00(int idx, Shock* s);
};
struct Globals_19ba50 {
    char pad0[0x14];
    Mgr_19ba50* mgr;
};
extern Globals_19ba50* DAT_004dd700;
extern Pool_19ba50 DAT_004e2210;

class FireGroundShockwaveAction {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual bool vfunc_5(int a, int b);
    char pad04[0x1c - 4];
    Source_19ba50* source;
    Target_19ba50* target;
};

bool FireGroundShockwaveAction::vfunc_5(int a, int b)
{
    if (a != 1)
        return true;
    if (target == 0)
        return false;
    Mgr_19ba50* mgr = DAT_004dd700->mgr;
    Clock_19ba50* clock = target->FUN_000592a0();
    Timing_19ba50* timing = clock->FUN_00059a30();
    Skeleton* skel = clock->FUN_00059a40();
    V3_19ba50 v;
    V3_19ba50 local;
    V3_19ba50 world;
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
    Child_19ba50* c = s->child;
    Mat_19ba50 m = c->mat;
    m.m[12] = local.x;
    m.m[13] = local.y;
    m.m[14] = local.z;
    c->v6(&m, 0);
    s->aim = world;
    mgr->FUN_001b6d00(handle, s);
    s->Release();
    return false;
}
