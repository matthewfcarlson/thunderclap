// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002a0b00..0x002a1230 (kind game, layer engine, confidence high), dominant class pure3d::LightGroup
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_fe79e145 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_fe79e145 {} using namespace fn_fe79e145;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_fe79e145 {
extern char DAT_0042d668[];
struct Vec3_2a0b00 { float x, y, z; };
struct Light {
    hulk_intptr vptr;
    char pad04[0xc];
    char b10, b11, b12, b13;
    int f14;
    Vec3_2a0b00 v18;
    int f24;
    char pad28[4];
    int f2c;
    Vec3_2a0b00 v30;
    Vec3_2a0b00 v3c;
    int f48, f4c, f50, f54;
    void FUN_0027b0b0(const Light *src);
    Light *FUN_002a0b00(const Light *src);
};
struct Vec3_2a0ba0 { float x,y,z; };
struct Object {
 char pad[0x30];
 Vec3_2a0ba0 value;
 Vec3_2a0ba0 limit;
 void set(const Vec3_2a0ba0* v, const Vec3_2a0ba0* upper);
};
struct Vec3_2a0d00 {
    float x, y, z;
};
union FBits_2a0d00 {
    float f;
    unsigned int u;
};
float FUN_00284a10(float t);
class Falloff {
public:
    char pad0[0x18];
    Vec3_2a0d00 center;
    int pad24;
    int pad28;
    int mode;
    float innerX;
    float innerY;
    float innerZ;
    float outerX;
    float outerY;
    float outerZ;
    float sinA;
    float cosA;
    hulk_freg FUN_002a0d00(const Vec3_2a0d00* p);
};
class Item_2a0fc0 {
  public:
    virtual void First();
    virtual void Second();
};
class Owner_2a0fc0 {
  public:
    char pad[0x18];
    Item_2a0fc0** items;
    void Set(int index, Item_2a0fc0* value);
};
extern "C" void* FUN_0008d6d0(hulk_uintptr);
extern "C" int * __cdecl FUN_002a1010(int *, int, const int *);
class Root {
  public:
    Root();
    virtual void f();
    char pad[12];
};
class Entity_2a1100 : public Root {
  public:
    Entity_2a1100() : a(0), b(0) {}
    int a, b;
};
class LightGroup : public Entity_2a1100 {
  public:
    LightGroup();
    virtual void f();
    int c, d;
};
} // namespace fn_fe79e145
namespace pure3d {
class Entity_2a1130 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    char pad[0x100];
};
}
namespace fn_fe79e145 {
struct Sub_2a1180 {
};
extern int hulk_at_0042d694;
extern void Free_0008d340(void*);
class Ref_2a11b0 {
  public:
    virtual void f0();
    virtual void Release();
};
class Entity_2a11b0 {
  public:
    void* vptr;
    ~Entity_2a11b0() throw();
};
class LightGroup_2a11b0 : public Entity_2a11b0 {
  public:
    char p[0xc];
    int n;
    int cap;
    Ref_2a11b0** arr;
    ~LightGroup_2a11b0() throw();
};


// 0x002a0b00 FUN_002a0b00 (155 B): equivalent/0x002a0b00.cpp
// sym: ?FUN_002a0b00@Light@fn_fe79e145@@QAEPAU12@PBU12@@Z @a4a424719a86 @wd956682ca2f7
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002a0b00 @ 0x002a0b00
Light *Light::FUN_002a0b00(const Light *src)
{
    FUN_0027b0b0(src);
    vptr = (hulk_intptr)DAT_0042d668;
    b10 = 0;
    b11 = src->b11;
    b12 = src->b12;
    b13 = 0;
    f14 = src->f14;
    v18 = src->v18;
    f24 = -1;
    f2c = src->f2c;
    v30 = src->v30;
    v3c = src->v3c;
    f48 = src->f48;
    f4c = src->f4c;
    f50 = 0;
    f54 = src->f54;
    return this;
}


// 0x002a0ba0 FUN_002a0ba0 (284 B): equivalent/0x002a0ba0.cpp
// sym: ?set@Object@fn_fe79e145@@QAEXPBUVec3_2a0ba0@2@0@Z @46ab3894f775 @w951322833b43
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 24/24)
// FUN_002a0ba0 @ 0x002a0ba0
void Object::set(const Vec3_2a0ba0* v, const Vec3_2a0ba0* upper) {
 limit.x = upper->x > 0.0f ? upper->x : 0.0f;
 limit.y = upper->y > 0.0f ? upper->y : 0.0f;
 limit.z = upper->z > 0.0f ? upper->z : 0.0f;
 if (v->x >= 0.0f && v->x <= limit.x) value.x = v->x;
 else if (v->x > limit.x) value.x = limit.x;
 else value.x = 0.0f;
 if (v->y >= 0.0f && v->y <= limit.y) value.y = v->y;
 else if (v->y > limit.y) value.y = limit.y;
 else value.y = 0.0f;
 if (v->z >= 0.0f && v->z <= limit.z) value.z = v->z;
 else if (v->z > limit.z) value.z = limit.z;
 else value.z = 0.0f;
}


