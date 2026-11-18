// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00089400..0x0008c570 (kind game, layer game, confidence high), dominant class CGameFlowManager
// (tree_prelude.h: not needed)
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/records.h"
#include "decls/data/script.h"
#include "game/script_bind.h"


// 0x0008bf80 FUN_0008bf80 (1106 B): equivalent/0x0008bf80.cpp [wrapped: macros]
// sym: ?FUN_0008bf80@CGameFlowManager@fn_0008bf80@@QAEXPAX0@Z @7ebfaa43afca @w5114555809a5 @v3c34f1bcc89f
inline void* operator new(hulk_uintptr, void* p) { return p; }
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_0008bf80 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 20/20)
// FUN_0008bf80 @ 0x0008bf80
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


extern "C" void* __cdecl FUN_0008d690(unsigned int);
struct Pool { void* vftable; int f_04; void* state; Pool* FUN_0008c7f0(); void FUN_0008c470(int); };   // (allocsize1) CMemoryCardManager's words (gen's record): the card state 0x0008c470 allocates is a pointer
namespace math { class Vector; }
// CGameFlowManager (its 32-bit layout) and the members it binds to Lua, typed by the game's Closure<N> instantiations;
// complete before any pointer to a member is formed (one code pointer on every build).
class CGameFlowManager { public: char padding[0xac0]; void* context; Pool* pool; unsigned int* records; void* other; void FUN_0008bf80(void*,void*);
    int FUN_00023e50(); int FUN_00023e60(); bool FUN_000893c0(); void FUN_000895c0(int); const char* FUN_000897e0(); const char* FUN_00089800(); void FUN_00089820(const char*); void FUN_00089830(const char*); math::Vector FUN_000898d0(); float FUN_00089910(); void FUN_00089920(int); const char* FUN_00089a00(); bool FUN_00089a10(); void FUN_00089ab0(); void FUN_00089f00(const char*,const char*); void FUN_00089f80(const char*); const char* FUN_0008a060(const char*); bool FUN_0008a090(const char*); int FUN_0008a2b0(); const char* FUN_0008a2d0(); const char* FUN_0008a310(); const char* FUN_0008abc0();
};
// (script1) the out-of-line Closure2 constructor 0x0008b310 builds gfm_SetMissionProgressSimple in place; MAKE's
// Closure1s are include/game/script_bind.h's records with the game's vftables by address.
struct Binding : ScriptFunctionFields { void* FUN_0008b310(const char*,CGameFlowManager*,void (CGameFlowManager::*)(const char*,const char*)); };
extern "C" char DAT_00400118[], DAT_004001c8[];   // Method1 / Closure1<CGameFlowManager,void,int>
extern "C" char DAT_00400128[], DAT_004001d8[];   // Method1 / Closure1<CGameFlowManager,void,const char*>
extern "C" char DAT_00400158[], DAT_00400208[];   // Method1 / Closure1<CGameFlowManager,bool,const char*>
extern "C" char DAT_00400178[], DAT_00400228[];   // Method1 / Closure1<CGameFlowManager,const char*,const char*>
struct Registry { void FUN_0008bb50(const char*,CGameFlowManager*,int (CGameFlowManager::*)()); void FUN_0008bbc0(const char*,CGameFlowManager*,const char* (CGameFlowManager::*)()); void FUN_0008bc30(const char*,CGameFlowManager*,bool (CGameFlowManager::*)()); void FUN_0008bd40(const char*,CGameFlowManager*,math::Vector (CGameFlowManager::*)()); void FUN_0008bdb0(const char*,CGameFlowManager*,float (CGameFlowManager::*)()); void FUN_0008bf10(const char*,CGameFlowManager*,void (CGameFlowManager::*)()); void FUN_001d3b70(const char*,void*); };
extern "C" Registry* FUN_001d4c90();
#define MAKE(R,A,name,cb,mv,cv) { typedef hulk_script::ScriptClosure<hulk_script::ScriptMethod1<CGameFlowManager,R,A>,CGameFlowManager> AllocT; HULK_SIZE32(AllocT,0x24); reg->FUN_001d3b70(name,new AllocT(name,this,&CGameFlowManager::FUN_##cb,mv,cv)); }
void CGameFlowManager::FUN_0008bf80(void* first,void* second) {
 Pool* p=(Pool*)FUN_0008d690((unsigned int)sizeof(Pool)); /* (allocsize1) the manager by its record (12 B on 32-bit) */ if(p) p=p->FUN_0008c7f0(); pool=p; p->FUN_0008c470(0xbe8); other=second;
 Registry* reg=FUN_001d4c90(); if(!reg) return;
 reg->FUN_0008bb50("gfm_GetChapter",this,&CGameFlowManager::FUN_00023e50);
 reg->FUN_0008bb50("gfm_GetMission",this,&CGameFlowManager::FUN_00023e60);
 reg->FUN_0008bbc0("gfm_GetChapterMission",this,&CGameFlowManager::FUN_0008a2d0);
 reg->FUN_0008bbc0("gfm_GetCurrentLocation",this,&CGameFlowManager::FUN_000897e0);
 reg->FUN_0008bbc0("gfm_GetPreviousLocation",this,&CGameFlowManager::FUN_00089800);
 reg->FUN_0008bc30("gfm_IsStartingFromFE",this,&CGameFlowManager::FUN_00089a10);
 reg->FUN_0008bc30("gfm_IsStoryModeComplete",this,&CGameFlowManager::FUN_000893c0);
 reg->FUN_0008bb50("gfm_GetDifficulty",this,&CGameFlowManager::FUN_0008a2b0);
 MAKE(void,int,"gfm_SetDifficulty",000895c0,DAT_00400118,DAT_004001c8)
 MAKE(void,int,"gfm_AddJumpMarker",00089920,DAT_00400118,DAT_004001c8)
 reg->FUN_0008bbc0("gfm_GetNextJumpMarkerLocatorName",this,&CGameFlowManager::FUN_00089a00);
 MAKE(void,const char*,"gfm_SetNextMission",00089820,DAT_00400128,DAT_004001d8)
 MAKE(void,const char*,"gfm_SetAcquireMission",00089830,DAT_00400128,DAT_004001d8)
 reg->FUN_0008bbc0("gfm_GetAcquireMission",this,&CGameFlowManager::FUN_0008a310);
 reg->FUN_0008bd40("gfm_GetMissionSpawnPosition",this,&CGameFlowManager::FUN_000898d0);
 reg->FUN_0008bdb0("gfm_GetMissionSpawnOrientation",this,&CGameFlowManager::FUN_00089910);
 MAKE(void,const char*,"gfm_SetMissionProgress",00089f80,DAT_00400128,DAT_004001d8)
 MAKE(bool,const char*,"gfm_GetMissionProgress",0008a090,DAT_00400158,DAT_00400208)
 HULK_SIZE32(ScriptClosureView,0x24); Binding* simple=(Binding*)FUN_0008d690((unsigned int)sizeof(ScriptClosureView)); void* s=0; if(simple) s=simple->FUN_0008b310("gfm_SetMissionProgressSimple",this,&CGameFlowManager::FUN_00089f00); reg->FUN_001d3b70("gfm_SetMissionProgressSimple",s);
 MAKE(const char*,const char*,"gfm_GetMissionProgressSimple",0008a060,DAT_00400178,DAT_00400228)
 reg->FUN_0008bf10("gfm_UnlockAllStoryMissions",this,&CGameFlowManager::FUN_00089ab0);
 reg->FUN_0008bbc0("gfm_GetNextChapterMissionToComplete",this,&CGameFlowManager::FUN_0008abc0);
 context=first; unsigned int* data=(unsigned int*)FUN_0008d690(0x4ad0); records=data; for(unsigned int i=0;i<0x12b4;++i) data[i]=0;
}
} // namespace fn_0008bf80
#undef MAKE
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

