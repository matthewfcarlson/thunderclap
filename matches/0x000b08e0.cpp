#include "decls/data/game/global.h"
// data: gItems = DAT_004ddb68, gZero = DAT_003f335c

struct Item {
    int count;
    int* value;
};
int* __cdecl FUN_000b08e0(int a, int b, int c) {
    if (a >= 0 && a < 2 && b >= 0 && b < 2 && c >= 0 && c < 3) {
        Item* p = &((Item*)&DAT_004ddb68)[(a * 2 + b) * 3 + c];
        if (p->count > 0)
            return p->value;
    }
    return ((int*)&DAT_003f335c);
}