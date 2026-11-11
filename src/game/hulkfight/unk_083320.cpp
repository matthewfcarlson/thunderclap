// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00083320..0x00083e30 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_ff46a245 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_ff46a245 {} using namespace fn_ff46a245;
#include "game/hulkfight.h"

// ---- declarations shared by the functions below
namespace fn_ff46a245 {
struct Vec3_83320 {
    float x, y, z;
};
struct Xform_83320 {
    float rot[12];
    Vec3_83320 pos;
    float w;
};
struct Part_83320 {
    char pad00[0x6c];
    int f6c;
    void FUN_002ef8b0(int a);
};
class Body_83320 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual Xform_83320* GetXform();      // slot 15
    void FUN_001d7510();
    void FUN_001d6b60(Xform_83320 pose, int flag);
};
struct Registry_83320 {
};
} // namespace fn_ff46a245
struct World {
    char pad00[0xc];
    Registry_83320* registry;             // 0x0c
};
namespace fn_ff46a245 {
void FUN_00082d30(Xform_83320* pose);
class Mover_83320 {
public:
    void FUN_00083320(Vec3_83320* anchor, Vec3_83320* dir, float scale, char airborne, hulk_intptr unused, char forced);

    char pad00[0x10];
    int id;                         // 0x10
    int state;                      // 0x14
    char pad18[4];
    char b1c;                       // 0x1c
    char pad1d[3];
    float f20;
    float f24;
    int f28;
    Vec3_83320 vel;                       // 0x2c
};
struct Vec {
    float x, y, z;
    void Cross(const Vec& a, const Vec& b);
};
typedef unsigned int Word_83c30;
struct Handle_83c30 { Word_83c30 words[2]; void FUN_0027b040(Word_83c30); };
struct FUN_0027b070 { virtual void slot0(); FUN_0027b070(); };
struct Triple_83c30 { Word_83c30 x,y,z; };
struct CVehicle : FUN_0027b070 {
 virtual void slot0();
 Word_83c30 unknown4;
 Handle_83c30 handle;
 Word_83c30 state;
 unsigned char flag; char pad15[3];
 Word_83c30 value18,value1c;
 Word_83c30 state20,state24,state28;
 unsigned char flag2c,flag2d; char pad2e[2];
 Word_83c30 state30;
 Word_83c30 value34,value38,value3c,value40;
 Triple_83c30 position,rotation;
 Word_83c30 value5c;
 Triple_83c30 originalPosition;
 char pad6c[0x4c];
 Word_83c30 stateb8,statebc;
 CVehicle(Word_83c30 a1,Word_83c30 a2,Word_83c30 a3,Word_83c30 a4,Word_83c30 a5,Word_83c30 a6,Word_83c30 a7,Word_83c30 a8,Word_83c30 a9,Word_83c30 a10,Word_83c30 a11,Word_83c30 a12,Word_83c30 a13);
};
class Target_83d10 {
    char pad[0x14];

  public:
    unsigned char value;
};
class A_83d30 {
    char pad[0x1c];

