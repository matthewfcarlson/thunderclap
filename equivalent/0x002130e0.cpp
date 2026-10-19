// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_002130e0 @ 0x002130e0
#include "decls/data/game/global.h"

struct Entry { int type; float value; };
Entry* __fastcall FUN_00212bb0(void* second, void* first);
Entry* __cdecl FUN_00217600(Entry*, void*);
float __cdecl FUN_002130e0(void* first, void* second)
{
    char scratch[8];
    Entry* entry = FUN_00212bb0(second, first);
    if (entry->type != 3) {
        entry = FUN_00217600(entry, scratch);
        if (!entry) return (*(float*)&DAT_003f32e0);
    }
    return entry->value;
}