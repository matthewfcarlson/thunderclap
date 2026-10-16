// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// FUN_00277b70 @ 0x00277b70
#include "decls/data/engine/core.h"

struct Base_277b70 {
 virtual void slot0();
 virtual void release();
 Base_277b70* FUN_002764d0(unsigned int a,unsigned int b,int c,int d,int e,int f,int g,int h,int i);
};
struct Object { Object* FUN_00277a70(unsigned int a,Base_277b70* b,unsigned int c); };
extern "C" Base_277b70* __cdecl FUN_00275d50(unsigned int size);
extern "C" Object* __cdecl FUN_00266e00(unsigned int a,unsigned int size);
void __cdecl FUN_00277b70(Object** out,unsigned int a,unsigned int b,unsigned int c,unsigned int d) {
 Base_277b70* p=FUN_00275d50(0x168);
 Base_277b70* base=0;
 if(p) base=p->FUN_002764d0(a,b,0,0,1,0,0,0,1);
 (*(unsigned int*)&DAT_004cdbb0)=d;
 Object* mem=FUN_00266e00(d,0x74);
 Object* result=0;
 if(mem) result=mem->FUN_00277a70(a,base,c);
 base->release();
 *out=result;
}