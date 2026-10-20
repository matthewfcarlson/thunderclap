#include "compat/ptr.h"
void FUN_00304370(hulk_intptr, hulk_intptr, int);
struct Thing_304500 {
    int* a;
    int* b;
};
void __fastcall FUN_00304500(Thing_304500* p) {
    int* s = p->b;
    int* d = p->a;
    FUN_00304370((hulk_intptr)d, (hulk_intptr)s, (int)(((char*)s - (char*)d) / 0x44));
}