#include "gen/owners.h"
extern "C" char* strncpy(char*, const char*, unsigned int);
void owners::C_266800::FUN_00266800(char* p) {
    if (p)
        strncpy((char*)this + 0x20, p, 0xff);
}