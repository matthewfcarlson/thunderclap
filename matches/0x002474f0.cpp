#include "decls/data/engine/audio.h"
// data: g_ptr = DAT_004cc1fc

extern "C" void* __cdecl FUN_002474f0(void* value) {
    void* old = (*(void**)&DAT_004cc1fc);
    (*(void**)&DAT_004cc1fc) = value;
    return old;
}