#include "decls/data/engine/audio.h"
#include "decls/data/engine/om.h"

extern void* __cdecl FUN_002611b0(void*);
extern float __cdecl FUN_00260d00(void*);
const char* __cdecl FUN_00261720(void* value) {
    void* first = FUN_002611b0(value);
    void* second = FUN_002611b0(value);
    float left = FUN_00260d00(first);
    float right = FUN_00260d00(second);
    return left <= right ? ((char*)&DAT_00429b50) : ((char*)&DAT_004269b4);
}