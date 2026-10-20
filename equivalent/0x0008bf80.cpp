// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 20/20)
// FUN_0008bf80 @ 0x0008bf80
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
typedef unsigned int size_t;
inline void* operator new(size_t, void* p) { return p; }
void* __cdecl FUN_0008d690(hulk_uintptr);
typedef void (*Callback)();
#define CB(a) void FUN_##a();
CB(00023e50) CB(00023e60) CB(000893c0) CB(000895c0) CB(000897e0) CB(00089800) CB(00089820) CB(00089830) CB(000898d0) CB(00089910) CB(00089920) CB(00089a00) CB(00089a10) CB(00089ab0) CB(00089f00) CB(00089f80) CB(0008a060) CB(0008a090) CB(0008a2b0) CB(0008a2d0) CB(0008a310) CB(0008abc0)
struct Pool { Pool* FUN_0008c7f0(); void FUN_0008c470(int); };
class CGameFlowManager;
struct Binding { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); char pad4[12]; unsigned char argumentType; char pad11[7]; unsigned char resultType; char pad19[3]; Callback callback; void FUN_001d0480(const char*,int); void* FUN_0008b310(const char*,CGameFlowManager*,Callback); };
template<class C, class R, class A> struct Method1 : Binding { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); };
template<class C, class R, class A> struct Closure1 : Method1<C,R,A> { C* owner; virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); };
struct Registry { void FUN_0008bb50(const char*,CGameFlowManager*,Callback); void FUN_0008bbc0(const char*,CGameFlowManager*,Callback); void FUN_0008bc30(const char*,CGameFlowManager*,Callback); void FUN_0008bd40(const char*,CGameFlowManager*,Callback); void FUN_0008bdb0(const char*,CGameFlowManager*,Callback); void FUN_0008bf10(const char*,CGameFlowManager*,Callback); void FUN_001d3b70(const char*,void*); };
Registry* FUN_001d4c90();
class CGameFlowManager { public: char padding[0xac0]; void* context; Pool* pool; unsigned int* records; void* other; void FUN_0008bf80(void*,void*); };
#define MAKE(R,A,name,cb,rt,at) { void* mem=FUN_0008d690(0x24); Closure1<CGameFlowManager,R,A>* b=0; if(mem) { Binding* base=(Binding*)mem; base->FUN_001d0480(name,1); Method1<CGameFlowManager,R,A>* m=new(mem) Method1<CGameFlowManager,R,A>; m->callback=cb; m->resultType=FUN_001d04d0(&rt); m->argumentType=FUN_001d04d0(&at); b=new(mem) Closure1<CGameFlowManager,R,A>; b->owner=this; } reg->FUN_001d3b70(name,b); }
void CGameFlowManager::FUN_0008bf80(void* first,void* second) {
 Pool* p=(Pool*)FUN_0008d690(12); if(p) p=p->FUN_0008c7f0(); pool=p; p->FUN_0008c470(0xbe8); other=second;
 Registry* reg=FUN_001d4c90(); if(!reg) return;
 reg->FUN_0008bb50("gfm_GetChapter",this,FUN_00023e50);
 reg->FUN_0008bb50("gfm_GetMission",this,FUN_00023e60);
 reg->FUN_0008bbc0("gfm_GetChapterMission",this,FUN_0008a2d0);
 reg->FUN_0008bbc0("gfm_GetCurrentLocation",this,FUN_000897e0);
 reg->FUN_0008bbc0("gfm_GetPreviousLocation",this,FUN_00089800);
 reg->FUN_0008bc30("gfm_IsStartingFromFE",this,FUN_00089a10);
 reg->FUN_0008bc30("gfm_IsStoryModeComplete",this,FUN_000893c0);
 reg->FUN_0008bb50("gfm_GetDifficulty",this,FUN_0008a2b0);
 MAKE(void,int,"gfm_SetDifficulty",FUN_000895c0,(*(int*)&DAT_0048e100),(*(int*)&DAT_0048e134))
 MAKE(void,int,"gfm_AddJumpMarker",FUN_00089920,(*(int*)&DAT_0048e100),(*(int*)&DAT_0048e134))
 reg->FUN_0008bbc0("gfm_GetNextJumpMarkerLocatorName",this,FUN_00089a00);
 MAKE(void,const char*,"gfm_SetNextMission",FUN_00089820,(*(int*)&DAT_0048e100),(*(int*)&DAT_0048e0f0))
 MAKE(void,const char*,"gfm_SetAcquireMission",FUN_00089830,(*(int*)&DAT_0048e100),(*(int*)&DAT_0048e0f0))
 reg->FUN_0008bbc0("gfm_GetAcquireMission",this,FUN_0008a310);
 reg->FUN_0008bd40("gfm_GetMissionSpawnPosition",this,FUN_000898d0);
 reg->FUN_0008bdb0("gfm_GetMissionSpawnOrientation",this,FUN_00089910);
 MAKE(void,const char*,"gfm_SetMissionProgress",FUN_00089f80,(*(int*)&DAT_0048e100),(*(int*)&DAT_0048e0f0))
 MAKE(bool,const char*,"gfm_GetMissionProgress",FUN_0008a090,(*(int*)&DAT_0048e0e4),(*(int*)&DAT_0048e0f0))
 Binding* simple=(Binding*)FUN_0008d690(0x24); void* s=0; if(simple) s=simple->FUN_0008b310("gfm_SetMissionProgressSimple",this,FUN_00089f00); reg->FUN_001d3b70("gfm_SetMissionProgressSimple",s);
 MAKE(const char*,const char*,"gfm_GetMissionProgressSimple",FUN_0008a060,(*(int*)&DAT_0048e0f0),(*(int*)&DAT_0048e0f0))
 reg->FUN_0008bf10("gfm_UnlockAllStoryMissions",this,FUN_00089ab0);
 reg->FUN_0008bbc0("gfm_GetNextChapterMissionToComplete",this,FUN_0008abc0);
 context=first; unsigned int* data=(unsigned int*)FUN_0008d690(0x4ad0); records=data; for(unsigned int i=0;i<0x12b4;++i) data[i]=0;
}
