#include "compat/ptr.h"
#include "gen/owners.h"
extern "C" void* Alloc(hulk_uintptr);
void owners::Buffer_2ede00::FUN_002ede00(int n) {
    if (n != 0) {
        void* q = Alloc(n * 4);
        p = q;
        if (q != 0) {
            end = (char*)q + n * 4;
            begin = q;
            return;
        }
    } else {
        p = 0;
    }
    begin = 0;
    end = 0;
}