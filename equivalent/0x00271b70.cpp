// STATUS: equivalent (tools/equiv.py level 3: 14823 inputs, branch coverage 12/12)
// FUN_00271b70 @ 0x00271b70
// FUN_00271b70 @ 0x00271b70
#include "decls/data/engine/core.h"

extern unsigned __int64 __fastcall FUN_002719a0(int length, const unsigned char *text);
int __cdecl FUN_00271b70(const unsigned char *text, int *length, int *value)
{
    unsigned int first = *text;
    int extra = ((signed char*)&DAT_0042b6f8)[first];
    int count = extra + 1;
    unsigned __int64 result = FUN_002719a0(count, text);
    unsigned int low = (unsigned int)result;
    if (!(low & 255)) return low;
    const unsigned char *p = (const unsigned char *)(unsigned int)(result >> 32);
    unsigned int code = 0;
    switch (extra) {
    case 3:
        code = first;
        ++p;
        code = (code << 6) + *p++;
        code = (code << 6) + *p++;
        code = (code << 6) + *p;
        break;
    case 2:
        code = *p++;
        code = (code << 6) + *p++;
        code = (code << 6) + *p;
        break;
    case 1:
        code = *p++;
        code = (code << 6) + *p;
        break;
    case 0:
        code = *p;
        break;
    }
    code -= ((int*)&DAT_0042b6d8)[extra];
    if (length) *length = count;
    if (value) *value = code;
    return ((unsigned int)value & 0xffffff00) | 1;
}
