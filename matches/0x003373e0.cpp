#include "gen/owners.h"
extern "C" int strcmp(const char*, const char*);
char* owners::Table_3373e0::FUN_003373e0(const char* s) {
    for (int i = 0; i < count; i++) {
        char* e = first + 4 + i * 0x288;
        if (strcmp(s, e) == 0)
            return (char*)this + 8 + i * 0x288;
    }
    return 0;
}
