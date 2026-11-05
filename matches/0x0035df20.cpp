#include "decls/data/game/global.h"

struct Pair_35df20 {
    int lo;
    int hi;
};
unsigned __int64 FUN_0027b020(const char* s);
void __cdecl FUN_0035df20() {
    unsigned __int64 r = FUN_0027b020("$MACRO_DEFINE");
    *(int*)((char*)&DAT_004e09c8) = (int)r;
    *(int*)((char*)&DAT_004e09cc) = (int)(r >> 32);
}
