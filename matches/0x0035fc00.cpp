#include "decls/data/engine/unknown.h"

struct Pair {
    int a, b;
};
extern Pair __cdecl Make(const char*, int, int);
void FUN_0035fc00() {
    (*(Pair*)&DAT_004e6340) = Make("Template", 0, 0);
}