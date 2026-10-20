// STATUS: equivalent (tools/equiv.py level 3: 20008 inputs, branch coverage 4/4)
// FUN_00277b70 @ 0x00277b70
#include "decls/data/engine/core.h"
#include "gen/core.h"

struct File_nv_277b70 {
    core::File* FUN_002764d0(unsigned int a,unsigned int b,int c,int d,int e,int f,int g,int h,int i);
};
struct Object_277b70 { Object_277b70* FUN_00277a70(unsigned int a,core::File* b,unsigned int c); };
extern "C" core::File* __cdecl FUN_00275d50(unsigned int size);
extern "C" Object_277b70* __cdecl FUN_00266e00(unsigned int a,unsigned int size);
void __cdecl FUN_00277b70(Object_277b70** out,unsigned int a,unsigned int b,unsigned int c,unsigned int d) {
 core::File* p=FUN_00275d50(0x168);
 core::File* base=0;
 if(p) base=((File_nv_277b70*)(p))->FUN_002764d0(a,b,0,0,1,0,0,0,1);
 (*(unsigned int*)&DAT_004cdbb0)=d;
 Object_277b70* mem=FUN_00266e00(d,0x74);
 Object_277b70* result=0;
 if(mem) result=mem->FUN_00277a70(a,base,c);
 base->vfunc_1();
 *out=result;
}