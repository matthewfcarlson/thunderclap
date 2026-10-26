#include "decls/data/engine/fight.h"

struct R64 {
    int lo;
    int hi;
};
extern R64 __cdecl FUN_002672f0(int, int, int);
void __cdecl FUN_0035f070() {
    R64 r = FUN_002672f0((*(int*)&DAT_004ca260), 0, 0);
    (*(int*)&DAT_004e5ba8) = r.lo;
    (*(int*)((char*)&DAT_004e5ba8 + 4)) = r.hi;
}
