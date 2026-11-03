#include "compat/ptr.h"
#include "gen/owners.h"
extern void __cdecl thunk_FUN_00267090(hulk_intptr);
extern void* __cdecl FUN_0008d6d0(int);
extern void __cdecl FUN_000fb690(void*, const short*, int);
void owners::Obj_f79a0::FUN_000f79a0(const short* text, hulk_intptr unused) {
    mState = -1;
    if (mData != 0) {
        thunk_FUN_00267090((hulk_intptr)mData);
        mData = 0;
    }
    if (text != 0) {
        int n = 0;
        while (text[n] != 0)
            ++n;
        mData = FUN_0008d6d0(n * 2 + 2);
        if (mData == 0)
            return;
        FUN_000fb690(mData, text, n + 1);
    }
    mOther = -1;
}