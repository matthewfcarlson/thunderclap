#include "gen/owners.h"
extern "C" int __cdecl FUN_000969d0(int);
void owners::Queue_35c70::FUN_00035c70(hulk_intptr value) {
    int result = FUN_000969d0(((int)value));
    if (count >= 64) {
        entries[index] = result;
        index = (index + 1) % 64;
        return;
    }
    entries[count] = result;
    ++count;
}
