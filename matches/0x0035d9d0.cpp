#include "decls/data/game/global.h"
// data: result = DAT_004de698

struct Pair {
    int a, b;
};
extern Pair __cdecl lookup(const char*);
void FUN_0035d9d0() {
    (*(Pair*)&DAT_004de698) = lookup("GameInstaceLocators");
}