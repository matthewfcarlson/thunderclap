// STATUS: equivalent (tools/equiv.py level 3: 70 inputs, branch coverage 14/14)
// FUN_000b4cf0 @ 0x000b4cf0
#include "gen/owners.h"

hulk_uintptr owners::NameTable_b4cf0::FUN_000b4cf0(const char *name)
{
    for (int i = 0; i < 128; i++) {
        const char *s = names[i];
        if (s == 0)
            return 0;
        const char *p = name;
        while (*p == *s) {
            if (*p == 0)
                break;
            p++;
            s++;
        }
        if (*p == *s)
            return values[i];
    }
    return 0;
}
