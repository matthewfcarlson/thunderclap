#include "decls/data/engine/unknown.h"
// data: gNames = DAT_00426bf0

char* __cdecl Make(void* a, const char* b, int c);
void __cdecl Target(void* param) {
    int i = 0;
    do {
        const char* p = ((const char* const*)&DAT_00426bf0)[i];
        const char* e = p + 1;
        char c;
        do {
            c = *p;
            p++;
        } while (c != 0);
        char* r = Make(param, ((const char* const*)&DAT_00426bf0)[i], (int)(p - e));
        r[5] |= 0x20;
        r[6] = (char)(i + 1);
        i++;
    } while (i < 21);
}
