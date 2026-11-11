// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002c3e10..0x002c4020 (kind game, layer engine, confidence high), dominant class pure3d::PointLight
#include "tree_prelude.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f06f3165 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f06f3165 {} using namespace fn_f06f3165;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f06f3165 {
class Light_2c3e10 {
  public:
    virtual void f();
    Light_2c3e10();
};
class PointLight : public Light_2c3e10 {
  public:
    char pad[0x50];
    int a;
    float b;
    int c, d, e;
    PointLight();
};
class X_2c3f00 {
  public:
    virtual void f0() {}
    virtual void f1() {}
    virtual void f2() {}
    virtual void f3() {}
    virtual void f4() {}
    virtual void f5() {}
    virtual void f6() {}
    virtual void f7() {}
    virtual void f8() {}
    virtual void f9(int v);
    char pad[0x58 - 4];
    int a;
    int b;
    int c;
    void Set(int x, int y, int z);
};
extern void* hulk_at_0042eeb0[];
class Light_2c3f40 {
  public:
    void Destroy_002a0720(); // FUN_00236d60, __thiscall, this in ecx
};
class PointLight_2c3f40 : public Light_2c3f40 {
  public:
    PointLight_2c3f40* vfunc_5(signed char flags);
};


// 0x002c3e10 FUN_002c3e10 (43 B): matches/0x002c3e10.cpp
// sym: ??0PointLight@fn_f06f3165@@QAE@XZ
PointLight::PointLight() : Light_2c3e10() {
    c = 0;
    d = 0;
    e = 0;
    b = 1.0f;
    a = 1;
}

} // namespace fn_f06f3165

// 0x002c3e90 pure3d::PointLight::vfunc_8 (25 B): matches/0x002c3e90.cpp
// sym: ?vfunc_8@PointLight@pure3d@@UAEXPAX@Z
// Same code shape as 0x002a07c0 (propagated; names are from that function)
void pure3d::PointLight::vfunc_8(void* __p0) { int * p = (int *)__p0;

    vfunc_7(p[0], p[1], p[2]);
}


// 0x002c3eb0 pure3d::PointLight::vfunc_7 (31 B): matches/0x002c3eb0.cpp
// sym: ?vfunc_7@PointLight@pure3d@@UAEXHHH@Z
// Same code shape as 0x002c3cc0 (propagated; names are from that function)
void pure3d::PointLight::vfunc_7(int x, int y, int z) {
    this->f_18 = x;
    this->f_1c = y;
    this->f_20 = z;
    vfunc_9(1);
}

namespace fn_f06f3165 {

// 0x002c3f00 FUN_002c3f00 (31 B): matches/0x002c3f00.cpp
// sym: ?Set@X_2c3f00@fn_f06f3165@@QAEXHHH@Z
void X_2c3f00::Set(int x, int y, int z) {
    a = x;
    b = y;
    c = z;
    f9(0);
}

} // namespace fn_f06f3165

// 0x002c3f20 FUN_002c3f20 (30 B): matches/0x002c3f20.cpp
// sym: ?FUN_002c3f20@C_2c3f20@owners@@QAEXPAH00@Z
// Same code shape as 0x002a2f20 (propagated; names are from that function)
void owners::C_2c3f20::FUN_002c3f20(int* x, int* y, int* z) {
    *x = a;
    *y = b;
    *z = c;
}

namespace fn_f06f3165 {

// 0x002c3f40 pure3d::PointLight::vfunc_2 (36 B): matches/0x002c3f40.cpp
// sym: ?vfunc_5@PointLight_2c3f40@fn_f06f3165@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
PointLight_2c3f40* PointLight_2c3f40::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0042eeb0;
    Destroy_002a0720();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_f06f3165

// 0x002c3f70 pure3d::PointLight::vfunc_9 (171 B): equivalent/0x002c3f70.cpp [wrapped: conflict: pure3d::PointLight]
// sym: ?vfunc_9@PointLight@pure3d@fn_002c3f70@@QAEXI@Z @cebe4c4e8973 @w90d392b8a9d1
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_002c3f70 {
// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 2/2)
// pure3d::PointLight::vfunc_9 @ 0x002c3f70
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

struct LightDescription {
 unsigned char flags; char padding[3]; int type; unsigned int color;
 float value0,value1,value2;
 float directionX,directionY,directionZ;
 float positionX,positionY,positionZ;
 float attenuation0,attenuation1,attenuation2,range;
};
struct Gfx {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
 virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
 virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
 virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23();
 virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27();
 virtual void slot28(); virtual void slot29(); virtual void slot30(); virtual void slot31();
 virtual void slot32(); virtual void slot33(); virtual void slot34(); virtual void slot35();
 virtual void slot36(); virtual void slot37(unsigned int,LightDescription *,unsigned int);
};
namespace pure3d {
struct PointLight {
 char prefix[16]; unsigned char enabled,flags; char padding[2];
 unsigned int color; float value0,value1,value2; unsigned int lightIndex;
 char middle[48]; float positionX,positionY,positionZ;
 void vfunc_9(unsigned int argument);
};
void PointLight::vfunc_9(unsigned int argument) {
 if (enabled) {
 LightDescription description;
 description.flags=flags;
 description.type=1;
 description.color=color;
 description.value0=value0;
 description.value1=value1;
 description.value2=value2;
 description.directionX=0.0f;
 description.directionY=0.0f;
 description.directionZ=1.0f;
 description.positionX=positionX;
 description.positionY=positionY;
 description.positionZ=positionZ;
 description.attenuation0=0.0f;
 description.attenuation1=0.0f;
 description.attenuation2=0.0f;
 description.range=10000000.0f;
 DAT_0052c2a8->slot37(lightIndex,&description,argument);
 }
}
}
} // namespace fn_002c3f70
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

