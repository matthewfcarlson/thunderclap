// STATUS: equivalent (tools/equiv.py level 3: 82 inputs, branch coverage 10/12, incomplete)
// FUN_00271cf0 @ 0x00271cf0
#include "decls/data/engine/core.h"

int __cdecl FUN_00271cf0(char *destination, const unsigned char *source, unsigned int capacity)
{
    unsigned int written = 0;
    while (source[written] != 0) {
        unsigned int count = (int)((signed char*)&DAT_0042b6f8)[source[written]] + 1;
        if (written + count + 1 > capacity)
            break;
        for (unsigned int i = 0; i < count; ++i) {
            const unsigned char *current = source + written + i;
            if (current == 0)
                return -1;
            destination[written + i] = *current;
        }
        written += count;
    }
    destination[written] = 0;
    return written;
}