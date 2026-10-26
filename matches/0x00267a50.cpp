#include "decls/data/engine/unknown.h"
// data: count = DAT_00528378, first = DAT_00528380, second = DAT_00528384

void __stdcall FUN_00354ce2(int*);
void FUN_00267a50() {
    (*(int*)&DAT_00528378)++;
    if ((*(int*)&DAT_00528378) == 1) {
        int local[2];
        FUN_00354ce2(local);
        (*(int*)&DAT_00528380) = local[0];
        (*(int*)&DAT_00528384) = local[1];
    }
}