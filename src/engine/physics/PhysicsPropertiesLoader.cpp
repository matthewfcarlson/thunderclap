// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002f27c0..0x002f2e70 (kind game, layer engine, confidence medium), dominant class physics::PhysicsPropertiesLoader
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/engine/physics.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
#include "gen/physics.h"
#define TREE_TU_BEGIN namespace fn_f6d70462 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f6d70462 {} using namespace fn_f6d70462;
#include "engine/physics.h"

// ---- declarations shared by the functions below
namespace fn_f6d70462 {
struct Entry_2f27c0 {
    int key1, key2;
    int value2, value4;
    int value1, value3, copy2, copy4;
};
struct Table_2f27c0 {
    Entry_2f27c0 entries[64];
    int count;
    Entry_2f27c0* FUN_002f27c0(int key1, int key2, int value1, int value2, int value3, int value4);
};
typedef unsigned __int64 U64;
} // namespace fn_f6d70462
extern "C" U64 __cdecl FUN_0027b020(int);
namespace fn_f6d70462 {
class Manager {
  public:
    void send_002f27c0(U64, int, int, int, int);
};
struct S_2f2900 {
    char pad[16];
    float x;
};
struct S_2f2930 {
    char pad[0x14];
    float x;
};
struct V {
    char pad[8];
    float value;
};
typedef unsigned __int64 Key_2f2970;
struct Reader_2f2970 {  };
struct Context_2f2970 { char pad[0x284]; Reader_2f2970* reader; };
struct Manager_2f2970 { void FUN_002f27c0(Key_2f2970, float, float, float, float); };
typedef unsigned __int64 Key_2f2a80;
extern "C" char DAT_00431394[];
class PhysicsPropertiesLoader {
  public:
    hulk_intptr vptr;
    int a;
    int b;
    int c;
    int d;
    PhysicsPropertiesLoader();
};
extern "C" void thunk_FUN_00267090(void*);
struct Obj_2f2e20 {
    hulk_intptr Init_002f2d10();
};
extern "C" void* __cdecl FUN_0008d690(int);


// 0x002f27c0 FUN_002f27c0 (198 B): equivalent/0x002f27c0.cpp
// sym: ?FUN_002f27c0@Table_2f27c0@fn_f6d70462@@QAEPAUEntry_2f27c0@2@HHHHHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 176 inputs, branch coverage 9/10, incomplete)
// FUN_002f27c0 @ 0x002f27c0
Entry_2f27c0* Table_2f27c0::FUN_002f27c0(int key1, int key2, int value1, int value2, int value3, int value4) {
    int originalCount = count;
    for (int i = 0; i < count; ++i) {
        Entry_2f27c0 &e = entries[i];
        if (e.key1 == key1 && e.key2 == key2) {
            e.key2 = key2;
            e.value1 = value1;
            e.copy2 = value2;
            e.value3 = value3;
            e.key1 = key1;
            e.copy4 = value4;
            e.value2 = value2;
            e.value4 = value4;
            return &e;
        }
    }
    Entry_2f27c0 &e = entries[originalCount];
    e.value1 = value1;
    e.copy2 = value2;
    e.value3 = value3;
    e.copy4 = value4;
    e.value2 = value2;
    e.key1 = key1;
    e.key2 = key2;
    e.value4 = value4;
    Entry_2f27c0 *result = &entries[count];
    ++count;
    return result;
}


// 0x002f28d0 FUN_002f28d0 (47 B): matches/0x002f28d0.cpp
// sym: _FUN_002f28d0
// data: gManager = DAT_00554c30
extern "C" void __cdecl FUN_002f28d0(int a, int b, int c, int d, int e) {
    (*(Manager**)&DAT_00554c30)->send_002f27c0(FUN_0027b020(a), b, c, d, e);
}


// 0x002f2900 FUN_002f2900 (34 B): matches/0x002f2900.cpp
// sym: ?FUN_002f2900@fn_f6d70462@@YAMPAUS_2f2900@1@0@Z
hulk_freg __cdecl FUN_002f2900(S_2f2900* a, S_2f2900* b) {
    float t = b->x;
    float q = a->x;
    if (!(q < t))
        q = t;
    return q;
}


// 0x002f2930 FUN_002f2930 (21 B): matches/0x002f2930.cpp
// sym: ?f@fn_f6d70462@@YAMPAUS_2f2930@1@0@Z
// data: half = DAT_003f32f4
hulk_freg f(S_2f2930* a, S_2f2930* b) {
    return (a->x + b->x) * DAT_003f32f4;
}


// 0x002f2950 FUN_002f2950 (21 B): matches/0x002f2950.cpp
// sym: ?FUN_002f2950@fn_f6d70462@@YAMPAUV@1@0@Z
// data: Half = DAT_003f32f4
hulk_freg __cdecl FUN_002f2950(V* a, V* b) {
    return (a->value + b->value) * DAT_003f32f4;
}

} // namespace fn_f6d70462