  public:
    float value;
    void Set(float x) {
        if (x >= 0.0f)
            value = x;
    }
};
struct Vec3_83e00 {
    float x, y, z;
};


// 0x00083320 FUN_00083320 (586 B): equivalent/0x00083320.cpp
// sym: ?FUN_00083320@Mover_83320@fn_ff46a245@@QAEXPAUVec3_83320@2@0MDHD@Z @ab343534601f @w65b0069f1f0c
// STATUS: equivalent (tools/equiv.py level 3: 3028 inputs, branch coverage 30/33, incomplete)
// FUN_00083320 @ 0x00083320
// equiv-conv: FUN_00082d30 esi
void Mover_83320::FUN_00083320(Vec3_83320* anchor, Vec3_83320* dir, float scale, char airborne, hulk_intptr unused, char forced)
{
    b1c = 1;
    f28 = 0;
    Body_83320* body = ((Body_83320 *)((owners::Obj_1dc0d0 *)(DAT_004dd700->registry))->FUN_001dc0d0((hulk_intptr)id));
    Xform_83320 pose = *body->GetXform();

    bool grounded = false;
    if (!forced) {
        union { float f; unsigned int u; } a, b;
        a.f = dir->y;
        a.u &= 0x7fffffff;
        b.f = a.f - 1.0f;
        b.u &= 0x7fffffff;
        if (b.f <= 0.1f) {
            grounded = true;
            if (((Part_83320 *)((owners::C_1d72e0 *)body)->FUN_001d72e0())->f6c == 0)
                pose.pos.y = anchor->y;
        }
    }

    if (!airborne) {
        switch (state) {
        case 2:
            if (!grounded) {
                Vec3_83320 v;
                v.x = -(scale * dir->x);
                v.y = 0.0f;
                v.z = -(scale * dir->z);
                ((owners::Vec3_11220 *)&(pose.pos))->FUN_00011220((const owners::Vec3_11220 *)(Vec3_83320 *)(&v));
                state = 3;
                f24 = 0.0f;
            }
            break;
        case 3:
            if (!grounded) {
                Vec3_83320 v;
                v.x = -(scale * dir->x);
                v.y = 0.0f;
                v.z = -(scale * dir->z);
                ((owners::Vec3_11220 *)&(pose.pos))->FUN_00011220((const owners::Vec3_11220 *)(Vec3_83320 *)(&v));
            }
            break;
        case 4:
            if (!grounded && vel.y * dir->y + vel.z * dir->z + dir->x * vel.x < 0.0f) {
                Vec3_83320 v;
                v.x = -(scale * dir->x);
                v.y = 0.0f;
                v.z = -(scale * dir->z);
                ((owners::Vec3_11220 *)&(pose.pos))->FUN_00011220((const owners::Vec3_11220 *)(Vec3_83320 *)(&v));
                state = 1;
                f24 = 0.0f;
            }
            break;
        case 6:
            if (grounded) {
                if (f24 > f20) {
                    FUN_00082d30(&pose);
                    pose.pos.y = anchor->y;
                    vel.y = 0.0f;
                    ((Part_83320 *)((owners::C_1d72e0 *)body)->FUN_001d72e0())->FUN_002ef8b0(0);
                    state = 8;
                    f24 = 0.0f;
                } else {
                    f20 = 2.0f;
                }
            }
            break;
        }
    } else {
        if ((unsigned int)state <= 8 && state != 3 && state != 7) {
            body->FUN_001d7510();
            state = 7;
            f24 = 0.0f;
        }
    }

    if (((Part_83320 *)((owners::C_1d72e0 *)body)->FUN_001d72e0())->f6c == 0)
        body->FUN_001d6b60(pose, 0);
}

} // namespace fn_ff46a245

// 0x000835a0 FUN_000835a0 (1388 B): equivalent/0x000835a0.cpp [wrapped: conflict: DAT_004dd700; World]
// sym: ?FUN_000835a0@Action@fn_000835a0@@QAEXM@Z @e54f8479441b @w3f25e55098f7
inline void operator delete(void*, void*) {}
inline void* operator new(size_t, void* p) {
    return p;
}
namespace fn_000835a0 {
// STATUS: equivalent (tools/equiv.py level 3: 2743 inputs, branch coverage 79/79)
// FUN_000835a0 @ 0x000835a0
// equiv-conv: FUN_00082d30 esi
namespace content {
namespace LoadInventory {
class __declspec(novtable) DynamicCasterBase {
  public:
    virtual void cast(void*);
};
template <class T> class DynamicCaster : public DynamicCasterBase {
  public:
    virtual void cast(void*);
};
} // namespace LoadInventory
} // namespace content
namespace pure3d {
class Animation;
}


struct Vec3_835a0 {
    float x, y, z;
    float FUN_0022d110();
};
struct Mat_835a0 {
    float m[16];
    void FUN_0022c3b0(Vec3_835a0*, Vec3_835a0*);
    void FUN_0022cc90(Vec3_835a0*);
};
void __cdecl FUN_00224d70(float, Vec3_835a0*);
void FUN_00082d30(Mat_835a0*);
struct Rng_835a0 {
    unsigned int s0, s1;
    float FUN_000787e0(float, float);
};
Rng_835a0* FUN_000964d0();
struct Chan_835a0 {
    void* FUN_00288960(unsigned int, unsigned int);
};
struct Anim_835a0 {
    Chan_835a0* FUN_00288a20(int);
};
class Factory_835a0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual Anim_835a0* f3(content::LoadInventory::DynamicCaster<pure3d::Animation>*, unsigned int,
                           unsigned int);
};
struct Holder44_835a0 {
    Factory_835a0* FUN_00203d70();
};
struct Holder28_835a0 {
    Holder44_835a0* FUN_000862a0();
};
struct VObj70 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual char v11();
};
struct EntB {
    char pad00[0x6c];
    int f6c;
    VObj70* f70;
    void FUN_002ef8b0(int);
};
struct Ent_835a0 {
    char pad00[0x114];
    int f114;
    EntB* FUN_001d72e0();
    void FUN_001d7510();
};
struct Fighter_835a0 {
    void FUN_00059a50(Vec3_835a0*);
};
struct Player_835a0 {
    char pad00[0x10];
    Fighter_835a0* f10;
};
struct List_835a0 {
    char pad00[0x124];
    Player_835a0* player;
};
class Action;
struct Mgr2_835a0 {
    void FUN_001ebc80(Action*, const char*);
};
struct World {
    void FUN_001dd520(int, Mat_835a0*);
    char FUN_001dd800(int);
    Ent_835a0* FUN_001dc0d0(int);
    Vec3_835a0* FUN_001dc3b0(int);
    void FUN_001dd470(int, Mat_835a0*, float);
};
struct Globals_835a0 {
    char pad00[0xc];
    World* world;
    char pad10[0x10];
    List_835a0* list;
    char pad24[0x10];
    Mgr2_835a0* mgr2;
    char pad38[0x1c];
    Holder28_835a0* holder;
};

