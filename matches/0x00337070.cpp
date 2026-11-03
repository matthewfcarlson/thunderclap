#include "gen/owners.h"
void owners::Obj_337070::FUN_00337070(char* s) {
    char* dst = (char*)this + 4;
    char* p = s;
    char c;
    do {
        c = *p;
        *(dst + (p - s)) = c;
        ++p;
    } while (c);
}
