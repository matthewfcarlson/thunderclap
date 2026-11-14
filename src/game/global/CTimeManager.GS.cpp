// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00085d90..0x00088e60 (kind game, layer game, confidence high), dominant class CTimeManager
#include "tree_prelude.h"
#include "decls/address.h"
#include "decls/data/engine/content.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_ffdc64b2 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_ffdc64b2 {} using namespace fn_ffdc64b2;
#include "game/global.h"
#include "decls/managers.h"

// ---- declarations shared by the functions below
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl sprintf(char *, const char *, ...);
#endif
namespace fn_ffdc64b2 {
typedef unsigned __int64 U64_86450;
extern "C" U64_86450 __cdecl FUN_00267f40();
struct Debug_86450 { void FUN_0023f720(int*,const char*); bool FUN_0023f760(const char*,int,int); bool FUN_0023f770(const char*,int); int FUN_0023f790(const char*,int,int,int,int); void FUN_0023f740(); };
struct Timer { U64_86450 limit,last,total,scaledTotal,elapsed,step,scaledStep,rate; char pad[8]; unsigned char paused; void FUN_00086450(); };
struct Screen_879c0 { void FUN_00086da0(); };
} // namespace fn_ffdc64b2
struct World { char pad0[0x54]; Screen_879c0* screen; char pad1[0x45]; unsigned char active; };
namespace fn_ffdc64b2 {
extern "C" unsigned int __cdecl FUN_00267f80();
extern int __cdecl _sprintf(char*, const char*, ...);
extern void __cdecl FUN_001bc0c0(const char*,int,int);


// 0x00086210 FUN_00086210 (45 B): matches/0x00086210.cpp
// sym: ?FUN_00086210@fn_ffdc64b2@@YAXPBD@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00086210 @ 0x00086210
void __cdecl FUN_00086210(const char *state)
{
    char text[64];
    sprintf(text, "Entering %s state\n", state);
}


// 0x00086450 FUN_00086450 (338 B): matches/0x00086450.cpp
// sym: ?FUN_00086450@Timer@fn_ffdc64b2@@QAEXXZ
// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 12/12)
// FUN_00086450 @ 0x00086450
void Timer::FUN_00086450() {
 char gs_unused[16]; /* dead stack buffer: MSVC /GS protects only functions with a char array */
 step=0; scaledStep=0;
 U64_86450 now=FUN_00267f40(); elapsed=now-last; last=now;
 (*(Debug_86450**)&DAT_004dd6e8)->FUN_0023f720(&DAT_0049c104,"VCR");
 if (!paused && (!(*(Debug_86450**)&DAT_004dd6e8)->FUN_0023f760("Paused",32,0) || (*(Debug_86450**)&DAT_004dd6e8)->FUN_0023f770("Step when paused",115))) {
 step=elapsed<limit?elapsed:limit;
 scaledStep=(rate*step)>>16;
 int dilation=(*(Debug_86450**)&DAT_004dd6e8)->FUN_0023f790("Debug time dilation",93,91,17,16);
 scaledStep=((U64_86450)(__int64)dilation*scaledStep)>>4;
 } else { step=0; scaledStep=0; }
 total+=step; scaledTotal+=scaledStep;
 (*(Debug_86450**)&DAT_004dd6e8)->FUN_0023f740();
}

} // namespace fn_ffdc64b2

