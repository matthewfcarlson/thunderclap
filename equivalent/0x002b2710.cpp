// STATUS: equivalent (tools/equiv.py level 3: 155 inputs, branch coverage 10/10)
// FUN_002b2710 @ 0x002b2710
#include "compat/ptr.h"
void* __cdecl FUN_0008d6d0(hulk_uintptr);
struct FUN_00284a70 { virtual void dummy(); char pad[20]; FUN_00284a70(); };
namespace pure3d {
struct MultiController : FUN_00284a70 {
 unsigned int state; float rate; float weight; unsigned int a,b; float step; float duration; float maxTime; unsigned int c,d; unsigned char enabled; char padding[3]; unsigned int e; unsigned int* entries; unsigned int* end;
 virtual void dummy();
 MultiController(unsigned int count,float durationArg,float rateArg);
};
MultiController::MultiController(unsigned int count,float durationArg,float rateArg) {
 rate=rateArg; state=0; weight=1.0f; a=0; b=0;
 double t=(double)durationArg-1.0f;
 if(t<0.0f) t=0.0f;
 duration=durationArg; maxTime=3.402823466e+38f; c=0; d=0; enabled=1; e=0;
 step=(float)(t/rateArg);
 if(count) { entries=(unsigned int*)FUN_0008d6d0(count*4); if(entries) end=(unsigned int*)((char*)entries+count*4); else { entries=0; end=0; } }
 else { entries=0; end=0; }
 for(unsigned int i=0;i<count;++i) entries[i]=0;
}
}
