// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001b3020..0x001b6800 (kind game, layer game, confidence high), dominant class CCollisionManager
// (tree_prelude.h: not needed)


// 0x001b4620 FUN_001b4620 (174 B): equivalent/0x001b4620.cpp [isolated: code differs from its standalone build]
// sym: ?FUN_001b4620@Owner_1b4620@fn_f2a9d4ea@@QAE_NUVec3_1b4620@2@III@Z
#include "gen/owners.h"
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_f2a9d4ea {} using namespace fn_f2a9d4ea;
namespace fn_f2a9d4ea {
// STATUS: equivalent (tools/equiv.py level 3: 3017 inputs, branch coverage 14/14)
// FUN_001b4620 @ 0x001b4620
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

struct Vec3_1b4620 { float x,y,z; };
struct State_1b4620 { int FUN_00088fa0(); int FUN_00088fb0(); };
struct ContextResult { char pad[0x80]; State_1b4620 state; };
struct Context {  };
struct World { char pad[0x54]; Context* context; };
struct Slot_1b4620 { char pad[0xc]; int status; char rest[0x128]; void FUN_001b3040(Vec3_1b4620 position, unsigned int a); void FUN_001b3760(unsigned int b);  };
struct Owner_1b4620 { char pad[0x10]; Slot_1b4620 slots[4]; bool FUN_001b4620(Vec3_1b4620 position, unsigned int a, unsigned int b, unsigned int c); };
bool Owner_1b4620::FUN_001b4620(Vec3_1b4620 position, unsigned int a, unsigned int b, unsigned int c) {
 State_1b4620* state = &((ContextResult *)((owners::C_86310 *)(DAT_004dd700->context))->FUN_00086310())->state;
 if (state->FUN_00088fa0()==10) { if (state->FUN_00088fb0()==39) return false; if(state->FUN_00088fb0()==45) return false; }
 for(int i=0;i<4;++i) { Slot_1b4620* slot=&slots[i]; if(slot->status<0) { slot->FUN_001b3040(position,a); slot->FUN_001b3760(c); if(b) ((owners::Thing_1b32e0 *)slot)->FUN_001b32e0((hulk_intptr)b); if(c) ((owners::Thing_1b32e0 *)slot)->FUN_001b32e0((hulk_intptr)c); return true; } }
 return false;
}
} // namespace fn_f2a9d4ea
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

