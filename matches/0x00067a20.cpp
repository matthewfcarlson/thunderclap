#include "gen/owners.h"
struct Item_67a20 {
    void tick();
};
void owners::C_67a20::FUN_00067a20() {
    Item_67a20* p = (Item_67a20*)((char*)this + 0x920);
    int i = 0x40;
    do {
        p = (Item_67a20*)((char*)p - 0x20);
        p->tick();
        --i;
    } while (i != 0);
}