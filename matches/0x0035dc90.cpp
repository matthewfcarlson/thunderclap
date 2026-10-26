#include "decls/data/game/global.h"
// data: globalPair = DAT_004de7e8

struct Pair {
    unsigned a, b;
};
extern Pair __cdecl getPair(const char*);
void target() {
    (*(Pair*)&DAT_004de7e8) = getPair("$MACRO_INSERT");
}