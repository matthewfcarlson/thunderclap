#include "decls/data/game/global.h"
#include "gen/owners.h"

extern int __cdecl FUN_00212f00(int, int);
extern float __cdecl FUN_002130e0(int, int);
extern "C" int __cdecl FUN_00213160(int, int);
extern void __cdecl FUN_00212d80(int, int);
unsigned char owners::Owner_1d1ae0::FUN_001d1ae0(unsigned char* out) {
    unsigned char result = 1;
    int x = FUN_00212f00(value, -1);
    switch (x) {
    case 0:
        *out = 0;
        break;
    case 1:
        *out = FUN_00213160(value, -1) != 0;
        break;
    case 3: {
        int b;
        if ((*(float*)&DAT_003f32e0) != FUN_002130e0(value, -1))
            b = 1;
        else
            b = 0;
        *out = b;
        break;
    }
    default:
        result = 0;
        break;
    }
    FUN_00212d80(value, -2);
    return result;
}