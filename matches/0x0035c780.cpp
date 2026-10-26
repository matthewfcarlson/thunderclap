#include "decls/address.h"
#include "decls/data/game/global.h"
extern int g0;
void FUN_0035c780() {
    unsigned long long r = FUN_0027b020("apache");
    g0 = (int)r;
    (*(int*)&DAT_004dc0a4) = (int)(r >> 32);
}
