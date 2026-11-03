#include "gen/owners.h"
extern "C" char* strncpy(char*, const char*, unsigned int);
void owners::C_e5510::FUN_000e5510(const char* p) {
    if (p)
        strncpy((char*)this + 0xb40, p, 0x40);
    else
        *((char*)this + 0xb40) = 0;
}