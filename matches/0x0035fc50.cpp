#include "decls/data/engine/unknown.h"

struct Pair {
    unsigned int a;
    unsigned int b;
};
unsigned __int64 FUN_002672f0(const char* s, int a, int b);
void __cdecl FUN_0035fc50() {
    unsigned __int64 p = FUN_002672f0("Template", 0, 0);
    (*(unsigned int*)&DAT_004e6350) = (unsigned int)p;
    (*(unsigned int*)&DAT_004e6354) = (unsigned int)(p >> 32);
}
