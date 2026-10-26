#include "decls/data/game/global.h"

bool __cdecl FUN_00085d90() {
    int sum = 0;
    signed char c = DAT_0049bfc8[0];
    if (c) {
        const signed char* text = (const signed char*)DAT_0049bfc8;
        do {
            sum += c;
            ++text;
            c = *text;
        } while (c);
    }
    return sum == DAT_0049c0c8;
}