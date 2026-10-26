#include "decls/address.h"
#include "decls/data/game/hulkfight/motion.h"
typedef unsigned long long U64_35e440;
void FUN_0035e440() {
    U64_35e440 r = FUN_0027b020("drop");
    (*(int*)&DAT_004e13e0) = (int)r;
    (*(int*)((char*)&DAT_004e13e0 + 4)) = (int)(r >> 32);
}
