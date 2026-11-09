// STATUS: equivalent (tools/equiv.py level 3: 71 inputs, branch coverage 26/32, incomplete)
// numuse: count a table's used slots and integer keys per power of 2; the array and hash sizes to resize to.
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_00215f70(unsigned int x);
// equiv-conv: FUN_002199d0 edx stack stack stack
extern "C" void __cdecl FUN_002199d0(int* nums, int ntotal, int* narray, int* nhash);

extern "C" void __cdecl FUN_00219a60(const LuaVMTable* t, int* narray, int* nhash) {
    int nums[25];
    int totaluse = 0;
    int i = 0;
    int sizearray = t->sizearray;
    int lg = 0;
    for (; lg <= 24; lg++) {
        int lim = 1 << lg;
        if (lim > sizearray) {
            lim = sizearray;
            if (i >= lim)
                break;
        }
        nums[lg] = 0;
        if (i < lim) {
            const LuaVMTObject* p = t->array + i;
            int cnt = lim - i;
            i += cnt;
            do {
                if (p->tt != LUAVM_TNIL) {
                    nums[lg]++;
                    totaluse++;
                }
                p++;
            } while (--cnt != 0);
        }
    }
    for (; lg <= 24; lg++)
        nums[lg] = 0;

    *narray = totaluse;
    int sizenode = 1 << t->lsizenode;
    float limit = (float)(2 * (sizenode + totaluse));
    if (!(limit < 16777216.0f))
        limit = 16777216.0f;
    for (int n = sizenode; n != 0; n--) {
        const LuaVMNode* nd = &t->node[n - 1];
        if (nd->i_val.tt == LUAVM_TNIL)
            continue;
        if (nd->i_key.tt == LUAVM_TNUMBER) {
            float k = nd->i_key.value.n;
            if (!(k <= 0.0f) && !(k > limit)) {
                int ki = (int)k;
                if ((float)ki == k && ki >= 0) {
                    int b = FUN_00215f70((unsigned int)(ki - 1));
                    nums[b + 1] = nums[b + 1] + 1;
                    (*narray)++;
                }
            }
        }
        totaluse++;
    }
    FUN_002199d0(nums, totaluse, narray, nhash);
}
