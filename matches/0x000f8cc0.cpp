#include "gen/owners.h"
extern "C" int strcmp(const char*, const char*);
int owners::Table_f8cc0::FUN_000f8cc0(const char* s) {
    int i = 0;
    const char* p = s;
    do {
        if (items[i] == 0)
            return 0;
        if (strcmp((const char*)(items[i] + 0x18), p) == 0)
            return ((int*)this)[i + 1];
        ++i;
    } while (i < 128);
    return 0;
}