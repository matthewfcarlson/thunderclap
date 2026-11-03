#include "compat/ptr.h"
#include "gen/owners.h"
void __fastcall cleanup(void*);
void owners::X_2d0c80::FUN_002d0c80() {
    hulk_uintptr n = ((char*)end - (char*)begin) >> 2;
    for (unsigned int i = 0; i < n; ++i) {
        void* p = begin[i];
        if (p)
            cleanup(p);
    }
}