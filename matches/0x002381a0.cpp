#include "decls/data/engine/fight.h"

extern "C" int __cdecl FUN_002381a0(int index, int value);
extern "C" int __cdecl FUN_002381a0(int index, int value) {
    int old = ((int*)&DAT_004caa14)[index];
    ((int*)&DAT_004caa14)[index] = value;
    return old;
}