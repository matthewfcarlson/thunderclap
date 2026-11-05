#include "decls/data/platform/xbox/unknown.h"
// data: result = DAT_004e5ce8

extern "C" __int64 __cdecl FUN_002672f0(const char*, int, int);
void init() {
    (*(__int64*)&DAT_004e5ce8) = FUN_002672f0("HalSystem", 0, 0);
}