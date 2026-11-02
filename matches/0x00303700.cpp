#include "compat/ptr.h"
struct E_303700 {
    char d[0x44];
};
extern "C" void __cdecl FUN_00303520(void *, void *, void *);

void G(E_303700* first, E_303700* mid, E_303700* last) {
    hulk_intptr n = last - first;
    if (n > 40) {
        hulk_intptr s = (n + 1) / 8;
        FUN_00303520((E_303700 *)first, (E_303700 *)(first + s), (E_303700 *)(first + s * 2));
        FUN_00303520((E_303700 *)(mid - s), (E_303700 *)mid, (E_303700 *)(mid + s));
        FUN_00303520((E_303700 *)(last - s * 2), (E_303700 *)(last - s), (E_303700 *)last);
        FUN_00303520((E_303700 *)(first + s), (E_303700 *)mid, (E_303700 *)(last - s));
    } else {
        FUN_00303520((E_303700 *)first, (E_303700 *)mid, (E_303700 *)last);
    }
}
