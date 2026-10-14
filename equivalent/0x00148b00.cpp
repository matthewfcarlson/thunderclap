// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 24/24)
// hulkfight::motion::GrappleThrowAction::vfunc_3 @ 0x00148b00
struct Vec3_148b00 {
    float x, y, z;
    char FUN_0022d2b0(Vec3_148b00* other, float eps);
    double FUN_0022d110();
};

struct Mat4_148b00 {
    void FUN_0022c3b0(Vec3_148b00* in, Vec3_148b00* out);
};

struct Part_148b00 {
    Mat4_148b00* FUN_00221c40();
};

struct Body_148b00 {
    char pad00[0x10];
    Part_148b00 part;
};

class Ref_148b00 {
public:
    virtual void AddRef();
    virtual void Release();
};

struct Entity {
    void FUN_00059a50(Vec3_148b00* out);
    Body_148b00* FUN_00059a40();
};

struct Link_148b00 {
    char pad00[0x14];
    int f14;
};

struct Throwable {
    char pad00[0x10];
    Entity* entity;
    char pad14[0x12c - 0x14];
    Ref_148b00* ref;
    char pad130[0x328 - 0x130];
    Ref_148b00* ref328;
    char pad32c[0x334 - 0x32c];
    int f334;
    float FUN_0003ec00(int mode);
};

struct Owner_148b00 {
    char pad00[0x10];
    Entity* entity;
    char pad14[0x11c - 0x14];
    Link_148b00* link;
    char pad120[0x12c - 0x120];
    Ref_148b00* ref;
    char pad130[0x338 - 0x130];
    Throwable* held;
    void FUN_0003a680(int a1, int a2, int a3, int a4, int a5, int a6, float a7, int a8);
    void FUN_000437a0(int a1, struct Desc_148b00* desc, struct Sub_148b00* sub, int a4, int a5);
};

struct Handle_148b00 {
    Owner_148b00* FUN_00059a30();
};

struct Source_148b00 {
    Handle_148b00* FUN_000592a0();
};

struct Config_148b00 {
    char pad00[0x10];
    Vec3_148b00 target;
    float a0, a1;
    float b0, b1;
    float c0, c1;
    float f34;
    float d0, d1;
};

struct Desc_148b00 {
    int f00, f04, f08, f0c, f10;
    int pad14;
    Vec3_148b00 dir;
    char f24;
    char pad25[3];
    Vec3_148b00 vel;
    char f34;
    char pad35[3];
    char pad38[0x48 - 0x38];
    int id;
    Ref_148b00* ref1;
    Ref_148b00* ref2;
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
    Ref_148b00* ref3;
    float f88;
    float f8c;
    char pad90[8];
    void FUN_00059820();
    void FUN_00059300();
};

struct Sub_148b00 {
    char pad00[4];
    int f04;
    char pad08[0x20 - 8];
    int f20;
    void FUN_002322f0(int a, int b);
    char FUN_00231ee0();
};

void __cdecl FUN_00097a30(float b, float c, float k, Ref_148b00* ref, int z, Vec3_148b00* pos, float p34, Vec3_148b00* dir, int a9, int a10, int a11, int a12);

struct Frame_148b00 {
    union {
        float b;
        Ref_148b00* ref;
    } t;
    float speed;
    Vec3_148b00 dir;
    Vec3_148b00 v2;
    Vec3_148b00 v1;
    Vec3_148b00 v3;
    Desc_148b00 desc;
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
    Config_148b00* config;
    Source_148b00* source;
    Sub_148b00 sub;
    char pad_sub[0x4c - 0x24 - sizeof(Sub_148b00)];
    int saved;
    char flag50;
};

char GrappleThrowAction::vfunc_3(int a, int b)
{
    Frame_148b00 f;
    saved = a;
    Owner_148b00* owner = source->FUN_000592a0()->FUN_00059a30();
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
        Body_148b00* body = th->entity->FUN_00059a40();
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

    Ref_148b00* grabRef = th->ref328;
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
