#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"

extern "C" void FUN_00267760(unsigned int, unsigned int, const char*, ...);
extern "C" void FUN_00096d50(hulk_uintptr p1, unsigned int p2, unsigned int p3, unsigned int p4) {
    FUN_00267760(p1, p2, (const char*)((hulk_intptr)((char*)&DAT_00404adc)), p4, p3);
}
