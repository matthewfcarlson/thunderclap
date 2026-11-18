// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0008ffb0..0x00091af0 (kind game, layer game, confidence high), dominant class CStatsManager
// (tree_prelude.h: not needed)
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/records.h"
#include "decls/data/script.h"
#include "decls/managers.h"
#include "game/script_bind.h"


// 0x00091630 FUN_00091630 (1174 B): equivalent/0x00091630.cpp [wrapped: macros]
// sym: ?initialize@CStatsManager@fn_00091630@@QAEPAU12@XZ @f2b018aa5731 @wd27cdcd017d7 @v60a9b1299ea6
inline void* operator new(hulk_uintptr, void* p) { return p; }
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_00091630 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 26/26)
// FUN_00091630 @ 0x00091630
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


struct Small { unsigned int data[2]; void FUN_0027af00(); };
struct Entry { Small first,second; unsigned int rest[12]; };
struct CStatsManager { union { Entry entries[50]; unsigned int words[800]; }; unsigned int count; unsigned int untouched; unsigned int xp; unsigned int tail[272]; unsigned int secrets; CStatsManager* initialize();
 void FUN_00090630(void*, void*, int, int, int, int); /* (unb4) as defined; address taken only */ void FUN_00090720(void*, int); /* (unb4) as defined; address taken only */ void FUN_000906f0(); void FUN_00090df0(); void FUN_000900a0(); void FUN_00090110(); void FUN_00090130(); void FUN_0008ffb0(); void FUN_000901a0(); int FUN_00090200(void*, int); /* (unb4) as defined; address taken only */ void FUN_0008ffc0(); void FUN_00090270(void*, void*, int); /* (unb4) as defined; address taken only */ void FUN_00090310(); void FUN_000903a0(); void FUN_00090430(); void FUN_00090440(); };
HULK_MGR_SAME(CStatsManager, HulkStatsManager);   // (x64t9-mgr) include/decls/managers.h
// The bound member functions are CStatsManager's; a Binding is a Method<N> / Closure<N> on Function's fields
// (include/decls/data/script.h): the member-function pointer, then (Closure) the object.
typedef void (CStatsManager::*Callback)();
extern "C" void* __cdecl FUN_0008d690(int);
// (script1) A Binding is ScriptClosureView's record (no stand-in vftable): the out-of-line Method constructors
// 0x00090840 / 0x00090c50 build the Method part in place, then the Closure's game vftable (by address) and the object;
// MAKE's Closure1s are include/game/script_bind.h's records.
struct Binding {
 void* vftable; ScriptFunctionFields f; Callback callback; CStatsManager* owner;
 void FUN_00090840(const char*,Callback);
 Binding* FUN_00090eb0(const char*,CStatsManager*,Callback);
 void FUN_00090c50(const char*,Callback);
};
extern "C" char DAT_00400cfc[], DAT_00400d6c[];   // Closure6<CStatsManager,...>, Closure3<CStatsManager,void,char*,char*,int>
extern "C" char DAT_00400c70[], DAT_00400d1c[];   // Method1 / Closure1<CStatsManager,void,const char*>
extern "C" char DAT_00400c80[], DAT_00400d2c[];   // Method1 / Closure1<CStatsManager,void,int>
extern "C" char DAT_00400ca0[], DAT_00400d4c[];   // Method1 / Closure1<CStatsManager,int,const char*>
extern "C" char DAT_00400cd0[], DAT_00400d7c[];   // Method1 / Closure1<CStatsManager,const char*,int>
struct Registry { void FUN_001d3b70(const char*,void*); void FUN_00091450(const char*,CStatsManager*,Callback); void FUN_00091510(const char*,CStatsManager*,Callback); };
extern "C" Registry* FUN_001d4c90();
#define MAKE(NAME,RET,ARG,FUNC,MV,CV) \
 r->FUN_001d3b70(NAME,new hulk_script::ScriptClosure<hulk_script::ScriptMethod1<CStatsManager,RET,ARG>,CStatsManager>(NAME,this,reinterpret_cast<RET (CStatsManager::*)(ARG)>(&CStatsManager::FUNC),MV,CV));
CStatsManager* CStatsManager::initialize() {
 for(int i=0;i<50;++i) { entries[i].first.FUN_0027af00(); entries[i].second.FUN_0027af00(); }
 count=0; for(int j=0;j<800;++j) words[j]=0;
 HULK_SIZE32(Binding, 0x24); HULK_SIZE32(ScriptClosureView, 0x24);
 Registry* r=FUN_001d4c90(); Binding* p=(Binding*)FUN_0008d690((int)sizeof(Binding));
 if(p) { p->FUN_00090840("sta_PrepareStat",(void (CStatsManager::*)())&CStatsManager::FUN_00090630); p->vftable=DAT_00400cfc; p->owner=this; }
 r->FUN_001d3b70("sta_PrepareStat",p);
 p=(Binding*)FUN_0008d690((int)sizeof(ScriptClosureView)); if(p) p=p->FUN_00090eb0("sta_Tally",this,(void (CStatsManager::*)())&CStatsManager::FUN_00090720); r->FUN_001d3b70("sta_Tally",p);
 MAKE("sta_BeginTrial",void,const char*,FUN_000906f0,DAT_00400c70,DAT_00400d1c)
 MAKE("sta_EndTrial",void,const char*,FUN_00090df0,DAT_00400c70,DAT_00400d1c)
 MAKE("sta_AddXP",void,int,FUN_000900a0,DAT_00400c80,DAT_00400d2c)
 r->FUN_00091450("sta_GetXP",this,&CStatsManager::FUN_00090110);
 MAKE("sta_SetXP",void,int,FUN_00090130,DAT_00400c80,DAT_00400d2c)
 r->FUN_00091450("sta_GetXPHighScore",this,&CStatsManager::FUN_0008ffb0);
 MAKE("sta_GetStatValue",int,const char*,FUN_000901a0,DAT_00400ca0,DAT_00400d4c)
 p=(Binding*)FUN_0008d690((int)sizeof(ScriptClosureView)); if(p) p=p->FUN_00090eb0("sta_SetStatValue",this,(void (CStatsManager::*)())&CStatsManager::FUN_00090200); r->FUN_001d3b70("sta_SetStatValue",p);
 r->FUN_00091510("sta_IsFakeXPActive",this,&CStatsManager::FUN_0008ffc0);
 p=(Binding*)FUN_0008d690((int)sizeof(Binding)); if(p) { p->FUN_00090c50("sta_AddDemoGrade",(void (CStatsManager::*)())&CStatsManager::FUN_00090270); p->vftable=DAT_00400d6c; p->owner=this; } r->FUN_001d3b70("sta_AddDemoGrade",p);
 MAKE("sta_GetDemoGrade",const char*,int,FUN_00090310,DAT_00400cd0,DAT_00400d7c)
 MAKE("sta_GetDemoCode",const char*,int,FUN_000903a0,DAT_00400cd0,DAT_00400d7c)
 MAKE("sta_SetDemoSecretsFound",void,int,FUN_00090430,DAT_00400c80,DAT_00400d2c)
 r->FUN_00091450("sta_GetDemoSecretsFound",this,&CStatsManager::FUN_00090440);
 xp=0; for(int k=0;k<272;++k) tail[k]=0; secrets=0; return this;
}
} // namespace fn_00091630
#undef MAKE
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

