// STATUS: equivalent (tools/equiv.py level 3: 301 inputs, branch coverage 12/12)
// FUN_00217c80 @ 0x00217c80
#include "compat/ptr.h"
extern "C" unsigned int __cdecl strlen(const char*);
int __cdecl FUN_003473c6(const char* a, const char* b);
struct TString_217c80 {
    char pad0[0xc];
    unsigned int len;
    char str[1];
};
// equiv-conv: FUN_00217c80 ecx eax
int FUN_00217c80(const TString_217c80* ls, const TString_217c80* rs) {
    const char* l = ls->str;
    unsigned int ll = ls->len;
    const char* r = rs->str;
    unsigned int lr = rs->len;
    for (;;) {
        int temp = FUN_003473c6(l, r);
        if (temp != 0)
            return temp;
        hulk_uintptr len = strlen(l);
        if (len == lr)
            return len != ll;
        if (len == ll)
            return -1;
        len++;
        l += len;
        ll -= len;
        r += len;
        lr -= len;
    }
}
