// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 26/26)
// FUN_00091630 @ 0x00091630
typedef unsigned int size_t;
inline void* operator new(size_t, void* p) { return p; }
struct CStatsManager;
typedef void (*Callback_91630)();
extern void FUN_00090630(); extern void FUN_00090720(); extern void FUN_000906f0(); extern void FUN_00090df0(); extern void FUN_000900a0(); extern void FUN_00090110(); extern void FUN_00090130(); extern void FUN_0008ffb0(); extern void FUN_000901a0(); extern void FUN_00090200(); extern void FUN_0008ffc0(); extern void FUN_00090270(); extern void FUN_00090310(); extern void FUN_000903a0(); extern void FUN_00090430(); extern void FUN_00090440();
extern int DAT_0048e100, DAT_0048e0f0, DAT_0048e134;
extern unsigned char __cdecl FUN_001d04d0(void*);
extern void* __cdecl FUN_0008d690(int);
struct Binding {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 char pad[12]; unsigned char resultType; char pad2[7]; unsigned char argumentType; char pad3[3]; Callback_91630 callback;
 void FUN_001d0480(const char*,int);
 void FUN_00090840(const char*,Callback_91630);
 Binding* FUN_00090eb0(const char*,CStatsManager*,Callback_91630);
 void FUN_00090c50(const char*,Callback_91630);
};
template<class C,class R,class A> struct Method1: Binding { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); };
template<class C,class R,class A> struct Closure1: Method1<C,R,A> { C* owner; virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); };
template<class C,class R,class A,class B,class D> struct Closure3: Binding { C* owner; virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); };
template<class C,class R,class A,class B,class D,class E,class F,class G> struct Closure6: Binding { C* owner; virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); };
struct Registry_91630 { void FUN_001d3b70(const char*,void*); void FUN_00091450(const char*,CStatsManager*,Callback_91630); void FUN_00091510(const char*,CStatsManager*,Callback_91630); };
extern Registry_91630* FUN_001d4c90();
struct Small_91630 { unsigned int data[2]; void FUN_0027af00(); };
struct Entry_91630 { Small_91630 first,second; unsigned int rest[12]; };
struct CStatsManager { union { Entry_91630 entries[50]; unsigned int words[800]; }; unsigned int count; unsigned int untouched; unsigned int xp; unsigned int tail[272]; unsigned int secrets; CStatsManager* initialize(); };
#define MAKE(NAME,RET,ARG,FUNC,AT,RT) \
 p=(Binding*)FUN_0008d690(36); \
 if(p) { p->FUN_001d0480(NAME,1); new(p) Method1<CStatsManager,RET,ARG>; p->callback=FUNC; p->argumentType=FUN_001d04d0(&AT); p->resultType=FUN_001d04d0(&RT); Closure1<CStatsManager,RET,ARG>* c=new(p) Closure1<CStatsManager,RET,ARG>; c->owner=this; } \
 r->FUN_001d3b70(NAME,p);
CStatsManager* CStatsManager::initialize() {
 for(int i=0;i<50;++i) { entries[i].first.FUN_0027af00(); entries[i].second.FUN_0027af00(); }
 count=0; for(int j=0;j<800;++j) words[j]=0;
 Registry_91630* r=FUN_001d4c90(); Binding* p=(Binding*)FUN_0008d690(36);
 if(p) { p->FUN_00090840("sta_PrepareStat",FUN_00090630); Closure6<CStatsManager,void,const char*,const char*,int,int,int,int>* c=new(p) Closure6<CStatsManager,void,const char*,const char*,int,int,int,int>; c->owner=this; }
 r->FUN_001d3b70("sta_PrepareStat",p);
 p=(Binding*)FUN_0008d690(36); if(p) p=p->FUN_00090eb0("sta_Tally",this,FUN_00090720); r->FUN_001d3b70("sta_Tally",p);
 MAKE("sta_BeginTrial",void,const char*,FUN_000906f0,DAT_0048e100,DAT_0048e0f0)
 MAKE("sta_EndTrial",void,const char*,FUN_00090df0,DAT_0048e100,DAT_0048e0f0)
 MAKE("sta_AddXP",void,int,FUN_000900a0,DAT_0048e100,DAT_0048e134)
 r->FUN_00091450("sta_GetXP",this,FUN_00090110);
 MAKE("sta_SetXP",void,int,FUN_00090130,DAT_0048e100,DAT_0048e134)
 r->FUN_00091450("sta_GetXPHighScore",this,FUN_0008ffb0);
 MAKE("sta_GetStatValue",int,const char*,FUN_000901a0,DAT_0048e134,DAT_0048e0f0)
 p=(Binding*)FUN_0008d690(36); if(p) p=p->FUN_00090eb0("sta_SetStatValue",this,FUN_00090200); r->FUN_001d3b70("sta_SetStatValue",p);
 r->FUN_00091510("sta_IsFakeXPActive",this,FUN_0008ffc0);
 p=(Binding*)FUN_0008d690(36); if(p) { p->FUN_00090c50("sta_AddDemoGrade",FUN_00090270); Closure3<CStatsManager,void,char*,char*,int>* c=new(p) Closure3<CStatsManager,void,char*,char*,int>; c->owner=this; } r->FUN_001d3b70("sta_AddDemoGrade",p);
 MAKE("sta_GetDemoGrade",const char*,int,FUN_00090310,DAT_0048e0f0,DAT_0048e134)
 MAKE("sta_GetDemoCode",const char*,int,FUN_000903a0,DAT_0048e0f0,DAT_0048e134)
 MAKE("sta_SetDemoSecretsFound",void,int,FUN_00090430,DAT_0048e100,DAT_0048e134)
 r->FUN_00091450("sta_GetDemoSecretsFound",this,FUN_00090440);
 xp=0; for(int k=0;k<272;++k) tail[k]=0; secrets=0; return this;
}