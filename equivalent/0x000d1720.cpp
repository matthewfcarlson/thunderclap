// STATUS: equivalent (tools/equiv.py level 3: 73 inputs, branch coverage 92/92)
// FUN_000d1720 @ 0x000d1720
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
typedef unsigned int size_t;
inline void* operator new(size_t,void* p){return p;}
struct HUDOverlay; namespace math {struct Vector{float x,y,z;};}
struct Base{virtual void v0();virtual void v1();virtual void v2();virtual void v3();char pad[12];unsigned char args[8],result;char pad2[3];void(*callback)();void FUN_001d0480(const char*,int);};
#define TYPES(N,PARAMS,USE) template<PARAMS> struct Method##N:Base{virtual void v0();}; template<PARAMS> struct Closure##N:Method##N<USE>{C* owner;virtual void v0();};
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
TYPES(0,P0,U0) TYPES(1,P1,U1) TYPES(2,P2,U2) TYPES(3,P3,U3) TYPES(4,P4,U4) TYPES(5,P5,U5)
struct Sub54{char data[48];void FUN_000f7930();};struct Sub94{char data[36];void FUN_000dee40();};struct Registry{void FUN_001d3b70(const char*,Base*);};Registry* FUN_001d4c90();void* FUN_0008d690(int);
extern int DAT_0048e10c;
#define CB(n) void FUN_##n();
CB(000ca850) CB(000ca860) CB(000ce590) CB(000cabf0) CB(000cac30) CB(000cac40) CB(000cac50) CB(000cac60) CB(000cacc0) CB(000cacd0) CB(000cad40) CB(000cad80) CB(000ce700) CB(000cad60) CB(000cad70) CB(000cae80) CB(000caea0) CB(000caee0) CB(000caf10) CB(000caf30) CB(000caf40) CB(000caf60) CB(000cafa0) CB(000cafd0) CB(000caff0) CB(000cb010) CB(000cb030) CB(000cb050) CB(000cb060) CB(000cb080) CB(000cb090) CB(000cb0f0) CB(000cb130) CB(000cb170) CB(000cb190) CB(000cb200) CB(000cb230) CB(000cb260) CB(000cb280) CB(000cb2a0) CB(000cb2e0) CB(000cb310) CB(000cb330) CB(000ce750)
struct HUDOverlay{virtual void v0();unsigned char active;char p5[7];int f0c,f10,f14,f18;char p1c[12];int slots[10],f50;Sub54 sub54;int f84,f88,f8c,f90;Sub94 sub94;int fb8;unsigned char fbc;char pbd[127];int f13c;float f140;int f144,f148,zeros14c[5],f160,zeros164[6],f17c,zeros180[16],zeros1c0[24];float f220;unsigned char f224,f225;char p226[2];int zeros228[5],f23c,f240,zeros244[8];struct Entry{unsigned char used;char rest[63];}entries[8];int zeros464[12],f494,f498;float f49c;int zeros4a0[6];char p4b8[12];unsigned char f4c4;char p4c5[63];int f504,f508;HUDOverlay();};
#define T0(R) HUDOverlay,R
#define T1(R,A) HUDOverlay,R,A
#define T2(R,A,B) HUDOverlay,R,A,B
#define T3(R,A,B,C) HUDOverlay,R,A,B,C
#define T4(R,A,B,C,D) HUDOverlay,R,A,B,C,D
#define T5(R,A,B,C,D,E) HUDOverlay,R,A,B,C,D,E
#define REG(K,T,N,NAME,CBODY,RET,ARGS) {void* mem=FUN_0008d690(36);Base* b=0;if(mem){b=(Base*)mem;b->FUN_001d0480(NAME,N);new(mem) Method##K<T>;b->callback=&FUN_##CBODY;b->result=FUN_001d04d0(&DAT_##RET);ARGS Closure##K<T>* c=new(mem) Closure##K<T>;c->owner=this;}registry->FUN_001d3b70(NAME,b);}
#define A1(T) b->args[0]=FUN_001d04d0(&DAT_##T);
#define A2(T,U) A1(T) b->args[1]=FUN_001d04d0(&DAT_##U);
#define A3(T,U,V) A2(T,U) b->args[2]=FUN_001d04d0(&DAT_##V);
#define A4(T,U,V,W) A3(T,U,V) b->args[3]=FUN_001d04d0(&DAT_##W);
#define A5(T,U,V,W,X) A4(T,U,V,W) b->args[4]=FUN_001d04d0(&DAT_##X);
HUDOverlay::HUDOverlay(){active=1;int i;for(i=0;i<10;++i)slots[i]=0;sub54.FUN_000f7930();sub94.FUN_000dee40();f0c=f14=f18=f88=f8c=f90=0;fb8=0x78d;fbc=0;f13c=f144=0;f148=0xffff00ff;for(i=0;i<5;++i)zeros14c[i]=0;for(i=0;i<6;++i)zeros164[i]=0;for(i=0;i<16;++i)zeros180[i]=0;for(i=0;i<24;++i)zeros1c0[i]=0;f84=f160=255;f140=-1.0f;f220=1.0f;f224=f225=0;for(i=0;i<5;++i)zeros228[i]=0;for(i=0;i<8;++i){zeros244[i]=0;entries[i].used=0;}for(i=0;i<12;++i)zeros464[i]=0;f494=255;f498=-1;f49c=-1.0f;for(i=0;i<6;++i)zeros4a0[i]=0;f4c4=0;f504=f508=0;Registry* registry=FUN_001d4c90();if(!registry)return;
REG(0,T0(void),0,"hud_glowHealth",000ca850,0048e100,)
REG(0,T0(void),0,"hud_glowRage",000ca860,0048e100,)
REG(1,T1(void,const char*),1,"hud_SetBossHudEnemy",000ce590,0048e100,A1(0048e0f0))
REG(1,T1(void,const char*),1,"hud_AddBossHudEnemy",000cabf0,0048e100,A1(0048e0f0))
REG(1,T1(void,int),1,"hud_SetBossHudHealthType",000cac30,0048e100,A1(0048e134))
REG(1,T1(void,int),1,"hud_SetBossHealthPipCount",000cac40,0048e100,A1(0048e134))
REG(1,T1(void,float),1,"hud_SetBossHealthMaxHealth",000cac50,0048e100,A1(0048e128))
REG(0,T0(void),0,"hud_ClearBossHud",000cac60,0048e100,)
REG(1,T1(void,float),1,"hud_SetChaseHudDistance",000cacc0,0048e100,A1(0048e128))
REG(1,T1(void,const char*),1,"hud_SetChaseHudDestination",000cacd0,0048e100,A1(0048e0f0))
REG(1,T1(void,const char*),1,"hud_SetChaseHudEnemy",000cad40,0048e100,A1(0048e0f0))
REG(4,T4(void,const char*,float,float,math::Vector),4,"hud_ExplodingText",000cad80,0048e100,A4(0048e0f0,0048e128,0048e128,0048e10c))
REG(3,T3(int,const char*,const char*,float),3,"hud_triggerButtonHintBegin",000ce700,0048e134,A3(0048e0f0,0048e0f0,0048e128))
REG(0,T0(void),0,"hud_triggerButtonHintEnd",000cad60,0048e100,)
REG(0,T0(int),0,"hud_GetButtonHintID",000cad70,0048e134,)
REG(1,T1(void,const char*),1,"hud_SetMap",000cae80,0048e100,A1(0048e0f0))
REG(1,T1(void,math::Vector),1,"hud_SetMapOriginToCoords",000caea0,0048e100,A1(0048e10c))
REG(1,T1(void,int),1,"hud_SetMapOriginToIcon",000caee0,0048e100,A1(0048e134))
REG(1,T1(void,int),1,"hud_SetMapAlpha",000caf10,0048e100,A1(0048e134))
REG(0,T0(void),0,"hud_EnableMapZoom",000caf30,0048e100,)
REG(1,T1(void,float),1,"hud_DisableMapZoom",000caf40,0048e100,A1(0048e128))
REG(2,T2(int,int,math::Vector),2,"hud_AddStaticMapIcon",000caf60,0048e134,A2(0048e134,0048e10c))
REG(2,T2(void,int,math::Vector),2,"hud_SetStaticMapIconPosition",000cafa0,0048e100,A2(0048e134,0048e10c))
REG(2,T2(int,int,const char*),2,"hud_AddMovingMapIcon",000cafd0,0048e134,A2(0048e134,0048e0f0))
REG(2,T2(void,bool,float),2,"hud_SetMapIconFadeOut",000caff0,0048e100,A2(0048e0e4,0048e128))
REG(2,T2(void,int,bool),2,"hud_SetMapIconOnlyVisibleWhenClose",000cb010,0048e100,A2(0048e134,0048e0e4))
REG(1,T1(void,int),1,"hud_RemoveMapIcon",000cb030,0048e100,A1(0048e134))
REG(0,T0(void),0,"hud_RemoveAllMapIcons",000cb050,0048e100,)
REG(1,T1(void,int),1,"hud_RemoveAllMapIconsByType",000cb060,0048e100,A1(0048e134))
REG(0,T0(void),0,"hud_RemoveAllObjectiveArrows",000cb080,0048e100,)
REG(4,T4(int,int,int,math::Vector,math::Vector),4,"hud_AddObjectiveArrow",000cb090,0048e134,A4(0048e134,0048e134,0048e10c,0048e10c))
REG(3,T3(void,int,int,math::Vector),3,"hud_SetObjectiveArrowOffset",000cb0f0,0048e100,A3(0048e134,0048e134,0048e10c))
REG(3,T3(void,int,int,math::Vector),3,"hud_SetObjectiveArrowRotation",000cb130,0048e100,A3(0048e134,0048e134,0048e10c))
REG(2,T2(void,int,int),2,"hud_RemoveObjectiveArrow",000cb170,0048e100,A2(0048e134,0048e134))
REG(5,T5(int,int,const char*,math::Vector,math::Vector,math::Vector),5,"hud_AddObjectiveArrowDirect",000cb190,0048e134,A5(0048e134,0048e0f0,0048e10c,0048e10c,0048e10c))
REG(2,T2(void,int,math::Vector),2,"hud_SetObjectiveArrowOffsetDirect",000cb200,0048e100,A2(0048e134,0048e10c))
REG(2,T2(void,int,math::Vector),2,"hud_SetObjectiveArrowRotationDirect",000cb230,0048e100,A2(0048e134,0048e10c))
REG(1,T1(void,int),1,"hud_RemoveObjectiveArrowDirect",000cb260,0048e100,A1(0048e134))
REG(1,T1(void,bool),1,"hud_ShowHudIcons",000cb280,0048e100,A1(0048e0e4))
REG(2,T2(int,int,math::Vector),2,"hud_AddStaticHudIcon",000cb2a0,0048e134,A2(0048e134,0048e10c))
REG(2,T2(void,int,math::Vector),2,"hud_SetStaticHudIconPosition",000cb2e0,0048e100,A2(0048e134,0048e10c))
REG(2,T2(int,int,const char*),2,"hud_AddMovingHudIcon",000cb310,0048e134,A2(0048e134,0048e0f0))
REG(1,T1(void,int),1,"hud_RemoveHudIcon",000cb330,0048e100,A1(0048e134))
REG(1,T1(void,int),1,"hud_SetEnemyResponseLevel",000ce750,0048e100,A1(0048e134))
}