// 0x002a0d00 FUN_002a0d00 (568 B): equivalent/0x002a0d00.cpp
// sym: ?FUN_002a0d00@Falloff@fn_fe79e145@@QAEMPBUVec3_2a0d00@2@@Z @395e1be4fc22 @w30f611f15aff
// STATUS: equivalent (tools/equiv.py level 3: 20016 inputs, branch coverage 26/26)
// FUN_002a0d00 @ 0x002a0d00
hulk_freg Falloff::FUN_002a0d00(const Vec3_2a0d00* p)
{
    if (mode == 0)
        return 1.0f;

    if (mode == 1) {
        float inner = innerX;
        float outer = outerX;
        float dx = p->x - center.x;
        float dy = p->y - center.y;
        float dz = p->z - center.z;
        float len = (float)sqrt(dz * dz + dy * dy + dx * dx);
        if (len <= inner)
            return 1.0f;
        if (!(len < outer))
            return 0.0f;
        return FUN_00284a10((outer - len) / (outer - inner));
    }

    if (mode == 2 || mode == 3) {
        FBits_2a0d00 b;
        float dx = p->x - center.x;
        float dy = p->y - center.y;
        float dz = p->z - center.z;

        b.f = dy;
        b.u &= 0x7fffffff;
        float ady = b.f;
        if (ady >= outerY)
            return 0.0f;

        float rx;
        float rz;
        b.f = sinA;
        b.u &= 0x7fffffff;
        if (b.f <= 0.0001f) {
            rx = dx;
            rz = dz;
        } else {
            rx = dx * cosA + dz * sinA;
            rz = dz * cosA - dx * sinA;
        }

        b.f = rx;
        b.u &= 0x7fffffff;
        float arx = b.f;
        b.f = rz;
        b.u &= 0x7fffffff;
        float arz = b.f;
        if (arx >= outerX)
            return 0.0f;
        if (arz >= outerZ)
            return 0.0f;

        float acc = 1.0f;
        if (arx > innerX)
            acc = FUN_00284a10((outerX - arx) / (outerX - innerX));
        if (ady > innerY)
            acc = FUN_00284a10((outerY - ady) / (outerY - innerY)) * acc;
        if (arz > innerZ)
            acc = FUN_00284a10((outerZ - arz) / (outerZ - innerZ)) * acc;
        return acc;
    }
    return 0.0f;
}


// 0x002a0fc0 FUN_002a0fc0 (44 B): matches/0x002a0fc0.cpp
// sym: ?Set@Owner_2a0fc0@fn_fe79e145@@QAEXHPAVItem_2a0fc0@2@@Z
void Owner_2a0fc0::Set(int index, Item_2a0fc0* value) {
    Item_2a0fc0** p = items + index;
    if (value)
        value->First();
    if (*p)
        (*p)->Second();
    *p = value;
}


// 0x002a1010 FUN_002a1010 (40 B): matches/0x002a1010.cpp
// sym: _FUN_002a1010
// Same code shape as 0x002ab530 (propagated; names are from that function)
extern "C" int* FUN_002a1010(int* dst, int count, const int* src) {
    if (count) {
        int n = count;
        int* p = dst;
        const int* s = src;
        do {
            if (p)
                *p = *s;
            p = (int*)((char*)p + 4);
        } while (--n);
        return p;
    }
    return dst;
}

} // namespace fn_fe79e145

