#include "decls/data/game/global.h"
// data: result = DAT_004dcee0

struct Pair {
    int a;
    int b;
};
extern Pair __cdecl lookup(const char*);
void __cdecl FUN_0035ca30() {
    (*(Pair*)&DAT_004dcee0) = lookup("squad");
}