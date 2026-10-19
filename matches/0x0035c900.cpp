#include "decls/address.h"
extern "C" char hulk_at_003f3fd8[];
typedef unsigned __int64 U64_35c900;
extern int gA_35c900;
extern int gB_35c900;
void FUN_0035c900() {
    U64_35c900 r = FUN_0027b020((const char*)((int)hulk_at_003f3fd8));
    gA_35c900 = (int)r;
    gB_35c900 = (int)(r >> 32);
}
