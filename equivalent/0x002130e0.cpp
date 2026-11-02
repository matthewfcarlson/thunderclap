// STATUS: equivalent (tools/equiv.py level 3: 18596 inputs, branch coverage 4/4)
// FUN_002130e0 @ 0x002130e0
// FUN_002130e0 @ 0x002130e0
#include "decls/data/game/global.h"

struct Entry { int type; float value; };
Entry* __fastcall FUN_00212bb0(void* second, void* first);
extern "C" void * __cdecl FUN_00217600(void *, void *);
extern "C" float __cdecl FUN_002130e0(void* first, void* second)
{
    char scratch[8];
    Entry* entry = FUN_00212bb0(second, first);
    if (entry->type != 3) {
        entry = ((Entry *)FUN_00217600((Entry *)entry, scratch));
        if (!entry) return (*(float*)&DAT_003f32e0);
    }
    return entry->value;
}
