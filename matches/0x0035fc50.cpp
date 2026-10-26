#include "decls/data/engine/unknown.h"

struct Pair {
    unsigned int a;
    unsigned int b;
};
extern "C" Pair __cdecl Hash(const char*, unsigned int, unsigned int);
void __cdecl FUN_0035fc50() {
    Pair p = Hash("Template", 0, 0);
    (*(unsigned int*)&DAT_004e6350) = p.a;
    (*(unsigned int*)&DAT_004e6354) = p.b;
}
