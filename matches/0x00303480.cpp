#include "compat/ptr.h"
struct Item_303480 {
    int v[17];
};
void helper(Item_303480*, int, int, Item_303480);
void target(Item_303480* first, Item_303480* last) {
    hulk_intptr count = last - first;
    hulk_intptr n = count / 2;
    if (n > 0) {
        Item_303480* p = first + n;
        do {
            --n;
            helper(first, n, count, *--p);
        } while (n > 0);
    }
}