// 0x000873a0 FUN_000873a0 (618 B): equivalent/0x000873a0.cpp [wrapped: macros]
// sym: ?update@Main@fn_000873a0@@QAEXXZ @100ea426cfd9 @w9fc6b0911eaa
namespace fn_000873a0 {
// STATUS: equivalent (tools/equiv.py level 3: 3063 inputs, branch coverage 21/21)
// FUN_000873a0 @ 0x000873a0
// cl-flags: /GS
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


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl sprintf(char *,const char *,...);
#endif

struct Gfx {
#define V(n) virtual void v##n();
V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29)
V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39)
V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49)
V(50) V(51) V(52) V(53) V(54) V(55) V(56) V(57) V(58) V(59)
V(60) V(61) V(62) V(63) V(64) V(65) V(66) V(67) V(68) V(69)
V(70) V(71) V(72) V(73) V(74) V(75) V(76) V(77) V(78) V(79)
V(80) V(81) V(82) V(83) V(84) V(85) V(86) V(87) V(88) V(89) V(90) V(91)
#undef V
};
struct State { unsigned current, previous; };
struct GameData { char pad0[16]; unsigned a,b,c,d; char pad1[24]; unsigned mode, extra; char pad2[8]; unsigned char active; };
struct Subsystem { void FUN_0008db60(int);  void FUN_00093c40(const char*); void FUN_00089810(const char*);  void FUN_00089300(const char*); void FUN_001ec3d0(); void FUN_000afe80(); void FUN_001eb4e0(); void FUN_001eb4d0();  };
struct Main {
unsigned unknown; State *state; GameData *data; char pad[12]; Subsystem *s18,*s1c,*s20; char pad2[12]; Subsystem *s30,*s34,*s38,*s3c;
void FUN_000865d0(); void FUN_00086630(); void FUN_00086790(); void FUN_000872a0(); void update();
};
void Main::update() {
char text[9][64];
while(state->current != state->previous) {
state->previous = state->current;
DAT_0052c2a8->v91();
switch(state->current) {
case 0: sprintf(text[0],"Entering %s state\n","GS_NONE"); break;
case 1:
if((*(unsigned char*)&DAT_004dd8d0)) {
if(((char*)&DAT_004dd890)[0]) {
FUN_000865d0();
void *item=((void *)((owners::NameTable_b4cf0 *)s20)->FUN_000b4cf0(((char*)&DAT_004dd890)));
if(!item) { return; }
s3c->FUN_00093c40(((char*)&DAT_004dd890));
s38->FUN_00089810(((char*)&DAT_004dd890));
((owners::LevelName_895e0 *)s38)->FUN_000895e0((const char *)item);
s38->FUN_00089300("oneshot");
} else { FUN_000865d0(); s38->FUN_00089810("C00M01"); s38->FUN_00089300("story"); }
} else { FUN_000865d0(); sprintf(text[1],"Entering %s state\n","GS_FRONTEND"); }
break;
case 2: sprintf(text[2],"Entering %s state\n","GS_PREGAME"); FUN_00086630(); break;
case 3: sprintf(text[3],"Entering %s state\n","GS_PRESSSTART"); FUN_00086790(); break;
case 4: sprintf(text[4],"Entering %s state\n","GS_GAME"); s1c->FUN_0008db60(0); (*(unsigned char*)&DAT_004dd6f0)=0; data->active=0; data->mode=0x10000; data->extra=0; data->a=0; data->b=0; data->c=0; data->d=0; s30->FUN_001ec3d0(); break;
case 5: sprintf(text[5],"Entering %s state\n","GS_POSTGAME"); FUN_000872a0(); break;
case 6: sprintf(text[6],"Entering %s state\n","GS_PAUSE"); s18->FUN_000afe80(); s30->FUN_001eb4e0(); break;
case 7: sprintf(text[7],"Entering %s state\n","GS_FMV"); (*(unsigned char*)&DAT_004dd6f0)=1; s30->FUN_001eb4d0(); ((owners::Object_1b83c0 *)s34)->FUN_001b83c0(); break;
case 8: sprintf(text[8],"Entering %s state\n","GS_QUIT"); break;
}
}
}
} // namespace fn_000873a0
#undef V
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_ffdc64b2 {

// 0x000879c0 FUN_000879c0 (194 B): matches/0x000879c0.cpp
// sym: ?FUN_000879c0@fn_ffdc64b2@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 99 inputs, branch coverage 12/12)
// FUN_000879c0 @ 0x000879c0
// FUN_000879c0 @ 0x000879c0
void __cdecl FUN_000879c0() {
 char buffer[128];
 unsigned int start = FUN_00267f80();
 while (start + 3000u > FUN_00267f80()) {
  unsigned int before = FUN_00267f80();
  World* state = DAT_004dd700;
  if (state && state->active && state->screen) state->screen->FUN_00086da0();
  else { thunk_FUN_00270a50(); FUN_002656a0(); }
  _sprintf(buffer, "copyright-%s", DAT_004dd8d4);
  FUN_001bc0c0(buffer,2,0);
  unsigned int elapsed = FUN_00267f80() - before;
  if (elapsed > 250u) start += elapsed - 250u;
 }
}

} // namespace fn_ffdc64b2

