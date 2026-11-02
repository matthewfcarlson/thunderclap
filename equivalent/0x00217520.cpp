// STATUS: equivalent (tools/equiv.py level 3: 2766 inputs, branch coverage 4/4)
// FUN_00217520 @ 0x00217520
#include "decls/data/engine/unknown.h"

struct Entry { char pad[5]; unsigned char flags; };
struct Context { char pad[16]; Entry **entries; };
extern "C" Entry * __cdecl FUN_00219430(Context *, const char *, int);
extern "C" void __cdecl FUN_00217520(void *context)
{
    for (int i = 0; i < 15; ++i) {
        const char *text = ((const char**)&DAT_00426a24)[i];
        const char *end = text;
        while (*end) ++end;
        ((Context *)context)->entries[0x74 / 4 + i] = FUN_00219430(((Context *)context), text, (int)(end - text));
        ((Context *)context)->entries[0x74 / 4 + i]->flags |= 0x20;
    }
}