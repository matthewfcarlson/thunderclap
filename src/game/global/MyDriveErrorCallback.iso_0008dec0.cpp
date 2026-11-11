// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0008de70..0x0008ed50 (kind game, layer game, confidence high), dominant class MyDriveErrorCallback
// (tree_prelude.h: not needed)


// 0x0008dec0 FUN_0008dec0 (424 B): equivalent/0x0008dec0.cpp [isolated: conflict: CSPHulkPropLoader; DAT_004dd7e4; DAT_0052c2b0; DAT_00555444; on include/gen/ and not mergeable]
// sym: ?FUN_0008dec0@Target_8dec0@owners@@QAEXXZ @688b3e9386fe @w2ddb286dea1f
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 12/12)
// FUN_0008dec0 @ 0x0008dec0
#include "decls/address.h"
#include "gen/owners.h"
extern char DAT_004dd7e4,DAT_0049c7dc,DAT_0049c90c,DAT_0049c8c4,DAT_0049c8e8; extern int DAT_004d293c,DAT_004d2940,DAT_004d2944,DAT_004d2948; extern "C" void FUN_00201850(); extern void (*DAT_00555444)();
extern "C" void __cdecl FUN_0008ecd0(void *);void* __cdecl FUN_0008d690(int);void* __cdecl FUN_00263ea0(int);extern "C" void __cdecl FUN_002f4df0(int,void*);extern "C" void FUN_00291dc0();extern "C" void FUN_002f5130();
struct AICollisionSolverAgent_8dec0{void* FUN_001b2e50();};
struct CSPHulkPropLoader{virtual void slot0_00038290();void FUN_00290740();char pad[16];};
struct Resource_8dec0{virtual void s0();virtual void s1();virtual void s2();virtual void s3();virtual void s4();virtual void s5();virtual void s6();virtual void s7();virtual void s8();virtual void s9();virtual void s10();virtual void s11(int);char pad[16];unsigned char enabled;};
Resource_8dec0* __cdecl FUN_00344e74(void*,int,void*,void*,int);
struct Manager_8dec0{void FUN_002659a0(int);void FUN_00265210(void*,int);};extern Manager_8dec0* DAT_00527c58;
struct Names_8dec0{void* FUN_00292560(void*);};extern Names_8dec0* DAT_0052c2b0;
struct Gfx{virtual void s0();virtual void s1();virtual void s2();virtual void s3();virtual void s4();virtual void s5();virtual void s6();virtual void s7();virtual void s8();virtual void s9();virtual void s10();virtual void s11();virtual void s12();virtual void s13();virtual void s14();virtual void s15();virtual void s16();virtual void s17();virtual void s18();virtual void s19();virtual void s20();virtual void s21();virtual void s22();virtual void s23();virtual void s24();virtual void s25();virtual void s26();virtual void s27();virtual void s28();virtual void s29();virtual void s30();virtual void s31();virtual void s32();virtual void s33();virtual void s34();virtual void s35();virtual void s36();virtual void s37();virtual void s38();virtual void s39();virtual void s40();virtual void s41();virtual void s42();virtual void s43();virtual void s44();virtual void s45();virtual void s46();virtual void s47();virtual void s48();virtual void s49();virtual void s50();virtual void s51();virtual void s52();virtual void s53();virtual void s54();virtual void s55();virtual void s56();virtual void s57();virtual void s58(int);};
void owners::Target_8dec0::FUN_0008dec0(){name=&DAT_004dd7e4;FUN_0008ecd0(&DAT_004dd7e4);handle=DAT_0052c2b0->FUN_00292560(name);DAT_0052c2a8->s58(1);DAT_004d293c=300;DAT_004d2948=0;DAT_004d2940=64;DAT_004d2944=2048;AICollisionSolverAgent_8dec0* p=(AICollisionSolverAgent_8dec0*)FUN_0008d690(12);void* q=p?p->FUN_001b2e50():0;FUN_002f4df0(2,q);FUN_00291dc0();Resource_8dec0* r=FUN_00344e74(((void *)((owners::Obj_265310 *)DAT_00527c58)->FUN_00265310((hulk_intptr)0x23000)),0,&DAT_0049c7dc,&DAT_0049c90c,0);if(r)r->enabled=0;DAT_00527c58->FUN_002659a0(0x802000a);CSPHulkPropLoader* l=(CSPHulkPropLoader*)FUN_00263ea0(20);if(l){l->FUN_00290740();l->CSPHulkPropLoader::CSPHulkPropLoader();}DAT_00527c58->FUN_00265210(l,0x802000a);FUN_002f5130();DAT_00555444=&FUN_00201850;r=FUN_00344e74(((void *)((owners::Thing_265340 *)DAT_00527c58)->FUN_00265340((char *)"png")),0,&DAT_0049c8c4,&DAT_0049c8e8,0);if(r)r->s11(2);r=FUN_00344e74(((void *)((owners::Thing_265340 *)DAT_00527c58)->FUN_00265340((char *)"bmp")),0,&DAT_0049c8c4,&DAT_0049c8e8,0);if(r)r->s11(2);r=FUN_00344e74(((void *)((owners::Thing_265340 *)DAT_00527c58)->FUN_00265340((char *)"tga")),0,&DAT_0049c8c4,&DAT_0049c8e8,0);if(r)r->s11(2);}