// 0x002f2970 physics::PhysicsPropertiesLoader::vfunc_5 (271 B): equivalent/0x002f2970.cpp
// sym: ?vfunc_5@PhysicsPropertiesLoader@physics@@UAEXPAX00H@Z
// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 0/0)
// physics::PhysicsPropertiesLoader::vfunc_5 @ 0x002f2970
void physics::PhysicsPropertiesLoader::vfunc_5(void* __p0, void* __p1, void* __p2, hulk_intptr __p3) { Context_2f2970 * context = (Context_2f2970 *)__p2;

struct Data { char pad[3]; unsigned char length; float a,c,d,b; char name[256]; } data;
((owners::X_2647e0 *)(context->reader))->FUN_002647e0((hulk_intptr)(&data.length), (hulk_intptr)1, 1, (hulk_intptr)1);
unsigned count=data.length;
((owners::X_2647e0 *)(context->reader))->FUN_002647e0((hulk_intptr)(data.name), (hulk_intptr)count, 1, (hulk_intptr)1);
data.name[count]=0;
((owners::X_2647e0 *)(context->reader))->FUN_002647e0((hulk_intptr)(&data.a), (hulk_intptr)1, 4, (hulk_intptr)1);
((owners::X_2647e0 *)(context->reader))->FUN_002647e0((hulk_intptr)(&data.b), (hulk_intptr)1, 4, (hulk_intptr)1);
((owners::X_2647e0 *)(context->reader))->FUN_002647e0((hulk_intptr)(&data.d), (hulk_intptr)1, 4, (hulk_intptr)1);
((owners::X_2647e0 *)(context->reader))->FUN_002647e0((hulk_intptr)(&data.a), (hulk_intptr)1, 4, (hulk_intptr)1);
((owners::X_2647e0 *)(context->reader))->FUN_002647e0((hulk_intptr)(&data.c), (hulk_intptr)1, 4, (hulk_intptr)1);
float x=data.a*0.5f+1.0f, y=data.b+data.b, z=data.c*-1.0f, w=data.d+data.d;
Key_2f2970 key=FUN_0027b020(data.name);
(*(Manager_2f2970**)&DAT_00554c30)->FUN_002f27c0(key,x,y,z,w);
}


