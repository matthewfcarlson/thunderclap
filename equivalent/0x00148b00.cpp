// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 24/24)
// hulkfight::motion::GrappleThrowAction::vfunc_3 @ 0x00148b00
struct Vec3 {
    float x, y, z;
    char FUN_0022d2b0(Vec3* other, float eps);
    double FUN_0022d110();
};

struct Mat4 {
    void FUN_0022c3b0(Vec3* in, Vec3* out);
};

struct Part {
    Mat4* FUN_00221c40();
};

struct Body {
    char pad00[0x10];
    Part part;
};

class Ref {
public:
    virtual void AddRef();
    virtual void Release();
};

struct Entity {
    void FUN_00059a50(Vec3* out);
    Body* FUN_00059a40();
};

struct Link {
    char pad00[0x14];
    int f14;
};

struct Throwable {
    char pad00[0x10];
    Entity* entity;
    char pad14[0x12c - 0x14];
    Ref* ref;
    char pad130[0x328 - 0x130];
    Ref* ref328;
    char pad32c[0x334 - 0x32c];
    int f334;
    float FUN_0003ec00(int mode);
};

struct Owner {
    char pad00[0x10];
    Entity* entity;
    char pad14[0x11c - 0x14];
    Link* link;
    char pad120[0x12c - 0x120];
    Ref* ref;
    char pad130[0x338 - 0x130];
    Throwable* held;
    void FUN_0003a680(int a1, int a2, int a3, int a4, int a5, int a6, float a7, int a8);
    void FUN_000437a0(int a1, struct Desc* desc, struct Sub* sub, int a4, int a5);
};

struct Handle {
    Owner* FUN_00059a30();
};

struct Source {
    Handle* FUN_000592a0();
};

struct Config {
    char pad00[0x10];
    Vec3 target;
    float a0, a1;
    float b0, b1;
    float c0, c1;
    float f34;
    float d0, d1;
};

struct Desc {
    int f00, f04, f08, f0c, f10;
    int pad14;
    Vec3 dir;
    char f24;
    char pad25[3];
    Vec3 vel;
    char f34;
    char pad35[3];
    char pad38[0x48 - 0x38];
    int id;
    Ref* ref1;
    Ref* ref2;
    int pad54;
    int f58;
    int f5c;
    int pad60;
    int f64;
    float f68;
    int pad6c;
    int pad70;
    int f74;
    int pad78;
    float f7c;
    float f80;
    Ref* ref3;
    float f88;
    float f8c;
    char pad90[8];
    void FUN_00059820();
    void FUN_00059300();
};

struct Sub {
    char pad00[4];
    int f04;
    char pad08[0x20 - 8];
    int f20;
    void FUN_002322f0(int a, int b);
    char FUN_00231ee0();
};

void __cdecl FUN_00097a30(float b, float c, float k, Ref* ref, int z, Vec3* pos, float p34, Vec3* dir, int a9, int a10, int a11, int a12);

struct Frame {
    union {
        float b;
        Ref* ref;
    } t;
    float speed;
    Vec3 dir;
    Vec3 v2;
    Vec3 v1;
    Vec3 v3;
    Desc desc;
};

namespace hulkfight {
namespace motion {

class GrappleThrowAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual char vfunc_3(int a, int b);

    char pad04[0x1c - 4];
    Config* config;
    Source* source;
    Sub sub;
    char pad_sub[0x4c - 0x24 - sizeof(Sub)];
    int saved;
    char flag50;
};

char GrappleThrowAction::vfunc_3(int a, int b)
{
    Frame f;
    saved = a;
    Owner* owner = source->FUN_000592a0()->FUN_00059a30();
    if (!owner)
        return false;
    Throwable* th = owner->held;
    if (!th)
        return false;

    f.v1.x = 0;
    f.v1.y = 0;
    f.v1.z = 0;
    owner->entity->FUN_00059a50(&f.v1);
    f.v2.x = 0;
    f.v2.y = 0;
    f.v2.z = 0;
    f.v3.x = config->target.x;
    f.v3.y = config->target.y;
    f.v3.z = config->target.z;
    if (!f.v3.FUN_0022d2b0(&f.v2, 0.00001f)) {
        Body* body = th->entity->FUN_00059a40();
        if (body) {
            f.v3.x = config->target.x;
            f.v3.y = config->target.y;
            f.v3.z = config->target.z;
            body->part.FUN_00221c40()->FUN_0022c3b0(&f.v3, &f.dir);
        }
    } else {
        f.v2.x = 0;
        f.v2.y = 0;
        f.v2.z = 0;
        th->entity->FUN_00059a50(&f.v2);
        f.dir.x = f.v1.x - f.v2.x;
        f.dir.y = f.v1.y - f.v2.y;
        f.dir.z = f.v1.z - f.v2.z;
    }
    f.dir.FUN_0022d110();

    Ref* grabRef = th->ref328;
    if (grabRef == owner->ref)
        grabRef = 0;
    owner->FUN_0003a680(0, -1, 0, 0, 0, 0, 1.0f, 0);
    th->f334 = 0;
    f.desc.FUN_00059820();

    f.t.ref = th->ref;
    if (f.t.ref)
        f.t.ref->AddRef();
    if (f.desc.ref1)
        f.desc.ref1->Release();
    f.desc.ref1 = f.t.ref;

    f.t.ref = owner->ref;
    if (f.t.ref)
        f.t.ref->AddRef();
    if (f.desc.ref2)
        f.desc.ref2->Release();
    f.desc.ref2 = f.t.ref;

    f.desc.dir.x = f.dir.x;
    f.desc.dir.z = f.dir.z;
    f.desc.f00 = f.desc.f04 = f.desc.f08 = f.desc.f0c = f.desc.f10 = 0;
    f.desc.dir.y = f.dir.y;
    f.desc.f24 = 1;
    f.desc.f58 = f.desc.f5c = f.desc.f64 = f.desc.f74 = 0;
    f.desc.f68 = 0;

    f.speed = th->FUN_0003ec00(2);
    f.desc.f34 = 1;
    f.desc.f7c = f.speed;
    f.desc.f80 = 0;
    if (owner->link->f14)
        f.desc.f80 = 1.0f;

    if (grabRef)
        grabRef->AddRef();
    if (f.desc.ref3)
        f.desc.ref3->Release();

    f.desc.ref3 = grabRef;
    f.desc.f88 = (config->a1 - config->a0) * f.speed + config->a0;
    f.t.b = (config->b1 - config->b0) * f.speed + config->b0;
    f.desc.f8c = (config->c1 - config->c0) * f.speed + config->c0;
    f.desc.f68 = (config->d1 - config->d0) * f.speed + config->d0;
    FUN_00097a30(f.t.b, f.desc.f8c, -1.0f, grabRef, 0, &f.v1, config->f34, &f.dir, 0, 0, 0, 1);

    f.desc.vel.x = f.dir.x * f.t.b;
    f.desc.vel.y = f.dir.y * f.t.b;
    f.desc.vel.z = f.dir.z * f.t.b;
    owner->FUN_000437a0(0, &f.desc, &sub, 0, 0);
    sub.FUN_002322f0(saved, b);
    flag50 = 1;
    char result = sub.FUN_00231ee0();
    f.desc.FUN_00059300();
    return result;
}

}
}
