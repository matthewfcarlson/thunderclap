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
void FUN_0033ed90(TwiddleTable_343e10 *t, int n, float *w);
// equiv-conv: FUN_0033eef0 eax edx esi
void FUN_0033eef0(TwiddleTable_343e10 *t, int n, float *w);
// equiv-conv: FUN_00343bb0 eax ecx stack stack stack
void __cdecl FUN_00343bb0(float *w, float *pair, int n, float *tw, int off);
// equiv-conv: FUN_00343ce0 eax ecx stack stack stack
void __cdecl FUN_00343ce0(float *w, float *pair, int n, float *tw, int off);
// equiv-conv: FUN_00342d90 eax esi stack stack
void __cdecl FUN_00342d90(float *w, float *pair, int n, int x);
// equiv-conv: FUN_00342e50 eax esi stack stack
void __cdecl FUN_00342e50(float *w, float *pair, int n, int x);

void __stdcall FUN_00343e10(int n, int sign, float *pair, TwiddleTable_343e10 *t, float *w)
{
    int off = t->size0;
    if (n > off * 4) {
        off = n >> 2;
        FUN_0033ed90(t, off, w);
    }
    int half = t->size1;
    if (n > half * 4) {
        half = n >> 2;
        FUN_0033eef0(t, half, w + off);
    }
    if (sign >= 0) {
        if (n > 4) {
            FUN_00343bb0(w, pair, n, t->data, off);
            FUN_00342d90(w + off, pair, n, half);
        } else if (n == 4) {
            FUN_00343bb0(w, pair, 4, t->data, off);
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
            FUN_00343ce0(w, pair, n, t->data, off);
        } else if (n == 4) {
            FUN_00343ce0(w, pair, 4, t->data, off);
        }
    }
}
