#include "decls/data/engine/audio.h"

typedef unsigned int u32_24c310;
typedef int i32_24c310;
extern "C" u32_24c310 __cdecl FUN_0024c310(i32_24c310* format) {
    return ((u32_24c310*)&DAT_004cc254)[((*format << 28) >> 28) * 6];
}