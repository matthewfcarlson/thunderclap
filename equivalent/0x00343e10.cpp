// STATUS: equivalent (tools/equiv.py level 3: 20010 inputs, branch coverage 14/14)
// FUN_00343e10 @ 0x00343e10
// FUN_00343e10 @ 0x00343e10
#include "compat/ptr.h"
struct TwiddleTable_343e10 {
    int size0;
    int size1;
    float data[1];
};

// equiv-conv: FUN_0033ed90 eax ecx edi
extern "C" void __cdecl FUN_0033ed90(void *, int, float *);
// equiv-conv: FUN_0033eef0 eax edx esi
extern "C" void __cdecl FUN_0033eef0(void *, int, float *);
// equiv-conv: FUN_00343bb0 eax ecx stack stack stack
extern "C" void __cdecl FUN_00343bb0(float *, float *, int, int *, int);
// equiv-conv: FUN_00343ce0 eax ecx stack stack stack
extern "C" void __cdecl FUN_00343ce0(float *, float *, int, int *, int);
// equiv-conv: FUN_00342d90 eax esi stack stack
extern "C" void __cdecl FUN_00342d90(float *, float *, int, int);
// equiv-conv: FUN_00342e50 eax esi stack stack
extern "C" void __cdecl FUN_00342e50(float *, float *, int, int);

void __stdcall FUN_00343e10(int n, int sign, float *pair, TwiddleTable_343e10 *t, float *w)
{
    int off = t->size0;
    if (n > off * 4) {
        off = n >> 2;
        FUN_0033ed90((TwiddleTable_343e10 *)t, off, w);
    }
    int half = t->size1;
    if (n > half * 4) {
        half = n >> 2;
        FUN_0033eef0((TwiddleTable_343e10 *)t, half, w + off);
    }
    if (sign >= 0) {
        if (n > 4) {
            FUN_00343bb0(w, pair, n, (int *)(float *)(t->data), off);
            FUN_00342d90(w + off, pair, n, half);
        } else if (n == 4) {
            FUN_00343bb0(w, pair, 4, (int *)(float *)(t->data), off);
        }
        hulk_freg d = pair[0] - pair[1];
        pair[0] = pair[0] + pair[1];
        pair[1] = d;
    } else {
        hulk_freg d = (pair[0] - pair[1]) * 0.5f;
        pair[1] = d;
        pair[0] = pair[0] - d;
        if (n > 4) {
            FUN_00342e50(w + off, pair, n, half);
            FUN_00343ce0(w, pair, n, (int *)(float *)(t->data), off);
        } else if (n == 4) {
            FUN_00343ce0(w, pair, 4, (int *)(float *)(t->data), off);
        }
    }
}
