#include "compat/ptr.h"
#include "gen/owners.h"
void owners::Thing_2bdd00::FUN_002bdd00(void* p) {
    value = p;
    for (int i = 0; i < count * 4; ++i) {
        hulk_intptr off = i * 0x18;
        *(void**)((char*)off + (hulk_intptr)base + 0xc) = value;
    }
}