// 0x002f2a80 FUN_002f2a80 (461 B): matches/0x002f2a80.cpp
// sym: ?FUN_002f2a80@PhysicsTable_2f2a80@owners@@QAEXXZ
// FUN_002f2a80 @ 0x002f2a80
// physics property table defaults @ 0x002f2a80
void owners::PhysicsTable_2f2a80::FUN_002f2a80() {
    FUN_002f27c0(FUN_0027b020("defaultPhysicsProperties"), 1.5f, 1.0f, -0.75f, 1.0f);
    FUN_002f27c0(FUN_0027b020("defaultArtPhysicsProperties"), 1.05f, 10.0f, -0.25f, 1.0f);
    FUN_002f27c0(FUN_0027b020("hardwood"), 1.5f, 2.0f, -0.75f, 0.97f);
    FUN_002f27c0(FUN_0027b020("softwood"), 1.2f, 2.0f, -0.75f, 0.5f);
    FUN_002f27c0(FUN_0027b020("hardrubber"), 1.9f, 100.0f, 0.5f, 1.3f);
    FUN_002f27c0(FUN_0027b020("softrubber"), 1.1f, 100.0f, 0.5f, 1.3f);
    FUN_002f27c0(FUN_0027b020("hardmetal"), 1.0f, 100000.0f, -0.5f, 10.0f);
    FUN_002f27c0(FUN_0027b020("softmetal"), 1.0f, 100000.0f, -0.5f, 2.7f);
    FUN_002f27c0(FUN_0027b020("concrete"), 1.01f, 1000.0f, -0.8f, 2.3f);
    FUN_002f27c0(FUN_0027b020("sticky"), 1.05f, 100000.0f, 0.0f, 1.0f);
    FUN_002f27c0(FUN_0027b020("icy"), 1.05f, 0.0f, -1.0f, 1.0f);
}

namespace fn_f6d70462 {

// 0x002f2c70 FUN_002f2c70 (27 B): matches/0x002f2c70.cpp
// sym: ??0PhysicsPropertiesLoader@fn_f6d70462@@QAE@XZ
PhysicsPropertiesLoader::PhysicsPropertiesLoader() {
    a = 0;
    b = 0x07011010;
    c = 0;
    d = 0;
    vptr = ((hulk_intptr)DAT_00431394);
}

} // namespace fn_f6d70462

// 0x002f2c90 physics::PhysicsPropertiesLoader::vfunc_2 (31 B): matches/0x002f2c90.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_002f2c90@@UAEPAV123@E@Z
namespace fn_002f2c90 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class SimpleChunkHandler_2f2c90 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* hulk_at_003f6098[];
namespace pure3d {
class NonCopyable : public SimpleChunkHandler_2f2c90 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = hulk_at_003f6098;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_002f2c90


// 0x002f2cb0 FUN_002f2cb0 (57 B): matches/0x002f2cb0.cpp
// sym: ?FUN_002f2cb0@Obj_2f2cb0@owners@@QAEXXZ
void owners::Obj_2f2cb0::FUN_002f2cb0() {
    int* q = data;
    int n = 64;
    do {
        q[-3] = 0;
        q[-2] = 0;
        q[-1] = 0;
        q[0] = 0;
        q[1] = 0;
        q[2] = 0;
        q[3] = 0;
        q[4] = 0;
        q += 8;
    } while (--n);
    end = 0;
    finish();
}

namespace fn_f6d70462 {

// 0x002f2cf0 FUN_002f2cf0 (29 B): matches/0x002f2cf0.cpp
// sym: ?FUN_002f2cf0@fn_f6d70462@@YAXXZ
void FUN_002f2cf0() {
    void* p = (*(void**)&DAT_00554c30);
    if (p)
        thunk_FUN_00267090(p);
    (*(void**)&DAT_00554c30) = 0;
}


// 0x002f2e20 FUN_002f2e20 (56 B): matches/0x002f2e20.cpp
// sym: _FUN_002f2e20
// data: gThing_2f2e20 = DAT_00554c30
extern "C" void __cdecl FUN_002f2e20() {
    if (!(*(Obj_2f2e20**)&DAT_00554c30)) {
        Obj_2f2e20* p = (Obj_2f2e20*)FUN_0008d690(0x808);
        if (p) {
            (*(Obj_2f2e20**)&DAT_00554c30) = (Obj_2f2e20*)p->Init_002f2d10();
            return;
        }
        (*(Obj_2f2e20**)&DAT_00554c30) = 0;
        return;
    }
    ((owners::Obj_2f2cb0 *)((*(Obj_2f2e20**)&DAT_00554c30)))->FUN_002f2cb0();
}

} // namespace fn_f6d70462
