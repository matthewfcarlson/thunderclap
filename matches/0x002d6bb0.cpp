#include "decls/data/engine/pure3d.h"

extern "C" int memcmp(const void*, const void*, unsigned int);
int FUN_002d6bb0(const char* p, unsigned int offset, unsigned int count) {
    if (count > 8)
        count = 8;
    if (count < 1)
        return 0;
    if (offset > 7)
        return 0;
    if (offset + count > 8)
        count = 8 - offset;
    return memcmp(p + offset, ((unsigned char*)&DAT_004d102c) + offset, count);
}