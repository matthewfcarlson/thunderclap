// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 20/20)
// FUN_0008bf80 @ 0x0008bf80
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/records.h"
#include "decls/data/script.h"
#include "decls/data/game/global.h"
inline void* operator new(hulk_uintptr, void* p) { return p; }
extern "C" void* __cdecl FUN_0008d690(unsigned int);
struct Pool { Pool* FUN_0008c7f0(); void FUN_0008c470(int); };
namespace math { class Vector; }
// CGameFlowManager (its 32-bit layout) and the members it binds to Lua, typed by the game's Closure<N> instantiations;
// complete before any pointer to a member is formed (one code pointer on every build).
class CGameFlowManager { public: char padding[0xac0]; void* context; Pool* pool; unsigned int* records; void* other; void FUN_0008bf80(void*,void*);
    int FUN_00023e50(); int FUN_00023e60(); bool FUN_000893c0(); void FUN_000895c0(int); const char* FUN_000897e0(); const char* FUN_00089800(); void FUN_00089820(const char*); void FUN_00089830(const char*); math::Vector FUN_000898d0(); float FUN_00089910(); void FUN_00089920(int); const char* FUN_00089a00(); bool FUN_00089a10(); void FUN_00089ab0(); void FUN_00089f00(const char*,const char*); void FUN_00089f80(const char*); const char* FUN_0008a060(const char*); bool FUN_0008a090(const char*); int FUN_0008a2b0(); const char* FUN_0008a2d0(); const char* FUN_0008a310(); const char* FUN_0008abc0();
};
struct Binding : ScriptFunctionFields { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); void FUN_001d0480(const char*,int); void* FUN_0008b310(const char*,CGameFlowManager*,void (CGameFlowManager::*)(const char*,const char*)); };
template<class C, class R, class A> struct Method1 : Binding { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); R (C::*callback)(A); };
template<class C, class R, class A> struct Closure1 : Method1<C,R,A> { C* owner; virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); };
struct Registry { void FUN_0008bb50(const char*,CGameFlowManager*,int (CGameFlowManager::*)()); void FUN_0008bbc0(const char*,CGameFlowManager*,const char* (CGameFlowManager::*)()); void FUN_0008bc30(const char*,CGameFlowManager*,bool (CGameFlowManager::*)()); void FUN_0008bd40(const char*,CGameFlowManager*,math::Vector (CGameFlowManager::*)()); void FUN_0008bdb0(const char*,CGameFlowManager*,float (CGameFlowManager::*)()); void FUN_0008bf10(const char*,CGameFlowManager*,void (CGameFlowManager::*)()); void FUN_001d3b70(const char*,void*); };
extern "C" Registry* FUN_001d4c90();
#define MAKE(R,A,name,cb,rt,at) { typedef Closure1<CGameFlowManager,R,A> AllocT; HULK_SIZE32(AllocT,0x24); void* mem=FUN_0008d690((unsigned int)sizeof(Closure1<CGameFlowManager,R,A>)); Closure1<CGameFlowManager,R,A>* b=0; if(mem) { Binding* base=(Binding*)mem; base->FUN_001d0480(name,1); Method1<CGameFlowManager,R,A>* m=new(mem) Method1<CGameFlowManager,R,A>; m->callback=&CGameFlowManager::FUN_##cb; m->retType=FUN_001d04d0(&rt); m->argTypes[0]=FUN_001d04d0(&at); b=new(mem) Closure1<CGameFlowManager,R,A>; b->owner=this; } reg->FUN_001d3b70(name,b); }
void CGameFlowManager::FUN_0008bf80(void* first,void* second) {
 Pool* p=(Pool*)FUN_0008d690(12); if(p) p=p->FUN_0008c7f0(); pool=p; p->FUN_0008c470(0xbe8); other=second;
 Registry* reg=FUN_001d4c90(); if(!reg) return;
 reg->FUN_0008bb50("gfm_GetChapter",this,&CGameFlowManager::FUN_00023e50);
 reg->FUN_0008bb50("gfm_GetMission",this,&CGameFlowManager::FUN_00023e60);
 reg->FUN_0008bbc0("gfm_GetChapterMission",this,&CGameFlowManager::FUN_0008a2d0);
 reg->FUN_0008bbc0("gfm_GetCurrentLocation",this,&CGameFlowManager::FUN_000897e0);
 reg->FUN_0008bbc0("gfm_GetPreviousLocation",this,&CGameFlowManager::FUN_00089800);
 reg->FUN_0008bc30("gfm_IsStartingFromFE",this,&CGameFlowManager::FUN_00089a10);
 reg->FUN_0008bc30("gfm_IsStoryModeComplete",this,&CGameFlowManager::FUN_000893c0);
 reg->FUN_0008bb50("gfm_GetDifficulty",this,&CGameFlowManager::FUN_0008a2b0);
 MAKE(void,int,"gfm_SetDifficulty",000895c0,(*(int*)&DAT_0048e100),(*(int*)&DAT_0048e134))
 MAKE(void,int,"gfm_AddJumpMarker",00089920,(*(int*)&DAT_0048e100),(*(int*)&DAT_0048e134))
 reg->FUN_0008bbc0("gfm_GetNextJumpMarkerLocatorName",this,&CGameFlowManager::FUN_00089a00);
 MAKE(void,const char*,"gfm_SetNextMission",00089820,(*(int*)&DAT_0048e100),(*(int*)&DAT_0048e0f0))
 MAKE(void,const char*,"gfm_SetAcquireMission",00089830,(*(int*)&DAT_0048e100),(*(int*)&DAT_0048e0f0))
 reg->FUN_0008bbc0("gfm_GetAcquireMission",this,&CGameFlowManager::FUN_0008a310);
 reg->FUN_0008bd40("gfm_GetMissionSpawnPosition",this,&CGameFlowManager::FUN_000898d0);
 reg->FUN_0008bdb0("gfm_GetMissionSpawnOrientation",this,&CGameFlowManager::FUN_00089910);
 MAKE(void,const char*,"gfm_SetMissionProgress",00089f80,(*(int*)&DAT_0048e100),(*(int*)&DAT_0048e0f0))
 MAKE(bool,const char*,"gfm_GetMissionProgress",0008a090,(*(int*)&DAT_0048e0e4),(*(int*)&DAT_0048e0f0))
 HULK_SIZE32(ScriptClosureView,0x24); Binding* simple=(Binding*)FUN_0008d690((unsigned int)sizeof(ScriptClosureView)); void* s=0; if(simple) s=simple->FUN_0008b310("gfm_SetMissionProgressSimple",this,&CGameFlowManager::FUN_00089f00); reg->FUN_001d3b70("gfm_SetMissionProgressSimple",s);
 MAKE(const char*,const char*,"gfm_GetMissionProgressSimple",0008a060,(*(int*)&DAT_0048e0f0),(*(int*)&DAT_0048e0f0))
 reg->FUN_0008bf10("gfm_UnlockAllStoryMissions",this,&CGameFlowManager::FUN_00089ab0);
 reg->FUN_0008bbc0("gfm_GetNextChapterMissionToComplete",this,&CGameFlowManager::FUN_0008abc0);
 context=first; unsigned int* data=(unsigned int*)FUN_0008d690(0x4ad0); records=data; for(unsigned int i=0;i<0x12b4;++i) data[i]=0;
}
