#include "gen/owners.h"
struct Item_f78f0 {
    unsigned int a, b, c, d;
};
void owners::X_f78f0::FUN_000f78f0() {
    if (count < 7) {
        Item_f78f0* p = (Item_f78f0*)((char*)this + count * 16);
        Item_f78f0* q = (Item_f78f0*)((char*)p + 16);
        *q = *p;
        ++count;
    }
}