// 0x00088020 FUN_00088020 (1281 B): equivalent/0x00088020.cpp [wrapped: conflict: DAT_004dd700; _sprintf]
// sym: ?FUN_00088020@Base_88020@fn_00088020@@QAEXXZ @54a5748c9730 @w982200fa5274
namespace fn_00088020 {
// STATUS: equivalent (tools/equiv.py level 3: 101 inputs, branch coverage 63/66, incomplete)
// FUN_00088020 @ 0x00088020
// checked with equiv.py --steps 3000 --time-budget 900 (at the defaults most inputs hit the time budget)
// cl-flags: /GS
// FUN_00088020 @ 0x00088020

extern "C" void* __cdecl FUN_0008d690(int); extern "C" int __cdecl _sprintf(char*,const char*,...); extern "C++" void __cdecl FUN_001bc0c0(char*,int,int); extern "C" void __cdecl FUN_000bc7c0(char*); extern "C" void __cdecl thunk_FUN_00271560(void**,const char*,int,int); extern "C" int __stdcall FUN_00209a8e(const char*); extern "C" void __cdecl FUN_001bb0b0(const char*); extern "C++" void __cdecl FUN_002381a0(int,int); extern "C++" void __cdecl thunk_FUN_00270a50(); extern "C++" void __cdecl FUN_002656a0(); extern "C" unsigned char __cdecl FUN_0008db80(); extern "C" void __cdecl FUN_0008db90();  extern "C" void __fastcall thunk_FUN_000b10d0(void*);
struct Obj_88020 { virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void FUN_slot10(); void FUN_0008e880(); void FUN_000af380(); void FUN_000afdf0(); void FUN_00090d70(); void FUN_001ee820(); void FUN_000d6a20(); void FUN_001b8690(); void FUN_0008db00(); void FUN_00086da0(); unsigned char FUN_00264c70(); void FUN_0023f690(const char*); void FUN_0008bf80(void*,void*); void FUN_001ebaf0(int); void FUN_001c0a40(void*); void FUN_000c4ef0(void*,void*,void*,void*,void*,void*,void*); int FUN_000bb670(); void FUN_000d3ef0(void*,void*); void FUN_002062d0(void*); void FUN_00088670(void*,void*); void FUN_001b7260(void*,void*,void*,void*); };
struct Base_88020 { char pad0[4]; void* f04; void* f08; void* f0c; void* f10; void* f14; void* f18; Obj_88020* f1c; void* f20; Obj_88020* f24; Obj_88020* f28; Obj_88020* f2c; Obj_88020* f30; Obj_88020* f34; Obj_88020* f38; Obj_88020* f3c; void* f40; Obj_88020* f44; Obj_88020* f48; Obj_88020* f4c; void FUN_00088020(); };
struct C0_88020 { Obj_88020* FUN_0008d850(); }; struct C1_88020 { Obj_88020* FUN_0023f670(); }; struct C2_88020 { Obj_88020* FUN_000aef10(); }; struct C3_88020 { Obj_88020* FUN_000af310(void*); }; struct C4 { Obj_88020* FUN_000b0500(void*); }; struct C5 { Obj_88020* FUN_00091630(); }; struct C6 { Obj_88020* FUN_0010b2c0(); }; struct C7 { Obj_88020* FUN_00094fb0(); }; struct C8 { Obj_88020* FUN_00089bf0(); }; struct C9 { Obj_88020* FUN_001eb220(void*,void*,int); }; struct C10_88020 { Obj_88020* FUN_000d6970(); }; struct C11 { Obj_88020* FUN_001c0cd0(); }; struct C12 { Obj_88020* FUN_000c0e40(); }; struct C13 { Obj_88020* FUN_001bb990(); }; struct C14_88020 { Obj_88020* FUN_00208210(); }; struct C15 { Obj_88020* FUN_00087e30(); }; struct C16 { Obj_88020* FUN_00088600(); }; struct C17 { Obj_88020* FUN_001b84f0(); };
   
#define DAT_004dd700 (*(Obj_88020* *)&::DAT_004dd700)

void Base_88020::FUN_00088020(){ void* p; p=FUN_0008d690((int)sizeof(HulkPlatformManager)); f1c=p?((C0_88020*)p)->FUN_0008d850():0; f1c->FUN_0008e880(); if(!DAT_004dd8d4[0]) FUN_000bc7c0(DAT_004dd8d4); char copyrightText[40],soundText[40]; _sprintf(copyrightText,"copyright-%s",DAT_004dd8d4); FUN_001bc0c0(copyrightText,2,0); _sprintf(soundText,"sound_%s.rcf",DAT_004dd8d4); if(DAT_004dd8d4[0]=='e' && DAT_004dd8d4[1]=='s' && DAT_004dd8d4[2]==0){ const char* uk="sound_uk.rcf"; for(int i=0;i<13;i++) soundText[i]=uk[i]; } void* tmp=0; thunk_FUN_00271560(&tmp,soundText,0,18); if(tmp)((Obj_88020*)tmp)->FUN_slot10(); p=FUN_0008d690((int)sizeof(Hulk_23f670)); (*(Obj_88020**)&DAT_004dd6e8)=p?((C1_88020*)p)->FUN_0023f670():0; (*(Obj_88020**)&DAT_004dd6e8)->FUN_0023f690("Hulk release Jun 14 2005 18:39:55"); (*(unsigned int*)&DAT_004dd830)^=0x4de610d; p=FUN_0008d690((int)sizeof(HulkControllerManager)); f10=p?((C2_88020*)p)->FUN_000aef10():0; thunk_FUN_000b10d0(f10); p=FUN_0008d690((int)sizeof(HulkGameControllerManager)); f14=p?((C3_88020*)p)->FUN_000af310(f10):0; ((Obj_88020*)f14)->FUN_000af380(); p=FUN_0008d690((int)sizeof(HulkHapticControllerManager)); f18=p?((C4*)p)->FUN_000b0500(f10):0; ((Obj_88020*)f18)->FUN_000afdf0(); p=FUN_0008d690((int)sizeof(HulkStatsManager)); f48=p?((C5*)p)->FUN_00091630():0; ((Obj_88020*)f48)->FUN_00090d70(); FUN_002381a0(0,13); FUN_002381a0(1,5); FUN_002381a0(2,11); FUN_002381a0(3,13); p=FUN_0008d690((int)sizeof(Hulk_10b2c0)); f44=p?((C6*)p)->FUN_0010b2c0():0; p=FUN_0008d690((int)sizeof(HulkUnlockablesManager)); f3c=p?((C7*)p)->FUN_00094fb0():0; HulkGameTriple* t=(HulkGameTriple*)FUN_0008d690((int)sizeof(HulkGameTriple)); if(t){t->a=1;t->b=0;t->c=0;} f04=t; p=FUN_0008d690((int)sizeof(HulkGameFlowManager)); f38=p?((C8*)p)->FUN_00089bf0():0; ((Obj_88020*)f38)->FUN_0008bf80(f04,f3c); p=FUN_0008d690((int)sizeof(HulkSoundRealTimeManager)); f30=p?((C9*)p)->FUN_001eb220(this,f04,DAT_0049caa0):0; f30->FUN_001ee820(); (*(unsigned int*)((char*)&DAT_004dd830 + 4))+=0x6a5; p=FUN_0008d690((int)sizeof(HulkOverlayManager)); f2c=p?((C10_88020*)p)->FUN_000d6970():0; f2c->FUN_000d6a20(); p=FUN_0008d690((int)sizeof(HulkSubtitleManager)); f4c=p?((C11*)p)->FUN_001c0cd0():0; f4c->FUN_001c0a40(this); p=FUN_0008d690((int)sizeof(HulkFEManager)); f20=p?((C12*)p)->FUN_000c0e40():0; ((Obj_88020*)f20)->FUN_000c4ef0(f10,f18,f1c,f3c,f48,f4c,f38); int v=((Obj_88020*)f20)->FUN_000bb670(); f30->FUN_001ebaf0(v); if(FUN_00209a8e("D:\\")!=0x800) do { FUN_001bb0b0("TBS_STOP_PIRATING"); }while(1); HulkManagerPair* pair=(HulkManagerPair*)FUN_0008d690((int)sizeof(HulkManagerPair)); if(pair){pair->a=0;pair->b=0;} f40=pair; ((Obj_88020*)f40)->FUN_000d3ef0(f20,f10); (*(unsigned int*)&DAT_004dd830)^=0x2e50ebda; p=FUN_0008d690((int)sizeof(HulkRenderManager)); f24=p?((C13*)p)->FUN_001bb990():0; f24->FUN_001b8690(); p=FUN_0008d690((int)sizeof(HulkWorldStreamManager)); f28=p?((C14_88020*)p)->FUN_00208210():0; f28->FUN_002062d0(this); p=FUN_0008d690((int)sizeof(HulkTimeManager)); f08=p?((C15*)p)->FUN_00087e30():0; p=FUN_0008d690((int)sizeof(HulkWorld)); f0c=p?((C16*)p)->FUN_00088600():0; ((Obj_88020*)f0c)->FUN_00088670(this,f10); while((*(Obj_88020**)&DAT_00527c58)->FUN_00264c70()){ Obj_88020* a=DAT_004dd700; if(a && *((unsigned char*)a+0x9d) && *(Obj_88020**)((char*)a+0x54)) (*(Obj_88020**)((char*)a+0x54))->FUN_00086da0(); else {thunk_FUN_00270a50(); FUN_002656a0();} if(f1c && FUN_0008db80()){do {FUN_0008db90(); f1c->FUN_0008db00();}while(FUN_0008db80());}} p=FUN_0008d690((int)sizeof(HulkFMVManager)); f34=p?((C17*)p)->FUN_001b84f0():0; if(DAT_0049caa0)f34->FUN_001b7260(f04,f1c,f28,f3c);  }

// (x64t9-mgr) each manager is allocated as its record (include/decls/managers.h: the words its constructor writes,
// pointers as pointers), the size its constructor's view checks; the 32-bit sizes are the XBE's. The triple and the
// pair (0x000d3ef0 stores two managers in it) are records too.
} // namespace fn_00088020
#undef DAT_004dd700


