#include "decls/data/engine/unknown.h"
// data: gTable_215f70 = DAT_00426830

int target(unsigned int value) {
    int count = -1;
    while (value >= 0x100) {
        value >>= 8;
        count += 8;
    }
    return ((unsigned char*)&DAT_00426830)[value] + count;
}