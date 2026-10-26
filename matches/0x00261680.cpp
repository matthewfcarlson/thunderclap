#include "decls/data/engine/audio.h"
#include "decls/data/engine/om.h"

extern "C" void* __cdecl FUN_002611b0(void*);
extern "C" float __cdecl FUN_00260d00(void*);
const char* __cdecl FUN_00261680(void* value) {
    void* first = FUN_002611b0(value);
    void* second = FUN_002611b0(value);
    float firstValue = FUN_00260d00(first);
    float secondValue = FUN_00260d00(second);
    return firstValue < secondValue ? ((char*)&DAT_00429b50) : ((char*)&DAT_004269b4);
}