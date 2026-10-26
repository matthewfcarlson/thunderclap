#include "decls/data/game/global.h"
// data: result = DAT_004de6d8

struct Pair {
    int a;
    int b;
};
extern Pair __cdecl Find(const char*);
void FUN_0035daf0() {
    (*(Pair*)&DAT_004de6d8) = Find("ClearAfterEntry");
}