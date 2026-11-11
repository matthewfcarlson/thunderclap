// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002c3c10..0x002c3e10 (kind game, layer engine, confidence high), dominant class pure3d::ProximityLight
#include "tree_prelude.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_fd752521 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_fd752521 {} using namespace fn_fd752521;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_fd752521 {
class ProximityLight {
  public:
    virtual ~ProximityLight();
    char pad[0x54];
    int a, b;
    float c, d;
    void Init_002a0a70();
};
extern void* hulk_at_0042ee68;
class Base_2c3ce0 {
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9(int arg);
    char pad[0x60];
    int m64;
    void F(int arg);
};
class X_2c3d00 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9(int);
    void set(int, int, int);
};


// 0x002c3c10 FUN_002c3c10 (40 B): matches/0x002c3c10.cpp
// sym: ?FUN_002c3c10@fn_fd752521@@YIPAVProximityLight@1@PAV21@@Z
ProximityLight* __fastcall FUN_002c3c10(ProximityLight* self) {
    self->Init_002a0a70();
    self->a = 0;
    self->b = 0;
    *(void**)self = &hulk_at_0042ee68;
    self->c = 1.0f;
    self->d = 10000000.0f;
    return self;
}

} // namespace fn_fd752521

// 0x002c3ca0 pure3d::ProximityLight::vfunc_8 (25 B): matches/0x002c3ca0.cpp
// sym: ?vfunc_8@ProximityLight@pure3d@@UAEXPAX@Z
// Same code shape as 0x002a07c0 (propagated; names are from that function)
void pure3d::ProximityLight::vfunc_8(void* __p0) { int * p = (int *)__p0;

    vfunc_7(p[0], p[1], p[2]);
}


// 0x002c3cc0 pure3d::ProximityLight::vfunc_7 (31 B): matches/0x002c3cc0.cpp
// sym: ?vfunc_7@ProximityLight@pure3d@@UAEXHHH@Z
void pure3d::ProximityLight::vfunc_7(int x, int y, int z) {
    this->f_18 = x;
    this->f_1c = y;
    this->f_20 = z;
    vfunc_9(1);
}

namespace fn_fd752521 {

// 0x002c3ce0 FUN_002c3ce0 (20 B): matches/0x002c3ce0.cpp
// sym: ?F@Base_2c3ce0@fn_fd752521@@QAEXH@Z
void Base_2c3ce0::F(int arg) {
    m64 = arg;
    arg = 0;
    V9(arg);
}


// 0x002c3d00 FUN_002c3d00 (17 B): matches/0x002c3d00.cpp
// sym: ?set@X_2c3d00@fn_fd752521@@QAEXHHH@Z
void X_2c3d00::set(int a, int b, int c) {
    *(int*)((char*)this + 0x60) = c;
    f9(0);
}

} // namespace fn_fd752521

// 0x002c3d20 FUN_002c3d20 (12 B): matches/0x002c3d20.cpp
// sym: ?FUN_002c3d20@C_2c3d20@owners@@QAEXHHPAH@Z
void owners::C_2c3d20::FUN_002c3d20(hulk_intptr a, hulk_intptr b, int* out) {
    *out = value;
}


// 0x002c3d30 pure3d::ProximityLight::vfunc_2 (43 B): matches/0x002c3d30.cpp [wrapped: conflict: ProximityLight]
// sym: ?vfunc_2@ProximityLight@fn_002c3d30@@UAEPAV12@E@Z
namespace fn_002c3d30 {
class ProximityLight {
  public:
    virtual void f0();
    virtual void f1();
    virtual ProximityLight* vfunc_2(unsigned char);
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    char pad[0x50];
    int value;
};
extern void* light_vtable;
extern "C" void __fastcall FUN_002a0720(void*);
void destroy_00263f30(ProximityLight*);
ProximityLight* ProximityLight::vfunc_2(unsigned char flag) {
    *(void**)this = &light_vtable;
    value = 4;
    FUN_002a0720((void*)(this));
    if (flag & 1)
        destroy_00263f30(this);
    return this;
}
} // namespace fn_002c3d30


// 0x002c3d60 pure3d::ProximityLight::vfunc_9 (170 B): equivalent/0x002c3d60.cpp [wrapped: conflict: pure3d::ProximityLight]
// sym: ?vfunc_9@ProximityLight@pure3d@fn_002c3d60@@UAEXI@Z @bbcd7a2cb79b @w099a624701fe
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_002c3d60 {
// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 2/2)
// pure3d::ProximityLight::vfunc_9 @ 0x002c3d60
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

struct LightData_2c3d60 { unsigned char flag; char padding[3]; unsigned int type; unsigned int color[4]; float direction[3]; unsigned int position[3]; float zero[3]; unsigned int range; };
struct Gfx { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15(); virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19(); virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23(); virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27(); virtual void slot28(); virtual void slot29(); virtual void slot30(); virtual void slot31(); virtual void slot32(); virtual void slot33(); virtual void slot34(); virtual void slot35(); virtual void slot36(); virtual void slot37(unsigned int, LightData_2c3d60*, unsigned int); };
namespace pure3d { struct ProximityLight { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(unsigned int); char pad[12]; unsigned char enabled; unsigned char flag; char pad2[2]; unsigned int color[4]; unsigned int index; char pad3[48]; unsigned int position[3]; unsigned int range; }; }
void pure3d::ProximityLight::vfunc_9(unsigned int arg) { if(enabled) { LightData_2c3d60 data; data.flag=flag; data.type=3; data.color[0]=color[0]; data.color[1]=color[1]; data.color[2]=color[2]; data.color[3]=color[3]; data.direction[0]=0.0f; data.direction[1]=0.0f; data.direction[2]=1.0f; data.position[0]=position[0]; data.position[1]=position[1]; data.position[2]=position[2]; data.zero[0]=0.0f; data.zero[1]=0.0f; data.zero[2]=0.0f; data.range=range; DAT_0052c2a8->slot37(index,&data,arg); } }
} // namespace fn_002c3d60
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

