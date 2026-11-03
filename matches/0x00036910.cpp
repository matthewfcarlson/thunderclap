#include "compat/ptr.h"
#include "gen/owners.h"
void owners::C_36910::FUN_00036910(unsigned char x) {
    hulk_intptr p = *(int*)((char*)this + 0x12c);
    if (p && *(int*)(p + 0x74))
        *(unsigned char*)(*(hulk_intptr*)(p + 0x74) + 0x72) = x;
}