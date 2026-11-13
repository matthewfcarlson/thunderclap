// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001be0e0..0x001c1200 (kind game, layer game, confidence high), dominant class CSubtitleManager
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/records.h"
#include "decls/data/script.h"
#define TREE_TU_BEGIN namespace fn_f74613ff {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f74613ff {} using namespace fn_f74613ff;
#include "game/global.h"
#include "decls/managers.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(hulk_uintptr, void* p) { return p; }
namespace fn_f74613ff {
extern "C" void* __cdecl FUN_0008d690(unsigned);
extern "C" void* __cdecl FUN_0008d6d0(unsigned);
void* __cdecl FUN_00263ea0(unsigned);
extern "C" int __cdecl FUN_00266da0(int);
struct CSubtitleManager;
typedef void (__cdecl *Callback_1c0cd0)();
void FUN_001bf860(void*, char); /* (unb4) as defined; address taken only */
void FUN_001bdfb0(void*, int); /* (unb4) as defined; address taken only */
void FUN_001bdf20(void*, int, float, float, float); /* (unb4) as defined; address taken only */
void FUN_001c0360(void*, int, int); /* (unb4) as defined; address taken only */
void FUN_001c0ca0(void*, int, int); /* (unb4) as defined; address taken only */
void FUN_00088ec0(void*, char); /* (unb4) as defined; address taken only */
char FUN_00088ee0(void*); /* (unb4) as defined; address taken only */
extern "C" void FUN_001bdfc0();
void FUN_001bdfd0(int, int, int); /* (unb4) as defined; address taken only */
void FUN_001bddc0(void*, char); /* (unb4) as defined; address taken only */
void FUN_001be9f0(void*, void*, void*, float); /* (unb4) as defined; address taken only */
struct Binding_1c0cd0 : ScriptFunctionFields { virtual void invoke(); Callback_1c0cd0 method; CSubtitleManager* owner; void FUN_001d0480(const char*,int); Binding_1c0cd0* FUN_001bfd70(const char*,CSubtitleManager*,Callback_1c0cd0); Binding_1c0cd0* FUN_001bffb0(const char*,CSubtitleManager*,Callback_1c0cd0); void FUN_001bf4c0(const char*,Callback_1c0cd0); void FUN_001bf710(const char*,Callback_1c0cd0); void FUN_001bf7c0(const char*,Callback_1c0cd0); };
template<class C,class R,class A> struct Method1: Binding_1c0cd0 { virtual void invoke(); };
template<class C,class R,class A> struct Closure1: Method1<C,R,A> { virtual void invoke(); };
template<class C,class R,class A,class B,class D,class E> struct Closure4: Binding_1c0cd0 { virtual void invoke(); };
template<class C,class R,class A,class B,class D> struct Closure3: Binding_1c0cd0 { virtual void invoke(); };
struct Registry_1c0cd0 { void FUN_001d3b70(const char*,void*); void FUN_001c08c0(const char*,CSubtitleManager*,Callback_1c0cd0); };
extern "C" Registry_1c0cd0* __cdecl FUN_001d4c90();
struct CSubtitleOverlay_1c0cd0 { CSubtitleOverlay_1c0cd0* FUN_000f6ef0(); CSubtitleOverlay_1c0cd0* FUN_001be170(); };
struct Stream { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void configure(unsigned,int); };
struct Shader_1c0cd0 { virtual void start(); char pad[12]; Stream* stream; Shader_1c0cd0* FUN_0028edb0(); };
struct Event_1c0cd0 { float begin,end; unsigned data[2]; };
struct Entry_1c0cd0 { unsigned data[4]; float time; unsigned tail; };
struct sSubtitleManagerCallback { virtual void invoke_001c06f0(int, int); CSubtitleManager* owner; };
// (x64t9-mgr) include/decls/managers.h's HulkSubtitleManager: h is CGame (0x001c0a40 stores it), then the last word
struct CSubtitleManager { float time; unsigned count; Event_1c0cd0* events; unsigned char enabled,flag; char pad[2]; unsigned a,b,c,mode,d; unsigned char ready; char pad2[3]; void** buffers; CSubtitleOverlay_1c0cd0* table; sSubtitleManagerCallback* callback; CSubtitleOverlay_1c0cd0* resource1; CSubtitleOverlay_1c0cd0* resource2; Entry_1c0cd0* entries; unsigned e,f,g; void* h; unsigned i; unsigned char j,k; char pad3[2]; Shader_1c0cd0* loader; unsigned last; CSubtitleManager* FUN_001c0cd0(); };
HULK_MGR_SAME(CSubtitleManager, HulkSubtitleManager);


// 0x001c0cd0 FUN_001c0cd0 (1241 B): equivalent/0x001c0cd0.cpp
// sym: ?FUN_001c0cd0@CSubtitleManager@fn_f74613ff@@QAEPAU12@XZ @7e6a47c269a3 @w0f5384d9a3f6
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 40/40)
// FUN_001c0cd0 @ 0x001c0cd0
CSubtitleManager* CSubtitleManager::FUN_001c0cd0() {
HULK_SIZE32(Binding_1c0cd0, 0x24);
time=-1.0f; count=0; events=0; enabled=0; flag=0; a=b=c=0; mode=1; d=0; ready=0; buffers=0; table=0; callback=0; resource1=resource2=0; entries=0; i=0; h=0; e=f=g=0; j=k=0; loader=0;
int old=FUN_00266da0(14); Registry_1c0cd0* reg=FUN_001d4c90(); Binding_1c0cd0* p=(Binding_1c0cd0*)FUN_0008d690((int)sizeof(Binding_1c0cd0)); if(p) p=p->FUN_001bfd70("stm_InitEvents",this,(void (*)())FUN_001c0360); reg->FUN_001d3b70("stm_InitEvents",p);
p=(Binding_1c0cd0*)FUN_0008d690((int)sizeof(Binding_1c0cd0)); if(p) {p->FUN_001d0480("stm_Clear",1); new(p) Method1<CSubtitleManager,void,bool>; p->method=(void (*)())FUN_001bf860; p->retType=FUN_001d04d0(((int*)&DAT_0048e100)); p->argTypes[0]=FUN_001d04d0(((int*)&DAT_0048e0e4)); new(p) Closure1<CSubtitleManager,void,bool>; p->owner=this;} reg->FUN_001d3b70("stm_Clear",p);
p=(Binding_1c0cd0*)FUN_0008d690((int)sizeof(Binding_1c0cd0)); if(p) {p->FUN_001d0480("stm_SetMode",1); new(p) Method1<CSubtitleManager,void,int>; p->method=(void (*)())FUN_001bdfb0; p->retType=FUN_001d04d0(((int*)&DAT_0048e100)); p->argTypes[0]=FUN_001d04d0(((int*)&DAT_0048e134)); new(p) Closure1<CSubtitleManager,void,int>; p->owner=this;} reg->FUN_001d3b70("stm_SetMode",p);
p=(Binding_1c0cd0*)FUN_0008d690((int)sizeof(Binding_1c0cd0)); if(p) {p->FUN_001bf4c0("stm_SetEvent",(void (*)())FUN_001bdf20); new(p) Closure4<CSubtitleManager,void,int,float,const char*,float>; p->owner=this;} reg->FUN_001d3b70("stm_SetEvent",p);
p=(Binding_1c0cd0*)FUN_0008d690((int)sizeof(Binding_1c0cd0)); if(p) p=p->FUN_001bffb0("stm_TriggerEvent",this,(void (*)())FUN_001c0ca0); reg->FUN_001d3b70("stm_TriggerEvent",p);
p=(Binding_1c0cd0*)FUN_0008d690((int)sizeof(Binding_1c0cd0)); if(p) {p->FUN_001d0480("stm_SetSubtitlesOn",1); new(p) Method1<CSubtitleManager,void,bool>; p->method=(void (*)())FUN_00088ec0; p->retType=FUN_001d04d0(((int*)&DAT_0048e100)); p->argTypes[0]=FUN_001d04d0(((int*)&DAT_0048e0e4)); new(p) Closure1<CSubtitleManager,void,bool>; p->owner=this;} reg->FUN_001d3b70("stm_SetSubtitlesOn",p);
reg->FUN_001c08c0("stm_IsSubtitlesOn",this,(void (*)())FUN_00088ee0);
p=(Binding_1c0cd0*)FUN_0008d690((int)sizeof(Binding_1c0cd0)); if(p) {p->FUN_001d0480("stm_SetScale",1); new(p) Method1<CSubtitleManager,void,float>; p->method=FUN_001bdfc0; p->retType=FUN_001d04d0(((int*)&DAT_0048e100)); p->argTypes[0]=FUN_001d04d0(((int*)&DAT_0048e128)); new(p) Closure1<CSubtitleManager,void,float>; p->owner=this;} reg->FUN_001d3b70("stm_SetScale",p);
p=(Binding_1c0cd0*)FUN_0008d690((int)sizeof(Binding_1c0cd0)); if(p) {p->FUN_001bf710("stm_SetPosition",(void (*)())FUN_001bdfd0); new(p) Closure3<CSubtitleManager,void,float,float,float>; p->owner=this;} reg->FUN_001d3b70("stm_SetPosition",p);
p=(Binding_1c0cd0*)FUN_0008d690((int)sizeof(Binding_1c0cd0)); if(p) {p->FUN_001d0480("stm_SetDisplayTime",1); new(p) Method1<CSubtitleManager,void,bool>; p->method=(void (*)())FUN_001bddc0; p->retType=FUN_001d04d0(((int*)&DAT_0048e100)); p->argTypes[0]=FUN_001d04d0(((int*)&DAT_0048e0e4)); new(p) Closure1<CSubtitleManager,void,bool>; p->owner=this;} reg->FUN_001d3b70("stm_SetDisplayTime",p);
p=(Binding_1c0cd0*)FUN_0008d690((int)sizeof(Binding_1c0cd0)); if(p) {p->FUN_001bf7c0("stm_MapSoundFileToStringKey",(void (*)())FUN_001be9f0); new(p) Closure3<CSubtitleManager,void,const char*,const char*,float>; p->owner=this;} reg->FUN_001d3b70("stm_MapSoundFileToStringKey",p);
buffers=(void**)FUN_0008d6d0(40); for(int n=0;n<10;++n){void* buf=FUN_0008d6d0(256); buffers[n]=buf;}
Event_1c0cd0* ev=(Event_1c0cd0*)FUN_0008d6d0(1120); if(ev) for(int n=0;n<70;++n){ev[n].begin=-1.0f;ev[n].end=-1.0f;} events=ev;
CSubtitleOverlay_1c0cd0* r=(CSubtitleOverlay_1c0cd0*)FUN_0008d690(288); resource1=r?r->FUN_000f6ef0():0; r=(CSubtitleOverlay_1c0cd0*)FUN_0008d690(288); resource2=r?r->FUN_000f6ef0():0;
Entry_1c0cd0* en=(Entry_1c0cd0*)FUN_0008d6d0(27600); if(en) for(int n=0;n<1150;++n) en[n].time=-1.0f; entries=en;
r=(CSubtitleOverlay_1c0cd0*)FUN_0008d690(308); table=r?r->FUN_001be170():0;
sSubtitleManagerCallback* cb=(sSubtitleManagerCallback*)FUN_0008d690(8); if(cb){new(cb) sSubtitleManagerCallback; cb->owner=this;} callback=cb;
Shader_1c0cd0* l=(Shader_1c0cd0*)FUN_00263ea0(32); loader=l?l->FUN_0028edb0():0; loader->start(); loader->stream->configure(0x444d4c42,1); FUN_00266da0(old); return this;
}

} // namespace fn_f74613ff
