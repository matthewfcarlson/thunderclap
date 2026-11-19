// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000cc7e0..0x000d40e0 (kind game, layer game, confidence high), dominant class HUDOverlay
// (tree_prelude.h: not needed)
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/records.h"
#include "decls/data/script.h"
#include "game/script_bind.h"


// 0x000d1720 FUN_000d1720 (5339 B): equivalent/0x000d1720.cpp [wrapped: macros; helper definitions (2 out-of-line function bodies)]
// sym: ??0HUDOverlay@fn_000d1720@@QAE@XZ @0638d49dc471 @w4482c0a5432d @vb5b84e2c0c3e
inline void* operator new(hulk_uintptr,void* p){return p;}
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_000d1720 {
// STATUS: equivalent (tools/equiv.py level 3: 73 inputs, branch coverage 92/92)
// FUN_000d1720 @ 0x000d1720
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


namespace math {struct Vector{float x,y,z;};}
} // namespace fn_000d1720
// (script2) math::Vector's type_info 0x0048e10c ('V') for the records' type codes
template <> struct hulk_script::ScriptType<fn_000d1720::math::Vector> { static const void* tag() { return hulk_script::DAT_0048e10c; } };
namespace fn_000d1720 {
#define TYPES(N,PARAMS,USE,ARGS) template<PARAMS> struct Method##N:Base{virtual void v0();R (C::*callback)(ARGS);}; template<PARAMS> struct Closure##N:Method##N<USE>{C* owner;virtual void v0();};
#define P0 class C,class R
#define P1 P0,class A
#define P2 P1,class B
#define P3 P2,class D
#define P4 P3,class E
#define P5 P4,class F
#define U0 C,R
#define U1 U0,A
#define U2 U1,B
#define U3 U2,D
#define U4 U3,E
#define U5 U4,F
struct Sub54{char data[48];void FUN_000f7930();};struct Sub94{char data[36];void FUN_000dee40();};
// (script2) HUDOverlay's vftable word: the constructor stores the game's vftable 0x0040a498 (no stand-in vftable)
struct HUDOverlay{void* vftable;unsigned char active;char p5[7];int f0c,f10,f14,f18;char p1c[12];int slots[10],f50;Sub54 sub54;int f84,f88,f8c,f90;Sub94 sub94;int fb8;unsigned char fbc;char pbd[127];int f13c;float f140;int f144,f148,zeros14c[5],f160,zeros164[6],f17c,zeros180[16],zeros1c0[24];float f220;unsigned char f224,f225;char p226[2];int zeros228[5],f23c,f240,zeros244[8];struct Entry{unsigned char used;char rest[63];}entries[8];int zeros464[12],f494,f498;float f49c;int zeros4a0[6];char p4b8[12];unsigned char f4c4;char p4c5[63];int f504,f508;HUDOverlay();
void FUN_000ca850(); void FUN_000ca860(); void FUN_000cabf0(const char*); void FUN_000cac30(int); void FUN_000cac40(int); void FUN_000cac50(float); void FUN_000cac60(); void FUN_000cacc0(float); void FUN_000cacd0(const char*); void FUN_000cad40(const char*); void FUN_000cad60(); int FUN_000cad70(); void FUN_000cad80(const char*,float,float,math::Vector); void FUN_000cae80(const char*); void FUN_000caea0(math::Vector); void FUN_000caee0(int); void FUN_000caf10(int); void FUN_000caf30(); void FUN_000caf40(float); int FUN_000caf60(int,math::Vector); void FUN_000cafa0(int,math::Vector); int FUN_000cafd0(int,const char*); void FUN_000caff0(bool,float); void FUN_000cb010(int,bool); void FUN_000cb030(int); void FUN_000cb050(); void FUN_000cb060(int); void FUN_000cb080(); int FUN_000cb090(int,int,math::Vector,math::Vector); void FUN_000cb0f0(int,int,math::Vector); void FUN_000cb130(int,int,math::Vector); void FUN_000cb170(int,int); int FUN_000cb190(int,const char*,math::Vector,math::Vector,math::Vector); void FUN_000cb200(int,math::Vector); void FUN_000cb230(int,math::Vector); void FUN_000cb260(int); void FUN_000cb280(bool); int FUN_000cb2a0(int,math::Vector); void FUN_000cb2e0(int,math::Vector); int FUN_000cb310(int,const char*); void FUN_000cb330(int); void FUN_000ce590(const char*); int FUN_000ce700(const char*,const char*,float); void FUN_000ce750(int);};
// The bound member functions (CB) are HUDOverlay's. Base is Function's fields (include/decls/data/script.h), then
// Method<N>'s member-function pointer; Closure<N> adds the object.
#define Q0
#define Q1 A
#define Q2 A,B
#define Q3 A,B,D
#define Q4 A,B,D,E
#define Q5 A,B,D,E,F
struct Registry{void FUN_001d3b70(const char*,void*);};
extern "C" char DAT_0040a498[], DAT_0040a4c0[], DAT_0040a4d0[], DAT_0040a4e0[], DAT_0040a4f0[], DAT_0040a500[], DAT_0040a510[], DAT_0040a520[], DAT_0040a530[], DAT_0040a540[], DAT_0040a550[], DAT_0040a560[], DAT_0040a570[], DAT_0040a580[], DAT_0040a590[], DAT_0040a5a0[], DAT_0040a5b0[], DAT_0040a5c0[], DAT_0040a5d0[], DAT_0040a5ec[], DAT_0040a5fc[], DAT_0040a60c[], DAT_0040a61c[], DAT_0040a62c[], DAT_0040a63c[], DAT_0040a64c[], DAT_0040a65c[], DAT_0040a66c[], DAT_0040a67c[], DAT_0040a68c[], DAT_0040a69c[], DAT_0040a6ac[], DAT_0040a6bc[], DAT_0040a6cc[], DAT_0040a6dc[], DAT_0040a6ec[], DAT_0040a6fc[];   // (script2) the instantiations' Method<N> / Closure<N> vftables
extern "C" Registry* FUN_001d4c90();extern "C" void* FUN_0008d690(int);
#define T0(R) HUDOverlay,R
#define T1(R,A) HUDOverlay,R,A
#define T2(R,A,B) HUDOverlay,R,A,B
#define T3(R,A,B,C) HUDOverlay,R,A,B,C
#define T4(R,A,B,C,D) HUDOverlay,R,A,B,C,D
#define T5(R,A,B,C,D,E) HUDOverlay,R,A,B,C,D,E
// (script2) the Method<N> / Closure<N> are include/game/script_bind.h's records with the game's vftables by address
// (MV, CV: the instantiation's Method<N> and Closure<N> vftables), as the game's inlined constructors store them.
#define REG(K,T,NAME,CBODY,MV,CV) registry->FUN_001d3b70(NAME,new hulk_script::ScriptClosure<hulk_script::ScriptMethod##K<T>,HUDOverlay>(NAME,this,&HUDOverlay::FUN_##CBODY,DAT_##MV,DAT_##CV));
#define A1(T) b->argTypes[0]=FUN_001d04d0(&DAT_##T);
#define A2(T,U) A1(T) b->argTypes[1]=FUN_001d04d0(&DAT_##U);
#define A3(T,U,V) A2(T,U) b->argTypes[2]=FUN_001d04d0(&DAT_##V);
#define A4(T,U,V,W) A3(T,U,V) b->argTypes[3]=FUN_001d04d0(&DAT_##W);
#define A5(T,U,V,W,X) A4(T,U,V,W) b->argTypes[4]=FUN_001d04d0(&DAT_##X);
HUDOverlay::HUDOverlay(){active=1;vftable=DAT_0040a498;int i;for(i=0;i<10;++i)slots[i]=0;sub54.FUN_000f7930();sub94.FUN_000dee40();f0c=f14=f18=f88=f8c=f90=0;fb8=0x78d;fbc=0;f13c=f144=0;f148=0xffff00ff;for(i=0;i<5;++i)zeros14c[i]=0;for(i=0;i<6;++i)zeros164[i]=0;for(i=0;i<16;++i)zeros180[i]=0;for(i=0;i<24;++i)zeros1c0[i]=0;f84=f160=255;f140=-1.0f;f220=1.0f;f224=f225=0;for(i=0;i<5;++i)zeros228[i]=0;for(i=0;i<8;++i){zeros244[i]=0;entries[i].used=0;}for(i=0;i<12;++i)zeros464[i]=0;f494=255;f498=-1;f49c=-1.0f;for(i=0;i<6;++i)zeros4a0[i]=0;f4c4=0;f504=f508=0;Registry* registry=FUN_001d4c90();if(!registry)return;
REG(0,T0(void),"hud_glowHealth",000ca850,0040a4c0,0040a5ec)
REG(0,T0(void),"hud_glowRage",000ca860,0040a4c0,0040a5ec)
REG(1,T1(void,const char*),"hud_SetBossHudEnemy",000ce590,0040a4d0,0040a5fc)
REG(1,T1(void,const char*),"hud_AddBossHudEnemy",000cabf0,0040a4d0,0040a5fc)
REG(1,T1(void,int),"hud_SetBossHudHealthType",000cac30,0040a4e0,0040a60c)
REG(1,T1(void,int),"hud_SetBossHealthPipCount",000cac40,0040a4e0,0040a60c)
REG(1,T1(void,float),"hud_SetBossHealthMaxHealth",000cac50,0040a4f0,0040a61c)
REG(0,T0(void),"hud_ClearBossHud",000cac60,0040a4c0,0040a5ec)
REG(1,T1(void,float),"hud_SetChaseHudDistance",000cacc0,0040a4f0,0040a61c)
REG(1,T1(void,const char*),"hud_SetChaseHudDestination",000cacd0,0040a4d0,0040a5fc)
REG(1,T1(void,const char*),"hud_SetChaseHudEnemy",000cad40,0040a4d0,0040a5fc)
REG(4,T4(void,const char*,float,float,math::Vector),"hud_ExplodingText",000cad80,0040a500,0040a62c)
REG(3,T3(int,const char*,const char*,float),"hud_triggerButtonHintBegin",000ce700,0040a510,0040a63c)
REG(0,T0(void),"hud_triggerButtonHintEnd",000cad60,0040a4c0,0040a5ec)
REG(0,T0(int),"hud_GetButtonHintID",000cad70,0040a520,0040a64c)
REG(1,T1(void,const char*),"hud_SetMap",000cae80,0040a4d0,0040a5fc)
REG(1,T1(void,math::Vector),"hud_SetMapOriginToCoords",000caea0,0040a530,0040a65c)
REG(1,T1(void,int),"hud_SetMapOriginToIcon",000caee0,0040a4e0,0040a60c)
REG(1,T1(void,int),"hud_SetMapAlpha",000caf10,0040a4e0,0040a60c)
REG(0,T0(void),"hud_EnableMapZoom",000caf30,0040a4c0,0040a5ec)
REG(1,T1(void,float),"hud_DisableMapZoom",000caf40,0040a4f0,0040a61c)
REG(2,T2(int,int,math::Vector),"hud_AddStaticMapIcon",000caf60,0040a540,0040a66c)
REG(2,T2(void,int,math::Vector),"hud_SetStaticMapIconPosition",000cafa0,0040a550,0040a67c)
REG(2,T2(int,int,const char*),"hud_AddMovingMapIcon",000cafd0,0040a560,0040a68c)
REG(2,T2(void,bool,float),"hud_SetMapIconFadeOut",000caff0,0040a570,0040a69c)
REG(2,T2(void,int,bool),"hud_SetMapIconOnlyVisibleWhenClose",000cb010,0040a580,0040a6ac)
REG(1,T1(void,int),"hud_RemoveMapIcon",000cb030,0040a4e0,0040a60c)
REG(0,T0(void),"hud_RemoveAllMapIcons",000cb050,0040a4c0,0040a5ec)
REG(1,T1(void,int),"hud_RemoveAllMapIconsByType",000cb060,0040a4e0,0040a60c)
REG(0,T0(void),"hud_RemoveAllObjectiveArrows",000cb080,0040a4c0,0040a5ec)
REG(4,T4(int,int,int,math::Vector,math::Vector),"hud_AddObjectiveArrow",000cb090,0040a590,0040a6bc)
REG(3,T3(void,int,int,math::Vector),"hud_SetObjectiveArrowOffset",000cb0f0,0040a5a0,0040a6cc)
REG(3,T3(void,int,int,math::Vector),"hud_SetObjectiveArrowRotation",000cb130,0040a5a0,0040a6cc)
REG(2,T2(void,int,int),"hud_RemoveObjectiveArrow",000cb170,0040a5b0,0040a6dc)
REG(5,T5(int,int,const char*,math::Vector,math::Vector,math::Vector),"hud_AddObjectiveArrowDirect",000cb190,0040a5c0,0040a6ec)
REG(2,T2(void,int,math::Vector),"hud_SetObjectiveArrowOffsetDirect",000cb200,0040a550,0040a67c)
REG(2,T2(void,int,math::Vector),"hud_SetObjectiveArrowRotationDirect",000cb230,0040a550,0040a67c)
REG(1,T1(void,int),"hud_RemoveObjectiveArrowDirect",000cb260,0040a4e0,0040a60c)
REG(1,T1(void,bool),"hud_ShowHudIcons",000cb280,0040a5d0,0040a6fc)
REG(2,T2(int,int,math::Vector),"hud_AddStaticHudIcon",000cb2a0,0040a540,0040a66c)
REG(2,T2(void,int,math::Vector),"hud_SetStaticHudIconPosition",000cb2e0,0040a550,0040a67c)
REG(2,T2(int,int,const char*),"hud_AddMovingHudIcon",000cb310,0040a560,0040a68c)
REG(1,T1(void,int),"hud_RemoveHudIcon",000cb330,0040a4e0,0040a60c)
REG(1,T1(void,int),"hud_SetEnemyResponseLevel",000ce750,0040a4e0,0040a60c)
}
} // namespace fn_000d1720
#undef A1
#undef A2
#undef A3
#undef A4
#undef A5
#undef P0
#undef P1
#undef P2
#undef P3
#undef P4
#undef P5
#undef Q0
#undef Q1
#undef Q2
#undef Q3
#undef Q4
#undef Q5
#undef REG
#undef T0
#undef T1
#undef T2
#undef T3
#undef T4
#undef T5
#undef TYPES
#undef U0
#undef U1
#undef U2
#undef U3
#undef U4
#undef U5
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

