// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00171d10..0x00171e60 (kind game, layer game, confidence high), dominant class hulkfight::motion::TeleportToLocatorAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f87ef82d {
#define TREE_TU_END }
namespace fn_f87ef82d {} using namespace fn_f87ef82d;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f87ef82d {
struct B_171d10 {
    int go();
};
struct A_171d10 {
    B_171d10* go();
};
struct C_171d10 {
    void go(const char*);
};
struct D {
    void go(void*, int);
};
class Locator {
  public:
    char pad[0x10];
    int value;
};
class Helper_171d70 {
  public:
    int invoke(int);
};
class TeleportToLocatorAction {
  public:
    char pad[0x18];
    Locator* locator;
    int active;
    char pad2[4];
    Helper_171d70 helper;
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool vfunc_3(int, int);
};

} // namespace fn_f87ef82d

// 0x00171d10 hulkfight::motion::TeleportRelativeAction::vfunc_3 (74 B): matches/0x00171d10.cpp
// sym: ?vfunc_3@TeleportRelativeAction@motion@hulkfight@@UAE_NHH@Z
bool hulkfight::motion::TeleportRelativeAction::vfunc_3(hulk_intptr __p0, hulk_intptr ) {
    hulk_intptr r = (*(A_171d10 * *)&this->f_20)->go()->go();
    ((C_171d10*)((char*)this + 0x28))->go("teleport_failed");
    if (!(*(A_171d10 * *)&this->f_20))
        return false;
    if (r)
        ((D*)r)->go((char*)this + 0x28, 0);
    return true;
}

namespace fn_f87ef82d {

// 0x00171d60 hulkfight::motion::TeleportRelativeAction::vfunc_4 (1 B): matches/0x00171d60.cpp
// sym: ?FUN_00171d60@fn_f87ef82d@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_00171d60() {}


// 0x00171d70 hulkfight::motion::TeleportToLocatorAction::vfunc_3 (32 B): matches/0x00171d70.cpp
// sym: ?vfunc_3@TeleportToLocatorAction@fn_f87ef82d@@UAE_NHH@Z
bool TeleportToLocatorAction::vfunc_3(int a, int b) {
    if (!active)
        return false;
    helper.invoke(locator->value);
    return true;
}

} // namespace fn_f87ef82d

// 0x00171d90 hulkfight::motion::TeleportToLocatorAction::vfunc_5 (186 B): equivalent/0x00171d90.cpp [wrapped: conflict: hulkfight::motion::TeleportToLocatorAction]
// sym: ?vfunc_5@TeleportToLocatorAction@motion@hulkfight@fn_00171d90@@UAE_NHH@Z
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_00171d90 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// hulkfight::motion::TeleportToLocatorAction::vfunc_5 @ 0x00171d90
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

struct Vec3_171d90 { float x,y,z; };
struct Actor_171d90 { void FUN_0003f400(Vec3_171d90*); };
struct Intermediate_171d90 { Actor_171d90* FUN_00059a30(); };
struct Source_171d90 { Intermediate_171d90* FUN_000592a0(); };
struct Locator {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(Vec3_171d90*);
};
struct Manager_171d90 { Locator* FUN_001fc8c0(unsigned int,unsigned int); };
struct World { char pad[0x28]; Manager_171d90* manager; };
struct Offset_171d90 { char pad[0x14]; Vec3_171d90 displacement; };
namespace hulkfight { namespace motion {
struct TeleportToLocatorAction {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual bool vfunc_5(int,int);
 char pad[0x18]; Offset_171d90* offset; Source_171d90* source; unsigned int unused; unsigned int key1,key2;
};
bool TeleportToLocatorAction::vfunc_5(int flag,int) {
 if(flag) return true;
 if(!source) return false;
 Intermediate_171d90* intermediate=source->FUN_000592a0();
 Actor_171d90* actor=intermediate->FUN_00059a30();
 Locator* locator=DAT_004dd700->manager->FUN_001fc8c0(key1,key2);
 if(!locator) return false;
 Vec3_171d90 position;
 locator->slot8(&position);
 Vec3_171d90 delta=offset->displacement;
 position.x=delta.x+position.x;
 position.y=delta.y+position.y;
 position.z=delta.z+position.z;
 actor->FUN_0003f400(&position);
 return true;
}
} }
} // namespace fn_00171d90
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f87ef82d {

// 0x00171e50 hulkfight::motion::TeleportToLocatorAction::vfunc_4 (1 B): matches/0x00171e50.cpp
// sym: ?FUN_00171e50@fn_f87ef82d@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_00171e50() {}

} // namespace fn_f87ef82d
