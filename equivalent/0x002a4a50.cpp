// STATUS: equivalent (tools/equiv.py level 3: 52 inputs, branch coverage 16/18, incomplete)
// FUN_002a4a50 @ 0x002a4a50
#include "compat/ptr.h"
struct Element_2a4a50 { virtual void unused(); virtual void release(); };
struct Array_2a4a50 { unsigned int unknown; Element_2a4a50** begin; Element_2a4a50** end; };
extern "C" void __cdecl FUN_0008d340(void*);
extern "C" void* __cdecl FUN_0008d6d0(hulk_uintptr);
void __stdcall resizeArray(Array_2a4a50* a, unsigned int count) {
    unsigned int i=count;
    while(i < (unsigned int)(a->end-a->begin)) {
        Element_2a4a50** slot=a->begin+i;
        if(*slot) { (*slot)->release(); *slot=0; }
        ++i;
    }
    if(a->begin) FUN_0008d340(a->begin);
    a->begin=0;
    a->end=0;
    if(count) {
        Element_2a4a50** p=(Element_2a4a50**)FUN_0008d6d0(count*4);
        a->begin=p;
        if(p) {
            a->end=(Element_2a4a50**)((char*)p+count*4);
            for(unsigned int j=0;j<count;++j,++p) if(p) *p=0;
            return;
        }
    }
    a->begin=0;
    a->end=0;
}
