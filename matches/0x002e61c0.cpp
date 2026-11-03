#include "compat/ptr.h"
void thunk_FUN_00267090(hulk_intptr);
extern "C" void FUN_002e61c0(int* first, int* last) {
    for (; first != last; first += 3) {
        if (*first != 0)
            thunk_FUN_00267090(*first);
    }
}