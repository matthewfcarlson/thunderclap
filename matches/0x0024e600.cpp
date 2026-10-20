#include "compat/ptr.h"
#include "decls/data/engine/audio.h"

extern "C" unsigned char __cdecl Check1(int, hulk_intptr, int);
extern "C" unsigned char __cdecl Validate1(hulk_intptr, int);
extern "C" unsigned char __cdecl Final1(hulk_intptr, hulk_intptr);
extern int kTenAddr;
unsigned char Target(int* p, int a, int b) {
    int v = *p;
    unsigned char r = Check1(v, ((hulk_intptr)((char*)&DAT_004298a8)), a);
    if (r) {
        r = Validate1((hulk_intptr)p, b);
        if (r) {
            p = (int*)*p;
            return Final1((hulk_intptr)p, (hulk_intptr)&kTenAddr);
        }
    }
    return 0;
}
