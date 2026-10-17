// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00261720 @ 0x00261720
#include "decls/data/engine/audio.h"
#include "decls/data/engine/om.h"

extern void * __cdecl FUN_002611b0(void *);
extern float __cdecl FUN_00260d00(void *);

const char * __cdecl FUN_00261720(void *value)
{
    void *first = FUN_002611b0(value);
    void *second = FUN_002611b0(value);
    float left = FUN_00260d00(first);
    float right = FUN_00260d00(second);
    return right < left ? ((char*)&DAT_004269b4) : ((char*)&DAT_00429b50);
}