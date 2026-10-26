#include "decls/data/engine/audio.h"
// data: g_ptr = DAT_004cc1fc

void* __cdecl Swap(void* value) {
    void* old = (*(void**)&DAT_004cc1fc);
    (*(void**)&DAT_004cc1fc) = value;
    return old;
}