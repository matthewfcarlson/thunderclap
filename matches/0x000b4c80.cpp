#include "gen/owners.h"
extern "C" int __cdecl strcmp(const char*, const char*);
bool owners::Table_b4c80::FUN_000b4c80(const char* name) {
    for (int i = 0; i < 0x80; i++) {
        const char* s = names[i];
        if (!s)
            return false;
        if (strcmp(name, s) == 0)
            return true;
    }
    return false;
}
