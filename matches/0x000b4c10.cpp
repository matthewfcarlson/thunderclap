#include "gen/owners.h"
extern "C" int strcmp(const char*, const char*);
bool owners::K_b4c10::FUN_000b4c10(const char* s) {
    for (int i = 0; i < 128; i++) {
        const char* n = names[i];
        if (!n)
            break;
        if (strcmp(s, n) == 0)
            return true;
    }
    return false;
}
