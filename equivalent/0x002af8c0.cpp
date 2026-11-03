// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_002af8c0 @ 0x002af8c0
#include "gen/owners.h"
struct Reader {
    char pad00[0xc];
    char open;
    char pad0d;
    char binary;
    char pad0f[0x11];
};

struct Header_2af8c0 {
    unsigned magic;
    unsigned char b4, b5, b6, b7;
    unsigned w8, wc, w10, w14;
    unsigned short s18, s1a;
    unsigned w1c, w20, w24, w28, w2c, w30;
};

// equiv-conv: FUN_002af8c0 esi edi
extern "C" void FUN_002af8c0(void *h, void *r)
{
    unsigned tmp;

    ((char)((owners::X_2647e0 *)(((Reader *)r)))->FUN_002647e0((hulk_intptr)(&tmp), (hulk_intptr)1, 4, (hulk_intptr)1)); ((Header_2af8c0 *)h)->magic = tmp;
    ((char)((owners::X_2647e0 *)(((Reader *)r)))->FUN_002647e0((hulk_intptr)(&tmp), (hulk_intptr)1, 1, (hulk_intptr)1)); ((Header_2af8c0 *)h)->b4 = (unsigned char)tmp;
    ((char)((owners::X_2647e0 *)(((Reader *)r)))->FUN_002647e0((hulk_intptr)(&tmp), (hulk_intptr)1, 1, (hulk_intptr)1)); ((Header_2af8c0 *)h)->b5 = (unsigned char)tmp;
    ((char)((owners::X_2647e0 *)(((Reader *)r)))->FUN_002647e0((hulk_intptr)(&tmp), (hulk_intptr)1, 1, (hulk_intptr)1)); ((Header_2af8c0 *)h)->b6 = (unsigned char)tmp;
    ((char)((owners::X_2647e0 *)(((Reader *)r)))->FUN_002647e0((hulk_intptr)(&tmp), (hulk_intptr)1, 1, (hulk_intptr)1)); ((Header_2af8c0 *)h)->b7 = (unsigned char)tmp;
    ((char)((owners::X_2647e0 *)(((Reader *)r)))->FUN_002647e0((hulk_intptr)(&tmp), (hulk_intptr)1, 4, (hulk_intptr)1)); ((Header_2af8c0 *)h)->w8 = tmp;
    ((char)((owners::X_2647e0 *)(((Reader *)r)))->FUN_002647e0((hulk_intptr)(&tmp), (hulk_intptr)1, 4, (hulk_intptr)1)); ((Header_2af8c0 *)h)->wc = tmp;
    ((char)((owners::X_2647e0 *)(((Reader *)r)))->FUN_002647e0((hulk_intptr)(&tmp), (hulk_intptr)1, 4, (hulk_intptr)1)); ((Header_2af8c0 *)h)->w10 = tmp;
    ((char)((owners::X_2647e0 *)(((Reader *)r)))->FUN_002647e0((hulk_intptr)(&tmp), (hulk_intptr)1, 4, (hulk_intptr)1)); ((Header_2af8c0 *)h)->w14 = tmp;
    ((char)((owners::X_2647e0 *)(((Reader *)r)))->FUN_002647e0((hulk_intptr)(&tmp), (hulk_intptr)1, 2, (hulk_intptr)1)); ((Header_2af8c0 *)h)->s18 = (unsigned short)tmp;
    ((char)((owners::X_2647e0 *)(((Reader *)r)))->FUN_002647e0((hulk_intptr)(&tmp), (hulk_intptr)1, 2, (hulk_intptr)1)); ((Header_2af8c0 *)h)->s1a = (unsigned short)tmp;
    ((char)((owners::X_2647e0 *)(((Reader *)r)))->FUN_002647e0((hulk_intptr)(&tmp), (hulk_intptr)1, 4, (hulk_intptr)1)); ((Header_2af8c0 *)h)->w1c = tmp;
    ((char)((owners::X_2647e0 *)(((Reader *)r)))->FUN_002647e0((hulk_intptr)(&tmp), (hulk_intptr)1, 4, (hulk_intptr)1)); ((Header_2af8c0 *)h)->w20 = tmp;
    ((char)((owners::X_2647e0 *)(((Reader *)r)))->FUN_002647e0((hulk_intptr)(&tmp), (hulk_intptr)1, 4, (hulk_intptr)1)); ((Header_2af8c0 *)h)->w24 = tmp;
    ((char)((owners::X_2647e0 *)(((Reader *)r)))->FUN_002647e0((hulk_intptr)(&tmp), (hulk_intptr)1, 4, (hulk_intptr)1)); ((Header_2af8c0 *)h)->w28 = tmp;
    ((char)((owners::X_2647e0 *)(((Reader *)r)))->FUN_002647e0((hulk_intptr)(&tmp), (hulk_intptr)1, 4, (hulk_intptr)1)); ((Header_2af8c0 *)h)->w2c = tmp;
    ((char)((owners::X_2647e0 *)(((Reader *)r)))->FUN_002647e0((hulk_intptr)(&tmp), (hulk_intptr)1, 4, (hulk_intptr)1)); ((Header_2af8c0 *)h)->w30 = tmp;
}
