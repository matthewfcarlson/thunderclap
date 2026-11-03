#include "gen/owners.h"
extern "C" char* strncpy(char*, const char*, unsigned);
char owners::X_626c0::FUN_000626c0(const char* s) {
    strncpy(buf, s, 0x80);
    return 1;
}