#define DAT_004dd700 (*(Globals_835a0* *)&::DAT_004dd700)

struct Entry_835a0 {
    int id0, id1;
    char b08;
    char pad09[7];
};
class Ctl_835a0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(float);
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16(int);
    virtual void v17();
    virtual void v18(int);
    virtual int v19();
    virtual void v20();
    virtual void v21();
    virtual char v22();
    virtual void v23();
    virtual void v24(void*, int, float);
};
class Action {
  public:
    char pad00[0x10];
    int f10, state, prevState;
    char b1c, b1d, pad1e[2];
    float f20, f24, f28, f2c, f30, f34;
    Anim_835a0* f38;
    Ctl_835a0* f3c;
    Chan_835a0* f40;
    void *f44, *f48;
    void FUN_00082db0(float, Mat_835a0*);
    void FUN_00083080(Mat_835a0*, Vec3_835a0*, float);
    void FUN_000835a0(float);
};
void Action::FUN_000835a0(float dt) {
    World* world = DAT_004dd700->world;
    Mat_835a0 transform;
    world->FUN_001dd520(f10, &transform);
    Ent_835a0* entity = 0;
    char alive = world->FUN_001dd800(f10);
    if (alive) {
        entity = world->FUN_001dc0d0(f10);
        if (entity->f114) {
            if (state != 5) {
                state = 5;
                f24 = 0.0f;
            }
        } else if (state == 5) {
            state = 6;
            f24 = 0.0f;
        }
    }
    if (state != prevState) {
        prevState = state;
        int count = ((int*)&DAT_003ff8bc)[state];
        Rng_835a0* rng = FUN_000964d0();
        unsigned int a = rng->s0;
        rng->s0 = (a & 0xffff) * 0x9069 + (a >> 16);
        unsigned int b = rng->s1;
        rng->s1 = (b & 0xffff) * 0x4650 + (b >> 16);
        unsigned int random = ((rng->s1 & 0xffff) + (rng->s0 << 16)) % (unsigned int)count;
        int index = random + ((int*)&DAT_003ff8e0)[state];
        Factory_835a0* factory = DAT_004dd700->holder->FUN_000862a0()->FUN_00203d70();
        Entry_835a0* entry = &((Entry_835a0*)&DAT_004dd270)[index];
        char casterStorage[sizeof(content::LoadInventory::DynamicCaster<pure3d::Animation>)];
        content::LoadInventory::DynamicCaster<pure3d::Animation>* caster =
            new (casterStorage) content::LoadInventory::DynamicCaster<pure3d::Animation>;
        f38 = factory->f3(caster, entry->id0, entry->id1);
        if (!f38)
            return;
        f40 = f38->FUN_00288a20(0);
        if (f40) {
            f44 = f40->FUN_00288960(0x4e415254, 0x54434556);
            f48 = f40->FUN_00288960(0x544f52, 0x544f52);
        } else {
            f44 = 0;
            f48 = 0;
        }
        float blend = b1c ? 0.0f : 10.0f;
        b1c = 0;
        if (alive && b1d)
            f3c->v24(f38, 0, blend);
        char selected = entry->b08;
        f3c->v16(2);
        f3c->v18(selected ? 0 : 1);
        Mgr2_835a0* manager = DAT_004dd700->mgr2;
        switch (state) {
        case 0:
            f20 = FUN_000964d0()->FUN_000787e0(2.0f, 10.0f);
            f34 = f30 = f2c = 0.0f;
            break;
        case 1:
            f20 = FUN_000964d0()->FUN_000787e0(30.0f, 60.0f);
            f34 = f30 = f2c = 0.0f;
            break;
        case 2: {
            Vec3_835a0 direction, rotated;
            direction.x = 0.0f;
            direction.y = 0.0f;
            direction.z = 1.0f;
            transform.FUN_0022c3b0(&direction, &rotated);
            volatile float angle = FUN_000964d0()->FUN_000787e0(-0.03f, 0.03f);
            FUN_00224d70(angle, &rotated);
            transform.FUN_0022cc90(&rotated);
            f20 = FUN_000964d0()->FUN_000787e0(2.0f, 15.0f);
            break;
        }
        case 4:
            f3c->v8(1.5f);
            f20 = FUN_000964d0()->FUN_000787e0(5.0f, 20.0f);
            if (entity)
                entity->FUN_001d72e0()->FUN_002ef8b0(0);
            manager->FUN_001ebc80(this, "moo");
            break;
        case 5:
            manager->FUN_001ebc80(this, "moo");
            f20 = 3.4028235e+38f;
            break;
        case 6:
            if (entity)
                entity->FUN_001d7510();
            manager->FUN_001ebc80(this, "moo");
            f20 = 3.4028235e+38f;
            break;
        case 7:
            if (entity)
                entity->FUN_001d7510();
            manager->FUN_001ebc80(this, "moo");
            f20 = 1.0f;
            break;
        case 8:
            if (entity)
                entity->FUN_001d72e0()->FUN_002ef8b0(0);
            f20 = 3.4028235e+38f;
            break;
        default:
            f20 = 3.4028235e+38f;
            break;
        }
    }
    volatile float elapsed = dt + f24;
    f24 = elapsed;
    f28 = dt + f28;
    if (state == 4) {
        Vec3_835a0 delta;
        DAT_004dd700->list->player->f10->FUN_00059a50(&delta);
        Vec3_835a0* position = DAT_004dd700->world->FUN_001dc3b0(f10);
        delta.x = delta.x - position->x;
        delta.y = delta.y - position->y;
        delta.z = delta.z - position->z;
        delta.FUN_0022d110();
        delta.x = delta.x * -1.0f;
        delta.y = delta.y * -1.0f;
        delta.z = delta.z * -1.0f;
        FUN_00083080(&transform, &delta, 0.01f);
    } else if (state == 5)
        f28 = 0.0f;
    else if (state == 8 && !alive && elapsed > 1.5f) {
        state = 0;
        f24 = 0.0f;
    }
    bool transition = false;
    if (f3c->v19() == 0 && f24 >= f20)
        transition = true;
    else if (f3c->v22())
        transition = true;
    if (transition) {
        switch (state) {
        case 0:
        case 4:
            state = 2;
            f24 = 0.0f;
            break;
        case 1:
        case 2:
        case 3:
        case 5:
            state = 0;
            f24 = 0.0f;
            break;
        case 6:
            break;
        case 7:
            if (alive && entity && entity->FUN_001d72e0()->f70->v11()) {
                FUN_00082d30(&transform);
                f30 = 0.0f;
                entity->FUN_001d72e0()->FUN_002ef8b0(0);
                state = 8;
                f24 = 0.0f;
            }
            break;
        default:
            state = 0;
            f24 = 0.0f;
            break;
        }
    }
    if (alive)
        FUN_00082db0(dt, &transform);
    else {
        transform.m[12] = dt * f2c + transform.m[12];
        transform.m[13] = dt * f30 + transform.m[13];
        f28 = 0.0f;
        transform.m[14] = dt * f34 + transform.m[14];
    }
    if (!alive || entity->FUN_001d72e0()->f6c == 0)
        world->FUN_001dd470(f10, &transform, dt);
    b1d = alive;
}
} // namespace fn_000835a0
#undef DAT_004dd700