// 0x002a10a0 FUN_002a10a0 (95 B): matches/0x002a10a0.cpp
// sym: ?FUN_002a10a0@Buffer_2a10a0@owners@@QAE_NIPAX@Z
// Same code shape as 0x00290790 (propagated; names are from that function)
bool owners::Buffer_2a10a0::FUN_002a10a0(unsigned int count, void* arg) {
    if (begin != 0)
        return false;
    if (count > 0) {
        int* p = (int*)FUN_0008d6d0(count * 4);
        begin = p;
        if (p != 0) {
            end = p + count;
            FUN_002a1010((int *)(void *)p, (unsigned int)count, (const int *)(void *)arg);
            return true;
        }
    }
    begin = 0;
    end = 0;
    return false;
}

namespace fn_fe79e145 {

// 0x002a1100 FUN_002a1100 (32 B): matches/0x002a1100.cpp
// sym: ??0LightGroup@fn_fe79e145@@QAE@XZ
LightGroup::LightGroup() {
    _ReadWriteBarrier();
    c = 0;
    d = 0;
}

} // namespace fn_fe79e145

// 0x002a1120 pure3d::LightGroup::vfunc_3 (3 B): matches/0x002a1120.cpp
// sym: ?vfunc_3@LightGroup@pure3d@@UAE_NXZ
// Same code shape as 0x00050220 (propagated; names are from that function)
bool pure3d::LightGroup::vfunc_3() {
    return (bool)(0);
}


// 0x002a1130 pure3d::LightGroup::vfunc_4 (3 B): matches/0x002a1130.cpp
// sym: ?vfunc_4@LightGroup@pure3d@@UAEPAXXZ
 // namespace pure3d
void* pure3d::LightGroup::vfunc_4() {
    return (void*)(this);
}


// 0x002a1140 FUN_002a1140 (55 B): equivalent/0x002a1140.cpp [wrapped: conflict: pure3d::LightGroup]
// sym: ??0LightGroup@pure3d@fn_002a1140@@QAE@H@Z @4d05ad97e681 @w76cfbf51dba2
namespace fn_002a1140 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002a1140 @ 0x002a1140
struct Entity_2a1140 { Entity_2a1140(); virtual void unused(); }; struct Items { int third; int fourth; void FUN_002a10a0(int, int *); }; namespace pure3d { struct LightGroup : Entity_2a1140 { char pad[12]; int first; int second; Items items; LightGroup(int value); }; } pure3d::LightGroup::LightGroup(int value) { first=value; second=value; items.third=0; items.fourth=0; int zero=0; items.FUN_002a10a0(value,&zero); }
} // namespace fn_002a1140


// 0x002a1180 FUN_002a1180 (42 B): matches/0x002a1180.cpp
// sym: ?FUN_002a1180@A_2a1180@owners@@QAEXH@Z
void owners::A_2a1180::FUN_002a1180(int x) {
    if (a == 0) {
        b = x;
        a = x;
        int t = 0;
        ((owners::Buffer_2a10a0 *)(((Sub_2a1180*)((char*)this + 0x18))))->FUN_002a10a0((unsigned int)x, &t);
    } else {
        b = x;
    }
}

namespace fn_fe79e145 {

// 0x002a11b0 FUN_002a11b0 (81 B): matches/0x002a11b0.cpp
// sym: ??1LightGroup_2a11b0@fn_fe79e145@@QAE@XZ
LightGroup_2a11b0::~LightGroup_2a11b0() throw() {
    vptr = &hulk_at_0042d694;
    for (int i = 0; i < n; i++) {
        Ref_2a11b0* r = arr[i];
        if (r)
            r->Release();
    }
    n = 0;
    cap = 0;
    _ReadWriteBarrier();
    if (arr)
        Free_0008d340(arr);
}

} // namespace fn_fe79e145

// 0x002a1210 pure3d::LightGroup::vfunc_2 (30 B): matches/0x002a1210.cpp
// sym: ??_GLightGroup@pure3d@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
pure3d::LightGroup::~LightGroup() {}

