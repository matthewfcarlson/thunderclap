#include "decls/data/engine/audio.h"
#include "decls/data/engine/om.h"

extern "C" int strcmp(const char*, const char*);
extern "C" const char* __cdecl FUN_002611b0(const char*);
const char* __cdecl FUN_00261570(const char* s) {
    const char* x = FUN_002611b0(s);
    const char* y = FUN_002611b0(s);
    return strcmp(x, y) == 0 ? DAT_00429b50 : DAT_004269b4;
}