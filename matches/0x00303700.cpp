#include "compat/ptr.h"
struct E_303700 {
    char d[0x44];
};
void F(E_303700* a, E_303700* b, E_303700* c);

void G(E_303700* first, E_303700* mid, E_303700* last) {
    hulk_intptr n = last - first;
    if (n > 40) {
        hulk_intptr s = (n + 1) / 8;
        F(first, first + s, first + s * 2);
        F(mid - s, mid, mid + s);
        F(last - s * 2, last - s, last);
        F(first + s, mid, last - s);
    } else {
        F(first, mid, last);
    }
}
