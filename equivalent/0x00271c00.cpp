// STATUS: equivalent (tools/equiv.py level 3: 86 inputs, branch coverage 18/20, incomplete)
// FUN_00271c00 @ 0x00271c00
#include "decls/data/engine/core.h"

int __cdecl FUN_00271c00(unsigned int, unsigned char *, unsigned int, unsigned int, unsigned int *, void *);
int __cdecl encode_utf8(unsigned int codepoint, unsigned char *destination, unsigned int capacity, unsigned int replacement, unsigned int *written, void *context)
{
    unsigned int length;
    if (codepoint < 0x80) length = 1;
    else if (codepoint < 0x800) length = 2;
    else if (codepoint < 0x10000) length = 3;
    else if (codepoint < 0x200000) length = 4;
    else {
        if (!replacement) return -4;
        int result = FUN_00271c00(replacement, destination, capacity, 0, written, context);
        return result == -2 ? -6 : result;
    }
    if (capacity < length) return -1;
    unsigned int remaining = codepoint;
    for (unsigned int i = length; i > 1; --i) {
        destination[i - 1] = (unsigned char)((remaining & 0x3f) | 0x80);
        remaining >>= 6;
    }
    destination[0] = (unsigned char)(((unsigned char*)&DAT_0042b6f0)[length] | remaining);
    *written = length;
    return 0;
}