// STATUS: equivalent (tools/equiv.py level 3: 3005 inputs, branch coverage 12/12)
// FUN_0024c200 @ 0x0024c200
#include "decls/data/engine/audio.h"

struct Entry { int value; const char *name; char unused[16]; };
int __cdecl FUN_0024c200(const char *name)
{
    for (unsigned i = 0; i < 6; ++i) {
        const char *a = name;
        const char *b = ((Entry*)&DAT_004cc248)[i].name;
        while (*a && *a == *b) { ++a; ++b; }
        if (*a == *b) return ((Entry*)&DAT_004cc248)[i].value;
    }
    return 7;
}