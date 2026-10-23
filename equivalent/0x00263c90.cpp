// STATUS: equivalent (tools/equiv.py level 3: 16731 inputs, branch coverage 4/4)
// FUN_00263c90 @ 0x00263c90
// FUN_00263c90 @ 0x00263c90: build a unique 64-bit id from the clock and bump it until it is not in the id set
#include "decls/data/engine/unknown.h"

struct Stamp {
    unsigned char b[7];
};

struct Id_263c90 {
    unsigned int lo;
    unsigned int hi;
};

                        // set of ids in use
void __cdecl FUN_00267ad0(Stamp *out);          // current date/time
unsigned int __cdecl FUN_00267f00();            // tick count
int __cdecl FUN_00263970(void *set, Id_263c90 *id);    // find

unsigned __int64 __cdecl FUN_00263c90()
{
    Id_263c90 id;
    Stamp now;

    FUN_00267ad0(&now);
    unsigned int hi = ((unsigned int)now.b[2] << 28) | ((unsigned int)now.b[3] << 23) |
                      ((unsigned int)now.b[4] << 18) | ((unsigned int)now.b[5] << 12) |
                      ((unsigned int)now.b[6] << 6);
    unsigned int lo = FUN_00267f00();
    id.lo = lo;
    id.hi = hi;
    while (FUN_00263970(((int*)&DAT_004cd4cc), &id)) {
        // 64-bit increment kept in registers: the find call overwrites the local
        lo++;
        if (lo == 0)
            hi++;
        id.lo = lo;
        id.hi = hi;
    }
    return ((unsigned __int64)hi << 32) | lo;
}
