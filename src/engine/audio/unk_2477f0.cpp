// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002477f0..0x00247ba0 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/audio.h"
#include "decls/data/game/unknown.h"
#include "decls/data/records.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f5890810 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f5890810 {} using namespace fn_f5890810;
#include "engine/audio.h"

// ---- declarations shared by the functions below
namespace fn_f5890810 {
struct Obj_247810 {
    char pad[0x2c];
    unsigned value;
};
struct S_247890 {
    char pad[8];
    float value;
};
struct Obj_2478b0 {
    char pad[12];
    float value;
};
typedef unsigned char u8_2478d0;
struct Obj_2478d0 {
    char pad[0xb4];
    u8_2478d0 value;
};
struct Obj_2478f0 {
    char pad[0xb4];
    unsigned char flag : 1;
};
typedef unsigned int U32_247930;
class C_247950 {
    char pad[0x30];

  public:
    int state;
    char pad2[4];
    int value;
};
class Obj_247970 {
  public:
    char pad[0x30];
    int state;
    char pad2[4];
    int value;
};
struct X_2479a0 {
    void FnA_0025def0();
    X_2479a0* Target(unsigned char flag);
};
extern int __cdecl FnB_0025d3d0();
extern "C" void __cdecl FUN_00247550(int, X_2479a0*);
struct Obj_247a10 {
    char pad[0x3c];
    u16 value;
};
class Obj_247a20 {
  public:
    void Start_0025dfc0(hulk_intptr, int);
};
class State_247a20 {
  public:
    char pad0[8];
    Obj_247a20* mObj;
    int mStatus;
    char mFlag;
    char pad11[3];
    int mValue;
};
class Callback_247a20 {
  public:
    virtual void A();
    virtual void B(void*, Obj_247a20*);
};
class Owner_247a20 {
  public:
    char pad0[0xac];
    Callback_247a20* mCallback;
};
extern "C" int FUN_0024afe0(Obj_247a20*);
struct Obj_247a90 {
    int pad[3];
    int f0c;
    int pad2[2];
    int f18;
    int f1c;
    int f20;
    float f24;
    int f28;
};
struct Pair {
    int a, b;
};
struct Obj {
  public:
    char _m_pad_0[0xc];
    int kind;
    char flag;
    char _m_pad_11[0x3];
    int val;
    Pair pair;
    int zero;
    float f;
    int other;
    char _m_pad_2c[0x88];
    unsigned char flags;
};
class Sub_247b30 {
  public:
    int x;
};
class Obj_247b30 {
  public:
    int a0;
    int a4;
    Sub_247b30* sub;
    int aC;
    char pad10[8];
    int a18;
    int a1C;
    int a20;
    char pad24[4];
    int a28;
};


// 0x002477f0 FUN_002477f0 (6 B): matches/0x002477f0.cpp
// sym: _FUN_002477f0
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_002477f0() {
    return &(*(int*)&DAT_004e6110);
}


// 0x00247800 FUN_00247800 (6 B): matches/0x00247800.cpp
// sym: _FUN_00247800
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
// DAT_004e6158: a static om type (records.h)
extern "C" int* FUN_00247800() {
    return &(*(int*)&DAT_004e6158);
}


// 0x00247810 FUN_00247810 (8 B): matches/0x00247810.cpp
// sym: _FUN_00247810
extern "C" unsigned __cdecl FUN_00247810(Obj_247810* p) {
    return p->value;
}


// 0x00247890 FUN_00247890 (12 B): matches/0x00247890.cpp
// sym: _FUN_00247890
extern "C" void FUN_00247890(S_247890* p, float v) {
    p->value = v;
}


// 0x002478b0 FUN_002478b0 (12 B): matches/0x002478b0.cpp
// sym: _FUN_002478b0
extern "C" void __cdecl FUN_002478b0(Obj_2478b0* object, float newValue) {
    object->value = newValue;
}


// 0x002478d0 FUN_002478d0 (32 B): matches/0x002478d0.cpp
// sym: _FUN_002478d0
extern "C" void FUN_002478d0(Obj_2478d0* obj, u8_2478d0 param) {
    obj->value = obj->value ^ ((obj->value ^ param) & 1);
}


// 0x002478f0 FUN_002478f0 (13 B): matches/0x002478f0.cpp
// sym: _FUN_002478f0
extern "C" unsigned char __cdecl FUN_002478f0(Obj_2478f0* p) {
    return p->flag;
}


// 0x00247900 FUN_00247900 (30 B): matches/0x00247900.cpp
// sym: _FUN_00247900
extern "C" void __cdecl FUN_00247900(Obj* p, volatile unsigned char v) {
    p->flags = p->flags ^ ((v << 1 ^ p->flags) & 2);
}


// 0x00247930 FUN_00247930 (8 B): matches/0x00247930.cpp
// sym: _FUN_00247930
extern "C" U32_247930 FUN_00247930(hulk_uintptr a, hulk_uintptr b) {
    return *(U32_247930*)(b + 0x0c);
}


// 0x00247950 FUN_00247950 (32 B): matches/0x00247950.cpp
// sym: _FUN_00247950
extern "C" void FUN_00247950(C_247950* self, int value) {
    if (self->state == 3 || self->state == 2) {
        self->state = 1;
        self->value = value;
    }
}


// 0x00247970 FUN_00247970 (31 B): matches/0x00247970.cpp
// sym: _FUN_00247970
extern "C" void FUN_00247970(Obj_247970* self, int value) {
    if (self->state == 1 || self->state == 0) {
        self->state = 3;
        self->value = value;
    }
}


// 0x002479a0 FUN_002479a0 (36 B): matches/0x002479a0.cpp
// sym: ?Target@X_2479a0@fn_f5890810@@QAEPAU12@E@Z
X_2479a0* X_2479a0::Target(unsigned char flag) {
    FnA_0025def0();
    if (flag & 1)
        FUN_00247550(FnB_0025d3d0(), this);
    return this;
}


// 0x00247a10 FUN_00247a10 (9 B): matches/0x00247a10.cpp
// sym: _FUN_00247a10
extern "C" void FUN_00247a10(Obj_247a10* p) {
    ++p->value;
}


// 0x00247a20 FUN_00247a20 (104 B): matches/0x00247a20.cpp
// sym: _FUN_00247a20
extern "C" void FUN_00247a20(Owner_247a20* owner, State_247a20* state, Obj_247a20* obj, int flag, int value) {
    state->mFlag = (char)flag;
    state->mValue = value;
    state->mStatus = 1;
    if (obj) {
        if (((owners::Object_25d3e0 *)(state->mObj))->FUN_0025d3e0() == 0) {
            state->mObj->Start_0025dfc0((hulk_intptr)obj, flag);
            if (FUN_0024afe0(obj) == 2) {
                state->mStatus = 3;
                return;
            }
        } else
            owner->mCallback->B(owner, obj);
    }
}


// 0x00247a90 FUN_00247a90 (65 B): matches/0x00247a90.cpp
// sym: _FUN_00247a90
extern "C" void FUN_00247a90(int p1, Obj_247a90* dst, int* src) {
    dst->f0c = 4;
    if (src != 0) {
        dst->f18 = src[0];
        dst->f1c = src[1];
    } else {
        dst->f18 = 0;
        dst->f1c = 0;
    }
    dst->f28 = 0;
    dst->f20 = 0;
    if (dst->f1c == 0) {
        dst->f24 = 1.0f;
        return;
    }
    dst->f24 = 0.0f;
}


// 0x00247ae0 FUN_00247ae0 (79 B): matches/0x00247ae0.cpp
// sym: _FUN_00247ae0
extern "C" void __cdecl FUN_00247ae0(int unused, Obj* o, char c, int v, Pair* p) {
    o->flag = c;
    o->val = v;
    o->kind = 3;
    if (p)
        o->pair = *p;
    else {
        o->pair.a = 0;
        o->pair.b = 0;
    }
    o->other = 0;
    o->zero = 0;
    if (!o->pair.b) {
        o->f = 1.0f;
        return;
    }
    o->f = 0.0f;
}


// 0x00247b30 FUN_00247b30 (104 B): matches/0x00247b30.cpp
// sym: _FUN_00247b30
extern "C" void __cdecl FUN_00247b30(int p1, Obj_247b30* p2, unsigned int* p3, int* p4) {
    p2->aC = 5;
    if (p3) {
        p2->a18 = p3[0];
        p2->a1C = p3[1];
    } else {
        p2->a18 = 0;
        p2->a1C = 0;
    }
    p2->a28 = 0;
    p2->a20 = 0;
    if (p4) {
        int t = ((owners::Object_25d3e0 *)(p2->sub))->FUN_0025d3e0();
        if (t == 1 || t == 2 || t == 3 || t == 4)
            ((owners::Obj_25d3f0 *)(p2->sub))->FUN_0025d3f0(p4);
        else
            *p4 = 0;
    }
}

} // namespace fn_f5890810
