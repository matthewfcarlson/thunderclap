// STATUS: equivalent (tools/equiv.py level 3: 121 inputs, branch coverage 24/26, incomplete)
// FUN_0026f3e0 @ 0x0026f3e0
#include "decls/data/platform/xbox/core.h"

unsigned int __stdcall FUN_0026f3e0(unsigned int code)
{
    (*(unsigned int*)&DAT_00528404) = 0;
    if (code <= 17) {
        switch (code) {
        case 0: return 0;
        case 2: case 3: case 15: return 1;
        case 11: return 5;
        case 14: return 8;
        case 17: return 3;
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
