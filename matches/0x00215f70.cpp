// luaO_log2: floor(log2(x)) through the byte table at 0x00426830.
#include "decls/data/engine/unknown.h"
// data: gTable_215f70 = DAT_00426830

extern "C" int __cdecl FUN_00215f70(unsigned int value) {
    int count = -1;
    while (value >= 0x100) {
        value >>= 8;
        count += 8;
    }
    return ((unsigned char*)&DAT_00426830)[value] + count;
}
