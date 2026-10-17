// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00261630 @ 0x00261630
#include "decls/data/engine/audio.h"
#include "decls/data/engine/om.h"

extern "C" void* __cdecl FUN_002611b0(void* value);
extern "C" float __cdecl FUN_00260d00(void* value);

char* __cdecl FUN_00261630(void* value)
{
    void* first = FUN_002611b0(value);
    void* second = FUN_002611b0(value);
    float firstValue = FUN_00260d00(first);
    float secondValue = FUN_00260d00(second);
    return secondValue < firstValue ? ((char*)&DAT_00429b50) : ((char*)&DAT_004269b4);
}