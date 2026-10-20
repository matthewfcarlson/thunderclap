// STATUS: equivalent (tools/equiv.py level 3: 20020 inputs, branch coverage 8/8)
// FUN_0008d480 @ 0x0008d480
// FUN_0008d480 @ 0x0008d480
#include "compat/ptr.h"
#include "decls/data/game/unknown.h"

extern "C" void __cdecl FUN_0008d320();
struct Ref_8d480 { virtual void FUN_00000000(); virtual void FUN_00000004(); }; struct Obj_8d480 { int size; Ref_8d480* a; Ref_8d480* b; char pad[0x48]; void* heap; void FUN_0008d3a0(int,int); void FUN_0008d480(); }; extern "C" void __cdecl FUN_00267280(); extern "C" void __cdecl FUN_00266d90(); extern "C" void __cdecl FUN_00266db0(hulk_intptr,int); extern "C" void __stdcall FUN_00209f01(int*); extern "C" Ref_8d480* __cdecl FUN_00266f40(int); extern "C" void __cdecl FUN_002670b0(int,int,Ref_8d480*); extern "C" void* __cdecl FUN_00266e00(int,hulk_intptr); extern "C" Ref_8d480* __cdecl FUN_0026cfa0(void*,int,int,const char*);   void Obj_8d480::FUN_0008d480() { FUN_00267280(); FUN_00266d90(); FUN_00266db0(((hulk_intptr)(void (__cdecl*)())&FUN_0008d320),0); int bounds[8]; FUN_00209f01(bounds); size=bounds[2]-bounds[3]; Ref_8d480* p=FUN_00266f40(0); if(p)p->FUN_00000000(); if(a)a->FUN_00000004(); a=p; FUN_002670b0(0,0,p); void* h=FUN_00266e00(0,0x20800); heap=h; p=FUN_0026cfa0(h,0x20800,0,"Temporary Heap"); if(p)p->FUN_00000000(); if(b)b->FUN_00000004(); b=p; FUN_002670b0(1,0,p); int ids[]={3,4,5,6,10,11,7,12,13,15,16,17,18,14,9}; for(int i=0;i<15;i++) FUN_0008d3a0(ids[i],0); DAT_0052c284=9; (*(unsigned char*)&DAT_004dd778)=1; }