// 0x00083ba0 FUN_00083ba0 (55 B): matches/0x00083ba0.cpp
// sym: ?FUN_00083ba0@Vec_83ba0@owners@@QAEXPBU12@@Z
void owners::Vec_83ba0::FUN_00083ba0(const owners::Vec_83ba0* a) {
    float yy = a->x * z - a->z * x;
    float zz = a->y * x - ((volatile const float*)a)[0] * y;
    float xx = a->z * y - a->y * z;
    x = xx;
    y = yy;
    z = zz;
}

namespace fn_ff46a245 {

// 0x00083be0 FUN_00083be0 (59 B): matches/0x00083be0.cpp
// sym: ?Cross@Vec@fn_ff46a245@@QAEXABU12@0@Z
void Vec::Cross(const Vec& a, const Vec& b) {
    float yy = b.x * a.z - b.z * a.x;
    float zz = ((const volatile Vec&)b).y * a.x - ((const volatile Vec&)b).x * a.y;
    float xx = b.z * a.y - b.y * a.z;
    x = xx;
    y = yy;
    z = zz;
}


// 0x00083c30 FUN_00083c30 (183 B): equivalent/0x00083c30.cpp
// sym: ??0CVehicle@fn_ff46a245@@QAE@IIIIIIIIIIIII@Z @6fcd5fb2a068 @wcc6d041fb625
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00083c30 @ 0x00083c30
CVehicle::CVehicle(Word_83c30 a1,Word_83c30 a2,Word_83c30 a3,Word_83c30 a4,Word_83c30 a5,Word_83c30 a6,Word_83c30 a7,Word_83c30 a8,Word_83c30 a9,Word_83c30 a10,Word_83c30 a11,Word_83c30 a12,Word_83c30 a13) {
 value18=a12; value1c=a12;
 value34=a2; value38=a3; value3c=a4; value40=a5;
 position.x=a6; position.y=a7; position.z=a8;
 rotation.x=a9; rotation.y=a10; rotation.z=a11;
 value5c=a13;
 originalPosition.x=a6; originalPosition.y=a7; originalPosition.z=a8;
 state=0; flag=0; state20=0; state24=0; state28=0; flag2c=0; flag2d=0; state30=0; stateb8=0; statebc=0;
 handle.FUN_0027b040(a1);
}


// 0x00083d10 FUN_00083d10 (4 B): matches/0x00083d10.cpp
// sym: ?FUN_00083d10@fn_ff46a245@@YIEPAVTarget_83d10@1@@Z
unsigned char __fastcall FUN_00083d10(Target_83d10* self) {
    return self->value;
}

} // namespace fn_ff46a245

