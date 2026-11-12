// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001f04e0..0x001f0630 (kind game, layer game, confidence medium), dominant class CSoundCommand_StopTunableEvent
#include "tree_prelude.h"
#include "decls/data/game/unknown.h"
#define TREE_TU_BEGIN namespace fn_f622a04d {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f622a04d {} using namespace fn_f622a04d;
namespace fn_f622a04d { extern "C" char DAT_004245a4[]; }   // (x64t6) the game vftables the placeholders stood for (verify_relocs)
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f622a04d {
extern "C" unsigned __int64 __cdecl createPair_002672f0(int, int, int);
extern "C" int __cdecl createOther_002673a0(int, int);
class CSoundCommand_1f04e0 {
  public:
    int a, b, c;
    virtual void run();
    CSoundCommand_1f04e0(int x) : a(0), b(0), c(x) {}
};
struct Pair {
    unsigned __int64 v;
    Pair() : v(0) {}
    void Init(int p) { v = createPair_002672f0(p, 0, 0); }
};
class CSoundCommand_StopTunableEvent : public CSoundCommand_1f04e0 {
  public:
    Pair pair;
    int other, value;
    CSoundCommand_StopTunableEvent(int p, int q, int r, int x);
    virtual void run();
};
class CSoundCommand_1f0530 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
namespace pure3d {
class NonCopyable : public CSoundCommand_1f0530 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
}
void thunk_FUN_00267090(pure3d::NonCopyable*);


// 0x001f04e0 FUN_001f04e0 (80 B): matches/0x001f04e0.cpp
// sym: ??0CSoundCommand_StopTunableEvent@fn_f622a04d@@QAE@HHHH@Z
CSoundCommand_StopTunableEvent::CSoundCommand_StopTunableEvent(int p, int q, int r, int x) : CSoundCommand_1f04e0(x) {
    pair.Init(p);
    other = createOther_002673a0(q, 0);
    value = r;
}


// 0x001f0530 CSoundCommand_StopTunableEvent::vfunc_0 (31 B): matches/0x001f0530.cpp
// sym: ?f2@NonCopyable@pure3d@fn_f622a04d@@UAEPAV123@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = (void**)DAT_004245a4;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_f622a04d

// 0x001f0550 CSoundCommand_StopTunableEvent::vfunc_1 (216 B): equivalent/0x001f0550.cpp [wrapped: conflict: CSoundCommand_StopTunableEvent]
// sym: ?vfunc_1@CSoundCommand_StopTunableEvent@fn_001f0550@@UAEXII@Z @97f5be1a69cd @w817b892d4c1a
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_001f0550 {
// STATUS: equivalent (tools/equiv.py level 3: 20009 inputs, branch coverage 14/14)
// CSoundCommand_StopTunableEvent::vfunc_1 @ 0x001f0550
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

struct Key_1f0550 { unsigned int low, high; };
struct Entry_1f0550 { Key_1f0550 key; unsigned int id; char rest[28]; };
struct Event_1f0550 { char pad[128]; Entry_1f0550 entries[4]; };
struct Playing_1f0550 { void FUN_001f34a0(unsigned int*, int); };
struct Manager_1f0550 { Event_1f0550* FUN_001f31a0(unsigned int); Playing_1f0550* FUN_001f2f30(void*, unsigned int); };
struct Lookup_1f0550 { void* FUN_001e98b0(Key_1f0550*); };
struct SoundSystem_1f0550 { Manager_1f0550* manager; Lookup_1f0550* lookup; };
extern "C++" __declspec(nothrow) unsigned int __cdecl FUN_002673a0(int,int);
struct CSoundCommand_StopTunableEvent {
 virtual void vfunc_0();
 virtual void vfunc_1(unsigned int, unsigned int);
 char pad[12]; Key_1f0550 key; unsigned int id; float fade;
};
void CSoundCommand_StopTunableEvent::vfunc_1(unsigned int arg, unsigned int unused) {
 Event_1f0550* event = (*(SoundSystem_1f0550**)&DAT_004e370c)->manager->FUN_001f31a0(arg);
 if (!event) return;
 void* found = (*(SoundSystem_1f0550**)&DAT_004e370c)->lookup->FUN_001e98b0(&key);
 if (!found) return;
 unsigned int low=key.low, high=key.high;
 for (int i=0;i<4;++i) {
  Entry_1f0550& entry=event->entries[i];
  if (entry.key.low==low && entry.key.high==high && entry.id==id) {
   unsigned __int64 value=FUN_002672f0(0,0,0);
   entry.key.low=(unsigned int)(__int64)value;
   entry.key.high=(unsigned int)(__int64)(value>>32);
   entry.id=FUN_002673a0(0,0);
   break;
  }
 }
 Playing_1f0550* playing=(*(SoundSystem_1f0550**)&DAT_004e370c)->manager->FUN_001f2f30(found,arg);
 if (playing) {
  int duration=(int)(__int64)fade;
  playing->FUN_001f34a0(&id,duration);
 }
}
} // namespace fn_001f0550
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

