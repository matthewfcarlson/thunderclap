// STATUS: equivalent (tools/equiv.py level 3: 91 inputs, branch coverage 6/6)
// FUN_0033ed20 @ 0x0033ed20
#include "decls/data/engine/unknown.h"

typedef unsigned int uint;
extern uint __stdcall FUN_0033eb90(uint);
uint __stdcall FUN_0033ed20(uint size)
{
    uint aligned = (size + 31) & ~31u;
    uint base = FUN_0033eb90((*(uint*)&DAT_00566200) + aligned);
    (*(uint*)&DAT_00566200) = 0;
    if (base != 0 && (*(uint*)&DAT_00566204) != 0) {
        uint offset = (uint)(*(uint**)&DAT_004d9858) - (uint)(*(uint**)&DAT_004d985c);
        uint *entry = (*(uint**)&DAT_004d985c);
        uint address = base + aligned;
        uint count = (*(uint*)&DAT_00566204);
        do {
            *(uint *)*(uint *)((char *)entry + offset) = address;
            address += *entry++;
        } while (--count != 0);
    }
    (*(uint*)&DAT_00566204) = 0;
    return base;
}