// 0x00083d20 FUN_00083d20 (10 B): matches/0x00083d20.cpp
// sym: ?FUN_00083d20@Thing_83d20@owners@@QAEXH@Z
void owners::Thing_83d20::FUN_00083d20(int x) {
    value = x;
}

namespace fn_ff46a245 {

// 0x00083d30 FUN_00083d30 (27 B): matches/0x00083d30.cpp
// sym: ?FUN_00083d30@fn_ff46a245@@YIXPAVA_83d30@1@PAXM@Z
void __fastcall FUN_00083d30(A_83d30* self, void*, float x) {
    if (x >= 0.0f)
        self->value = x;
}

} // namespace fn_ff46a245

// 0x00083d50 FUN_00083d50 (10 B): matches/0x00083d50.cpp
// sym: ?FUN_00083d50@C_83d50@owners@@QAEXH@Z
void owners::C_83d50::FUN_00083d50(int x) {
    value = x;
}


// 0x00083d60 FUN_00083d60 (10 B): matches/0x00083d60.cpp
// sym: ?FUN_00083d60@Target_83d60@owners@@QAEXH@Z
void owners::Target_83d60::FUN_00083d60(int v) {
    value = v;
}


// 0x00083d70 FUN_00083d70 (10 B): matches/0x00083d70.cpp
// sym: ?FUN_00083d70@C_83d70@owners@@QAEXH@Z
void owners::C_83d70::FUN_00083d70(int x) {
    value = x;
}

namespace fn_ff46a245 {

// 0x00083d90 FUN_00083d90 (55 B): matches/0x00083d90.cpp
// sym: _FUN_00083d90
// data: negone = DAT_003f3388, one = DAT_003f32dc, zero_83d90 = DAT_003f32e0
extern "C" float FUN_00083d90(float* p) {
    if (*p < DAT_003f32e0)
        return DAT_003f3388;
    if (*p > DAT_003f32e0)
        return DAT_003f32dc;
    return DAT_003f32e0;
}


// 0x00083dd0 FUN_00083dd0 (37 B): matches/0x00083dd0.cpp
// sym: _FUN_00083dd0
extern "C" float* FUN_00083dd0(float* out, float scalar, const float* in) {
    float a = scalar * in[2];
    float b = scalar * in[1];
    float c = scalar * in[0];
    out[0] = c;
    out[1] = b;
    out[2] = a;
    return out;
}


// 0x00083e00 FUN_00083e00 (37 B): matches/0x00083e00.cpp
// sym: _FUN_00083e00
extern "C" Vec3_83e00* FUN_00083e00(Vec3_83e00* out, Vec3_83e00* in, float scale) {
    float z = scale * in->z;
    float y = scale * in->y;
    float x = scale * in->x;
    out->x = x;
    out->y = y;
    out->z = z;
    return out;
}

} // namespace fn_ff46a245
