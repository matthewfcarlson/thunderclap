#include "decls/data/game/global.h"
// data: gEntries = DAT_004dc360

struct Entry {
    int a, b, c, d, e, f;
};
void FUN_00044c60(int index, int a, int b, int c, int d, int e, int f) {
    if (index >= 0 && index < 6) {
        ((Entry*)&DAT_004dc360)[index].a = a;
        ((Entry*)&DAT_004dc360)[index].b = b;
        ((Entry*)&DAT_004dc360)[index].c = c;
        ((Entry*)&DAT_004dc360)[index].d = d;
        ((Entry*)&DAT_004dc360)[index].e = e;
        ((Entry*)&DAT_004dc360)[index].f = f;
    }
}