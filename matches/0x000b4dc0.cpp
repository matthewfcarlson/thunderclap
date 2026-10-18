#include "decls/data/game/global.h"

extern "C" int strcmp(const char*, const char*);
const char* words[3];

extern "C" bool __stdcall FUN_000b4dc0(const char* s) {
    const char** p = words;
    do {
        const char* q = *p;
        if (q == 0)
            break;
        if (strcmp(s, q) == 0)
            return true;
        ++p;
    } while ((int)p < ((int)DAT_0049f3e4));
    return false;
}