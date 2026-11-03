// Same code shape as 0x0030d980 (propagated; names are from that function)
#include "gen/owners.h"
struct Sub_30d9b0 {
};
struct Item_30d9b0 {
    char pad[0x10];
    Sub_30d9b0* sub;
};
struct Owner_30d9b0 {
    char pad[4];
    Item_30d9b0* begin;
    Item_30d9b0* end;
    void Target();
};
void Owner_30d9b0::Target() {
    Item_30d9b0* p = begin;
    if (p <= end) {
        do {
            ((owners::Thing_319ef0 *)(p->sub))->FUN_00319ef0();
            Item_30d9b0* old = p;
            p = (Item_30d9b0*)((char*)p + 0x14);
            if (old == end)
                break;
        } while (1);
    }
}