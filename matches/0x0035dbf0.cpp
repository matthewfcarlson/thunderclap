#include "decls/address.h"
#include "decls/data/game/global.h"
// data: g1_35dbf0 = DAT_004de74c
typedef unsigned __int64 int64_35dbf0;
extern int g0;
void FUN_0035dbf0() {
    int64_35dbf0 r = FUN_0027b020("$MACRO_INSERT");
    g0 = (int)r;
    (*(int*)&DAT_004de74c) = (int)(r >> 32);
}
