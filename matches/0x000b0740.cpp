#include "gen/owners.h"
extern "C" int sprintf(char*, const char*, ...);
extern "C" int FUN_00096670(const char*, const char*, int);
void owners::Dev_b0740::FUN_000b0740(const char* s) {
    sprintf(name, "%s", s);
    if (name[0] == 0) {
        type = 3;
        return;
    }
    if (FUN_00096670(name, "Keyboard", 8) == 0) {
        type = 1;
        return;
    }
    type = (FUN_00096670(name, "Mouse", 5) != 0) ? 0 : 2;
}
