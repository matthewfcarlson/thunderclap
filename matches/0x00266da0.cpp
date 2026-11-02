// Same code shape as 0x002474f0 (propagated; names are from that function)
#include "decls/data/engine/unknown.h"
// data: g_ptr = DAT_00527f60

extern "C" void* __cdecl FUN_00266da0(void* value) {
    void* old = (*(void**)&DAT_00527f60);
    (*(void**)&DAT_00527f60) = value;
    return old;
}