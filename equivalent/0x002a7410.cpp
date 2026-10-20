// STATUS: equivalent (tools/equiv.py level 3: 56 inputs, branch coverage 12/12)
// FUN_002a7410 @ 0x002a7410
#include "compat/ptr.h"
typedef unsigned int uint;
struct RefObject_2a7410 { virtual void AddRef(); virtual void Release(); };
void* __cdecl FUN_0008d6d0(hulk_uintptr);
struct Base_2a7410 { virtual void v0(); char pad[0x3c]; Base_2a7410(const Base_2a7410&); };
namespace pure3d {
struct ParticleController : Base_2a7410 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void vfunc_23();
 unsigned char flag; char gap[3]; uint a,b,c; RefObject_2a7410** begin; RefObject_2a7410** end;
 ParticleController(const ParticleController&);
};
ParticleController::ParticleController(const ParticleController& src) : Base_2a7410(src) {
 flag=src.flag; a=src.a; b=src.b; c=src.c;
 uint count=(uint)(((int)((char*)src.end-(char*)src.begin))>>2);
 if(count) {
 uint bytes=count*4;
 RefObject_2a7410** allocated=(RefObject_2a7410**)FUN_0008d6d0(bytes);
 begin=allocated;
 if(allocated) end=(RefObject_2a7410**)((char*)allocated+bytes);
 else { begin=0; end=0; }
 } else { begin=0; end=0; }
 for(uint i=0;i<(uint)(((int)((char*)end-(char*)begin))>>2);++i) {
 begin[i]=0;
 RefObject_2a7410* obj=src.begin[i];
 RefObject_2a7410** slot=begin+i;
 if(obj) obj->AddRef();
 if(*slot) (*slot)->Release();
 *slot=obj;
 }
 ParticleController::vfunc_23();
}
}
