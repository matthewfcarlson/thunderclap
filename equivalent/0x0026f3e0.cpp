// STATUS: equivalent (tools/equiv.py level 3: 121 inputs, branch coverage 24/26, incomplete)
// FUN_0026f3e0 @ 0x0026f3e0
#include "decls/data/platform/xbox/core.h"

extern unsigned char DAT_0026f498[];
unsigned int __stdcall FUN_0026f3e0(unsigned int code)
{
    (*(unsigned int*)&DAT_00528404) = 0;
    if (code <= 17) {
        switch (DAT_0026f498[code]) {
        case 0: return 0;
        case 1: return 1;
        case 2: return 5;
        case 3: return 8;
        case 4: return 3;
        default: (*(unsigned int*)&DAT_00528404) = code; return 8;
        }
    }
    switch (code) {
    case 21: return 2;
    case 26: return 11;
    case 27: return 5;
    case 34: return 3;
    case 112: return 7;
    case 1005: return 6;
    case 1167: return 4;
    default: (*(unsigned int*)&DAT_00528404) = code; return 8;
    }
}
