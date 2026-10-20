// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 40/40)
// FUN_001c0cd0 @ 0x001c0cd0
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
inline void* __cdecl operator new(unsigned, void* p) { return p; }
void* __cdecl FUN_0008d690(unsigned); void* __cdecl FUN_0008d6d0(unsigned); void* __cdecl FUN_00263ea0(unsigned); int __cdecl FUN_00266da0(int);
struct CSubtitleManager; typedef void (__cdecl *Callback_1c0cd0)();
void FUN_001bf860(); void FUN_001bdfb0(); void FUN_001bdf20(); void FUN_001c0360(); void FUN_001c0ca0(); void FUN_00088ec0(); void FUN_00088ee0(); void FUN_001bdfc0(); void FUN_001bdfd0(); void FUN_001bddc0(); void FUN_001be9f0();
struct Binding_1c0cd0 { virtual void invoke(); char pad[12]; unsigned char resultType; char pad2[7]; unsigned char ownerType; char pad3[3]; Callback_1c0cd0 method; CSubtitleManager* owner; void FUN_001d0480(const char*,int); Binding_1c0cd0* FUN_001bfd70(const char*,CSubtitleManager*,Callback_1c0cd0); Binding_1c0cd0* FUN_001bffb0(const char*,CSubtitleManager*,Callback_1c0cd0); void FUN_001bf4c0(const char*,Callback_1c0cd0); void FUN_001bf710(const char*,Callback_1c0cd0); void FUN_001bf7c0(const char*,Callback_1c0cd0); };
template<class C,class R,class A> struct Method1: Binding_1c0cd0 { virtual void invoke(); };
template<class C,class R,class A> struct Closure1: Method1<C,R,A> { virtual void invoke(); };
template<class C,class R,class A,class B,class D,class E> struct Closure4: Binding_1c0cd0 { virtual void invoke(); };
template<class C,class R,class A,class B,class D> struct Closure3: Binding_1c0cd0 { virtual void invoke(); };
struct Registry_1c0cd0 { void FUN_001d3b70(const char*,void*); void FUN_001c08c0(const char*,CSubtitleManager*,Callback_1c0cd0); }; Registry_1c0cd0* __cdecl FUN_001d4c90();
struct Resource_1c0cd0 { Resource_1c0cd0* FUN_000f6ef0(); Resource_1c0cd0* FUN_001be170(); };
struct Stream { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void configure(unsigned,int); };
struct Loader_1c0cd0 { virtual void start(); char pad[12]; Stream* stream; Loader_1c0cd0* FUN_0028edb0(); };
struct Event_1c0cd0 { float begin,end; unsigned data[2]; }; struct Entry_1c0cd0 { unsigned data[4]; float time; unsigned tail; };
struct sSubtitleManagerCallback { virtual void invoke(); CSubtitleManager* owner; };
struct CSubtitleManager { float time; unsigned count; Event_1c0cd0* events; unsigned char enabled,flag; char pad[2]; unsigned a,b,c,mode,d; unsigned char ready; char pad2[3]; void** buffers; Resource_1c0cd0* table; sSubtitleManagerCallback* callback; Resource_1c0cd0* resource1; Resource_1c0cd0* resource2; Entry_1c0cd0* entries; unsigned e,f,g,h,i; unsigned char j,k; char pad3[2]; Loader_1c0cd0* loader; CSubtitleManager* FUN_001c0cd0(); };
CSubtitleManager* CSubtitleManager::FUN_001c0cd0() {
time=-1.0f; count=0; events=0; enabled=0; flag=0; a=b=c=0; mode=1; d=0; ready=0; buffers=0; table=0; callback=0; resource1=resource2=0; entries=0; e=f=g=h=i=0; j=k=0; loader=0;
int old=FUN_00266da0(14); Registry_1c0cd0* reg=FUN_001d4c90(); Binding_1c0cd0* p=(Binding_1c0cd0*)FUN_0008d690(36); if(p) p=p->FUN_001bfd70("stm_InitEvents",this,FUN_001c0360); reg->FUN_001d3b70("stm_InitEvents",p);
p=(Binding_1c0cd0*)FUN_0008d690(36); if(p) {p->FUN_001d0480("stm_Clear",1); new(p) Method1<CSubtitleManager,void,bool>; p->method=FUN_001bf860; p->ownerType=FUN_001d04d0(((int*)&DAT_0048e100)); p->resultType=FUN_001d04d0(((int*)&DAT_0048e0e4)); new(p) Closure1<CSubtitleManager,void,bool>; p->owner=this;} reg->FUN_001d3b70("stm_Clear",p);
p=(Binding_1c0cd0*)FUN_0008d690(36); if(p) {p->FUN_001d0480("stm_SetMode",1); new(p) Method1<CSubtitleManager,void,int>; p->method=FUN_001bdfb0; p->ownerType=FUN_001d04d0(((int*)&DAT_0048e100)); p->resultType=FUN_001d04d0(((int*)&DAT_0048e134)); new(p) Closure1<CSubtitleManager,void,int>; p->owner=this;} reg->FUN_001d3b70("stm_SetMode",p);
p=(Binding_1c0cd0*)FUN_0008d690(36); if(p) {p->FUN_001bf4c0("stm_SetEvent",FUN_001bdf20); new(p) Closure4<CSubtitleManager,void,int,float,const char*,float>; p->owner=this;} reg->FUN_001d3b70("stm_SetEvent",p);
p=(Binding_1c0cd0*)FUN_0008d690(36); if(p) p=p->FUN_001bffb0("stm_TriggerEvent",this,FUN_001c0ca0); reg->FUN_001d3b70("stm_TriggerEvent",p);
p=(Binding_1c0cd0*)FUN_0008d690(36); if(p) {p->FUN_001d0480("stm_SetSubtitlesOn",1); new(p) Method1<CSubtitleManager,void,bool>; p->method=FUN_00088ec0; p->ownerType=FUN_001d04d0(((int*)&DAT_0048e100)); p->resultType=FUN_001d04d0(((int*)&DAT_0048e0e4)); new(p) Closure1<CSubtitleManager,void,bool>; p->owner=this;} reg->FUN_001d3b70("stm_SetSubtitlesOn",p);
reg->FUN_001c08c0("stm_IsSubtitlesOn",this,FUN_00088ee0);
p=(Binding_1c0cd0*)FUN_0008d690(36); if(p) {p->FUN_001d0480("stm_SetScale",1); new(p) Method1<CSubtitleManager,void,float>; p->method=FUN_001bdfc0; p->ownerType=FUN_001d04d0(((int*)&DAT_0048e100)); p->resultType=FUN_001d04d0(((int*)&DAT_0048e128)); new(p) Closure1<CSubtitleManager,void,float>; p->owner=this;} reg->FUN_001d3b70("stm_SetScale",p);
p=(Binding_1c0cd0*)FUN_0008d690(36); if(p) {p->FUN_001bf710("stm_SetPosition",FUN_001bdfd0); new(p) Closure3<CSubtitleManager,void,float,float,float>; p->owner=this;} reg->FUN_001d3b70("stm_SetPosition",p);
p=(Binding_1c0cd0*)FUN_0008d690(36); if(p) {p->FUN_001d0480("stm_SetDisplayTime",1); new(p) Method1<CSubtitleManager,void,bool>; p->method=FUN_001bddc0; p->ownerType=FUN_001d04d0(((int*)&DAT_0048e100)); p->resultType=FUN_001d04d0(((int*)&DAT_0048e0e4)); new(p) Closure1<CSubtitleManager,void,bool>; p->owner=this;} reg->FUN_001d3b70("stm_SetDisplayTime",p);
p=(Binding_1c0cd0*)FUN_0008d690(36); if(p) {p->FUN_001bf7c0("stm_MapSoundFileToStringKey",FUN_001be9f0); new(p) Closure3<CSubtitleManager,void,const char*,const char*,float>; p->owner=this;} reg->FUN_001d3b70("stm_MapSoundFileToStringKey",p);
buffers=(void**)FUN_0008d6d0(40); for(int n=0;n<10;++n){void* buf=FUN_0008d6d0(256); buffers[n]=buf;}
Event_1c0cd0* ev=(Event_1c0cd0*)FUN_0008d6d0(1120); if(ev) for(int n=0;n<70;++n){ev[n].begin=-1.0f;ev[n].end=-1.0f;} events=ev;
Resource_1c0cd0* r=(Resource_1c0cd0*)FUN_0008d690(288); resource1=r?r->FUN_000f6ef0():0; r=(Resource_1c0cd0*)FUN_0008d690(288); resource2=r?r->FUN_000f6ef0():0;
Entry_1c0cd0* en=(Entry_1c0cd0*)FUN_0008d6d0(27600); if(en) for(int n=0;n<1150;++n) en[n].time=-1.0f; entries=en;
r=(Resource_1c0cd0*)FUN_0008d690(308); table=r?r->FUN_001be170():0;
sSubtitleManagerCallback* cb=(sSubtitleManagerCallback*)FUN_0008d690(8); if(cb){new(cb) sSubtitleManagerCallback; cb->owner=this;} callback=cb;
Loader_1c0cd0* l=(Loader_1c0cd0*)FUN_00263ea0(32); loader=l?l->FUN_0028edb0():0; loader->start(); loader->stream->configure(0x444d4c42,1); FUN_00266da0(old); return this;
}