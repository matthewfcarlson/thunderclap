#include "compat/ptr.h"
struct Item_2f9ff0 {
    void f(int);
};
extern "C" int __cdecl FUN_002f9ff0(Item_2f9ff0* p, int count, int b) {
    if (count != 0) {
        int n = count;
        Item_2f9ff0* q = p;
        do {
            if (q)
                q->f(b);
            q = (Item_2f9ff0*)((char*)q + 0x50);
            --n;
        } while (n != 0);
        return (hulk_intptr)q;
    }
    return (hulk_intptr)p;
}
