#include "decls/data/engine/audio.h"
// data: gPair = DAT_004e5f90

struct Pair {
    int a;
    int b;
};
extern Pair __cdecl FUN_002672f0(const char*, int, int);
void FUN_0035f560() {
    (*(Pair*)&DAT_004e5f90) = FUN_002672f0("Unknown", 0, 0);
}