// 0x00088940 FUN_00088940 (565 B): equivalent/0x00088940.cpp [wrapped: macros]
// sym: ?run@Obj_88940@fn_00088940@@QAEXPAUContext@2@PAUMission_88940@2@@Z @177a598f3895 @wee03094025ee
namespace fn_00088940 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00088940 @ 0x00088940
// cl-flags: /GS
struct Obj_88940; struct Context; struct Mission_88940;
struct ResourceList { char storage[248]; void FUN_0027a630(); void FUN_0027a6e0(const char*,Obj_88940*);  };
struct Component_88940 { void FUN_001bdb90(); void FUN_0009a090(); void FUN_00201bb0(); void FUN_001b3f90(Obj_88940*); void FUN_001dbd40(); void FUN_001b68d0(Obj_88940*); void FUN_001063f0(); void FUN_000244a0(ResourceList*); void FUN_001f6c50(Mission_88940*);  void FUN_001faf70(const char*);  void FUN_001fc690(); void FUN_001cbf40(Mission_88940*);  void FUN_000d71f0(Obj_88940*,void*,void*); void FUN_00078c60(); void FUN_001c0ab0(const char*); };
struct Mission_88940 { const char* FUN_000897f0(); const char* FUN_000897e0(); const char* FUN_0008a2d0(); };
struct Other_88940 { void* FUN_000b4ff0(); };
struct Context {   Other_88940* FUN_00086280(); };
// equiv-conv: _sprintf stack stack stack
#if !defined(__clang__)

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl sprintf(char*,const char*,const char*,const char*);
#endif

