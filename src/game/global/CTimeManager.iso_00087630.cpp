// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00085d90..0x00088e60 (kind game, layer game, confidence high), dominant class CTimeManager
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x00087630 FUN_00087630 (770 B): equivalent/0x00087630.cpp [isolated: code differs from its standalone build]
// sym: ?run@Target_87630@fn_f2137440@@QAEXXZ @3a76108f2538 @wec9d503a55b9 @v473f58440276
#include "gen/owners.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_f2137440 {} using namespace fn_f2137440;
namespace fn_f2137440 {
// STATUS: equivalent (tools/equiv.py level 3: 17507 inputs, branch coverage 36/36)
// FUN_00087630 @ 0x00087630
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

struct Target_87630;
struct Queue_87630 { void FUN_0008db00(); };
// (gfx3) 0x0008db20 / 0x0008db80 as defined (unk_08ceb0.cpp): a member / bool spelling bound nothing natively, so the
// loop read "not running" and quit (mode 8) on its first frame
extern "C" bool __stdcall FUN_0008db20(hulk_intptr game);
extern "C" unsigned char __cdecl FUN_0008db80(); extern "C" void __cdecl FUN_0008db90();
struct State_87630 { int mode; int unused; int saved; };
struct Clock_87630 { char pad[32]; unsigned __int64 ticks; void FUN_00086450(); hulk_freg FUN_000860c0(); };
struct Sim_87630 { void* words[11]; /* (gfx3) the World's words (HulkWorld: vftable, parts[0..9]) */ void* item; void FUN_00088c30(State_87630*,float);  };
struct Notify_87630 { void FUN_000afe80(); };
struct Sub_87630 { void* words[6]; /* (gfx3) CGame's words (HulkGame) */ Notify_87630* notify; };
struct World { void* vftable; void* parts[20];   /* (sweep2) the World's words (HulkWorld): +0x54 is CGame */ Sub_87630 *sub; }; 
struct Stop_87630 { void FUN_001b7970(); };
struct Update_87630 { void FUN_001eb2a0(float,bool); };   // (gfx4) as defined
struct Check_87630 { bool FUN_00089e80(void*,unsigned int); };
struct UI_87630 { void FUN_0023f6b0(); void FUN_0023f720(int*,int); bool FUN_0023f760(const char*,int,int); void FUN_0023f740(); void FUN_0023f6c0(); };  
struct Gate_87630 { unsigned int FUN_000b4f20(); }; struct Singleton_4dd6ec { void* words[8]; /* (gfx3) CGame's words (HulkGame) */ Gate_87630* gate; }; 
struct Audio_87630 { void FUN_001d1160(float); void FUN_001d15d0(int); }; Audio_87630* __cdecl FUN_001d4c90();
extern "C" unsigned int __cdecl FUN_00267f80(); unsigned int __cdecl FUN_00267f00(); float __cdecl FUN_00085e60(unsigned int,int); extern "C" void __cdecl FUN_00240bb0();
 
// (gfx3) CGame (decls/managers.h's HulkGame) by its pointer words: its 32-bit pads put the platform queue, the sound
// update, the FMV stop and the game-flow check one or more words early natively
struct Target_87630 { void* vftable; State_87630* state; Clock_87630* clock; Sim_87630* sim; void* controllers; void* gameControllers; void* haptic; Queue_87630* queue; void* frontEnd; void* render; void* worldStream; void* overlay; Update_87630* update; Stop_87630* stop; Check_87630* check; void FUN_00086ad0(); void FUN_00086790(); void FUN_000873a0(); void FUN_00086a40(float); void run(); };
void Target_87630::run() {
 queue->FUN_0008db00();
 if (!FUN_0008db20((hulk_intptr)this)) { if(state->mode==7) stop->FUN_001b7970(); else if(state->mode==6) { state->mode=state->saved; state->saved=0; DAT_004dd700->sub->notify->FUN_000afe80(); } state->mode=8; DAT_004dd700->sub->notify->FUN_000afe80(); }
 if(queue && FUN_0008db80()) { do { FUN_0008db90(); queue->FUN_0008db00(); } while(FUN_0008db80()); }
 FUN_00086ad0(); if(state->mode==3) { FUN_00086790(); return; }
 clock->FUN_00086450(); FUN_000873a0();
 if(state->mode!=7) { Audio_87630* a=FUN_001d4c90(); a->FUN_001d1160(clock->ticks * 0.000001f); a->FUN_001d15d0(0); }
 unsigned int start=FUN_00267f80(); FUN_00086a40(clock->ticks * 0.000001f);
 if(state->mode==8) return;
 unsigned int start2=0; if((*(unsigned char*)&DAT_004dd8e4)) start2=FUN_00267f00();
 if(state->mode==4) { (*(UI_87630**)&DAT_004dd6e8)->FUN_0023f6b0(); (*(UI_87630**)&DAT_004dd6e8)->FUN_0023f720(&DAT_0049c218,0); if((*(UI_87630**)&DAT_004dd6e8)->FUN_0023f760("Enable simulation",83,1)) { hulk_freg v=clock->FUN_000860c0(); sim->FUN_00088c30(state,v); } (*(UI_87630**)&DAT_004dd6e8)->FUN_0023f740(); void* item=sim->item; unsigned int result=DAT_004dd6ec->gate->FUN_000b4f20(); unsigned int disabled=(result & 0xffffff00u) | ((result & 255u)==0 ? 1u:0u); if(check->FUN_00089e80(item,disabled)) { state->mode=5; DAT_004dd700->sub->notify->FUN_000afe80(); } (*(UI_87630**)&DAT_004dd6e8)->FUN_0023f6c0(); if(((int)(hulk_uintptr)((owners::A_88e40 *)sim)->FUN_00088e40())) { state->mode=5; DAT_004dd700->sub->notify->FUN_000afe80(); return; } }
 unsigned int end=FUN_00267f80(); unsigned __int64 elapsed=(unsigned __int64)end-(unsigned __int64)start; update->FUN_001eb2a0(elapsed*0.001f,1);
 if((*(unsigned char*)&DAT_004dd8e4)) { unsigned int e=FUN_00267f00(); if((*(unsigned char*)&DAT_004dd8e4)) DAT_004dd914=FUN_00085e60(e-start2,0); }
 if(DAT_0049caa0 && state->mode!=7) FUN_00240bb0();
}
} // namespace fn_f2137440
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

