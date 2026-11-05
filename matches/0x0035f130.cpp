#include "decls/data/engine/fight.h"
// data: result = DAT_004e5b40, source = DAT_004ca278

unsigned __int64 FUN_002672f0(const char* s, int a, int b);
void __cdecl FUN_0035f130() {
    unsigned __int64 r = FUN_002672f0((*(const char**)&DAT_004ca278), 0, 0);
    (*(unsigned int*)&DAT_004e5b40) = (unsigned int)r;
    (*(unsigned int*)&DAT_004e5b44) = (unsigned int)(r >> 32);
}