#endif
// equiv-conv: FUN_00267760 stack stack stack stack
int __cdecl FUN_00267760(char*,unsigned,const char*,...);
struct Obj_88940 { char pad0[8]; Component_88940 *p08,*p0c,*p10,*p14,*p18,*p1c,*p20,*p24,*p28,*p2c,*p30,*p34,*p38,*p3c,*p40,*p44,*p48,*p4c,*p50; char pad54[8]; unsigned char flag5c; char pad5d[63]; unsigned char flag9c; void run(Context*,Mission_88940*); };
void Obj_88940::run(Context* context,Mission_88940* mission) {
  flag5c=0; flag9c=0;
 p40->FUN_001bdb90(); p08->FUN_0009a090(); p24->FUN_00201bb0(); p10->FUN_001b3f90(this); p0c->FUN_001dbd40(); p14->FUN_001b68d0(this); p18->FUN_001063f0();
 ResourceList list; list.FUN_0027a630(); p20->FUN_000244a0(&list); list.FUN_0027a6e0("art/global.rdl",this);
 char buffer[255]; const char* b=mission->FUN_000897f0(); const char* a=mission->FUN_000897e0(); sprintf(buffer,"art/locations/%s/%s.rdl",a,b); list.FUN_0027a6e0(buffer,this);
 b=mission->FUN_0008a2d0(); a=mission->FUN_0008a2d0(); sprintf(buffer,"art/missions/%s/%s.rdl",a,b); list.FUN_0027a6e0(buffer,this);
 p38->FUN_001f6c50(mission); ((owners::C_1fac40 *)p48)->FUN_001fac40((hulk_intptr)p18); ((owners::C_1fac40 *)p48)->FUN_001fac40((hulk_intptr)p28); ((owners::C_1fac40 *)p48)->FUN_001fac40((hulk_intptr)p0c); ((owners::C_1fac40 *)p48)->FUN_001fac40((hulk_intptr)p4c); void* value=((void *)((owners::Obj_86290 *)context)->FUN_00086290()); ((owners::C_1fac40 *)p48)->FUN_001fac40((hulk_intptr)value);
 b=mission->FUN_000897f0(); a=mission->FUN_000897e0(); FUN_00267760(buffer,255,"art/locations/%s/%s.dh",a,b); p48->FUN_001faf70(buffer);
 b=mission->FUN_0008a2d0(); a=mission->FUN_0008a2d0(); FUN_00267760(buffer,255,"art/missions/%s/%s.dh",a,b); p48->FUN_001faf70(buffer);
 ((owners::Thing_25eb0 *)p20)->FUN_00025eb0(); p28->FUN_001fc690(); p30->FUN_001cbf40(mission); ((owners::Obj_1cd3d0 *)p2c)->FUN_001cd3d0((hulk_intptr)(Mission_88940 *)mission);
 value=((void *)((owners::C_862b0 *)context)->FUN_000862b0()); Other_88940* other=context->FUN_00086280(); void* result=other->FUN_000b4ff0(); p3c->FUN_000d71f0(this,result,value); p4c->FUN_00078c60(); a=mission->FUN_0008a2d0(); p50->FUN_001c0ab0(a); ((owners::X_27a570 *)&list)->FUN_0027a570();
}
} // namespace fn_00088940

