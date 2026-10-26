#include "decls/data/engine/core.h"
// data: g_code = DAT_004cdcaa

typedef unsigned char byte_272240;
typedef unsigned int uint_272240;
extern "C" bool __cdecl FUN_00272240(byte_272240* p, uint_272240* count, uint_272240* value) {
    byte_272240 b = *p;
    uint_272240 v;
    uint_272240 n;
    if (b <= 0x7f) {
        v = (uint_272240)b;
        n = 1;
    } else if (b >= 0xa1 && b <= 0xdf) {
        v = (uint_272240)b + 0xfec0;
        n = 1;
    } else if (((b >= 0x81 && b <= 0x9f) || (b >= 0xe0 && b <= 0xfc)) && p[1] >= 0x40 && p[1] <= 0xfc &&
               p[1] != 0x7f) {
        v = (*(unsigned short*)&DAT_004cdcaa);
        n = 2;
    } else
        return false;
    if (count)
        *count = n;
    if (value)
        *value = v;
    return true;
}