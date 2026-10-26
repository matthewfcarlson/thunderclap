#include "decls/data/engine/unknown.h"
// data: zero_213010 = DAT_00426824

#include "compat/ptr.h"
typedef unsigned int U_213010;
U_213010* __fastcall helper(U_213010, hulk_uintptr);
U_213010 __cdecl combine(U_213010*, U_213010*);
hulk_uintptr __cdecl target(hulk_uintptr a, U_213010 b, U_213010 c) {
    U_213010* x = helper(b, a);
    U_213010* y = helper(c, a);
    if (x != ((U_213010*)&DAT_00426824) && y != ((U_213010*)&DAT_00426824))
        return combine(x, y);
    return 0;
}