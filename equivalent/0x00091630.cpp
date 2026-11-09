// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 26/26)
// FUN_00091630 @ 0x00091630
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/records.h"
#include "decls/data/script.h"
inline void* operator new(hulk_uintptr, void* p) { return p; }
struct Small { unsigned int data[2]; void FUN_0027af00(); };
struct Entry { Small first,second; unsigned int rest[12]; };
struct CStatsManager { union { Entry entries[50]; unsigned int words[800]; }; unsigned int count; unsigned int untouched; unsigned int xp; unsigned int tail[272]; unsigned int secrets; CStatsManager* initialize();
 void FUN_00090630(); void FUN_00090720(); void FUN_000906f0(); void FUN_00090df0(); void FUN_000900a0(); void FUN_00090110(); void FUN_00090130(); void FUN_0008ffb0(); void FUN_000901a0(); void FUN_00090200(); void FUN_0008ffc0(); void FUN_00090270(); void FUN_00090310(); void FUN_000903a0(); void FUN_00090430(); void FUN_00090440(); };
// The bound member functions are CStatsManager's; a Binding is a Method<N> / Closure<N> on Function's fields
// (include/decls/data/script.h): the member-function pointer, then (Closure) the object.
typedef void (CStatsManager::*Callback)();
extern "C" void* __cdecl FUN_0008d690(int);
struct Binding : ScriptFunctionFields {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 Callback callback;
 void FUN_001d0480(const char*,int);
 void FUN_00090840(const char*,Callback);
 Binding* FUN_00090eb0(const char*,CStatsManager*,Callback);
 void FUN_00090c50(const char*,Callback);
};
template<class C,class R,class A> struct Method1: Binding { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); };
template<class C,class R,class A> struct Closure1: Method1<C,R,A> { C* owner; virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); };
template<class C,class R,class A,class B,class D> struct Closure3: Binding { C* owner; virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); };
template<class C,class R,class A,class B,class D,class E,class F,class G> struct Closure6: Binding { C* owner; virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); };
struct Registry { void FUN_001d3b70(const char*,void*); void FUN_00091450(const char*,CStatsManager*,Callback); void FUN_00091510(const char*,CStatsManager*,Callback); };
extern "C" Registry* FUN_001d4c90();
#define MAKE(NAME,RET,ARG,FUNC,AT,RT) \
 p=(Binding*)FUN_0008d690((int)sizeof(Closure1<CStatsManager,RET,ARG>)); \
 if(p) { p->FUN_001d0480(NAME,1); new(p) Method1<CStatsManager,RET,ARG>; p->callback=&CStatsManager::FUNC; p->retType=FUN_001d04d0(&AT); p->argTypes[0]=FUN_001d04d0(&RT); Closure1<CStatsManager,RET,ARG>* c=new(p) Closure1<CStatsManager,RET,ARG>; c->owner=this; } \
 r->FUN_001d3b70(NAME,p);
CStatsManager* CStatsManager::initialize() {
 for(int i=0;i<50;++i) { entries[i].first.FUN_0027af00(); entries[i].second.FUN_0027af00(); }
 count=0; for(int j=0;j<800;++j) words[j]=0;
 typedef Closure6<CStatsManager,void,const char*,const char*,int,int,int,int> Closure6_t; typedef Closure3<CStatsManager,void,char*,char*,int> Closure3_t;
 HULK_SIZE32(Closure6_t, 0x24); HULK_SIZE32(Closure3_t, 0x24); HULK_SIZE32(ScriptClosureView, 0x24);
 Registry* r=FUN_001d4c90(); Binding* p=(Binding*)FUN_0008d690((int)sizeof(Closure6_t));
 if(p) { p->FUN_00090840("sta_PrepareStat",&CStatsManager::FUN_00090630); Closure6<CStatsManager,void,const char*,const char*,int,int,int,int>* c=new(p) Closure6<CStatsManager,void,const char*,const char*,int,int,int,int>; c->owner=this; }
 r->FUN_001d3b70("sta_PrepareStat",p);
 p=(Binding*)FUN_0008d690((int)sizeof(ScriptClosureView)); if(p) p=p->FUN_00090eb0("sta_Tally",this,&CStatsManager::FUN_00090720); r->FUN_001d3b70("sta_Tally",p);
 MAKE("sta_BeginTrial",void,const char*,FUN_000906f0,(*(int*)&DAT_0048e100),(*(int*)&DAT_0048e0f0))
 MAKE("sta_EndTrial",void,const char*,FUN_00090df0,(*(int*)&DAT_0048e100),(*(int*)&DAT_0048e0f0))
 MAKE("sta_AddXP",void,int,FUN_000900a0,(*(int*)&DAT_0048e100),(*(int*)&DAT_0048e134))
 r->FUN_00091450("sta_GetXP",this,&CStatsManager::FUN_00090110);
 MAKE("sta_SetXP",void,int,FUN_00090130,(*(int*)&DAT_0048e100),(*(int*)&DAT_0048e134))
 r->FUN_00091450("sta_GetXPHighScore",this,&CStatsManager::FUN_0008ffb0);
 MAKE("sta_GetStatValue",int,const char*,FUN_000901a0,(*(int*)&DAT_0048e134),(*(int*)&DAT_0048e0f0))
 p=(Binding*)FUN_0008d690((int)sizeof(ScriptClosureView)); if(p) p=p->FUN_00090eb0("sta_SetStatValue",this,&CStatsManager::FUN_00090200); r->FUN_001d3b70("sta_SetStatValue",p);
 r->FUN_00091510("sta_IsFakeXPActive",this,&CStatsManager::FUN_0008ffc0);
 p=(Binding*)FUN_0008d690((int)sizeof(Closure3_t)); if(p) { p->FUN_00090c50("sta_AddDemoGrade",&CStatsManager::FUN_00090270); Closure3<CStatsManager,void,char*,char*,int>* c=new(p) Closure3<CStatsManager,void,char*,char*,int>; c->owner=this; } r->FUN_001d3b70("sta_AddDemoGrade",p);
 MAKE("sta_GetDemoGrade",const char*,int,FUN_00090310,(*(int*)&DAT_0048e0f0),(*(int*)&DAT_0048e134))
 MAKE("sta_GetDemoCode",const char*,int,FUN_000903a0,(*(int*)&DAT_0048e0f0),(*(int*)&DAT_0048e134))
 MAKE("sta_SetDemoSecretsFound",void,int,FUN_00090430,(*(int*)&DAT_0048e100),(*(int*)&DAT_0048e134))
 r->FUN_00091450("sta_GetDemoSecretsFound",this,&CStatsManager::FUN_00090440);
 xp=0; for(int k=0;k<272;++k) tail[k]=0; secrets=0; return this;
}