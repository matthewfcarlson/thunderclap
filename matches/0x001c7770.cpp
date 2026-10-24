// FUN_001c7770 @ 0x001c7770
// equiv-map: ?thunk_FUN_00267090@@YAXPAX@Z = 0x0008d330
#include "gen/Render.h"

extern void __cdecl thunk_FUN_00267090(void* p);
extern void* __cdecl FUN_0008d690(unsigned int size);
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
extern "C" void* __cdecl memset(void*, int, unsigned int);

void Render::StoreBase::FUN_001c7770(unsigned int newCapacity) {
    int* fresh = static_cast<int*>(FUN_0008d690(newCapacity << 2));
    memset(fresh, 0, newCapacity << 2);
    if ((*(int * *)&this->f_14) != 0)
        memcpy(fresh, (*(int * *)&this->f_14), (*(unsigned int *)&this->f_10) * 4 + 4);
    (*(unsigned int *)&this->f_08) = newCapacity;
    thunk_FUN_00267090((*(int * *)&this->f_14));
    (*(int * *)&this->f_14) = fresh;
}
