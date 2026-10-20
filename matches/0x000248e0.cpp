#include "compat/ptr.h"
extern char gEmpty_248e0;
struct Sub_248e0 {
    void* Lookup(int);
};
struct Item_248e0 {
    void* Get();
};
struct Owner_248e0 {
    char pad[0x44];
    Sub_248e0* sub;
};
struct Thing_248e0 {
    Owner_248e0* owner;
    char pad[8];
    int count;
    int items[69];
    int excluded;
    void* run(int);
};
void* Thing_248e0::run(int index) {
    if (index < 0 || index >= count)
        return &gEmpty_248e0;
    int found = 0, i = 0;
    if (count > 0) {
        int* p = items;
        do {
            Sub_248e0* s = owner->sub;
            Item_248e0* v = (Item_248e0*)s->Lookup(*p);
            if (v && (hulk_intptr)v != excluded) {
                if (found == index)
                    return v->Get();
                ++found;
            }
            ++i;
            ++p;
        } while (i < count);
    }
    return &gEmpty_248e0;
}
