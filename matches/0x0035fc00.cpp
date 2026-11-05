#include "decls/data/engine/unknown.h"

struct Pair {
    int a, b;
};
extern Pair __cdecl FUN_002672f0(const char*, int, int);
void FUN_0035fc00() {
    (*(Pair*)&DAT_004e6340) = FUN_002672f0("Template", 0, 0);
}