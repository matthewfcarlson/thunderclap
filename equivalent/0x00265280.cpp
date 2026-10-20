// STATUS: equivalent (tools/equiv.py level 3: 50 inputs, branch coverage 12/12)
// FUN_00265280 @ 0x00265280
#include "compat/ptr.h"
struct Item_265280 {
    virtual void unused();
    virtual void release();
    void FUN_00266950(int);
};
struct Owner_265280 { void FUN_002666e0(); };
struct Entry_265280 { Item_265280* item; unsigned value; };
struct Queue_265280 {
    char pad0[8];
    Owner_265280* owner;
    char padC[8];
    Entry_265280* read;
    Entry_265280* write;
    Entry_265280* begin;
    Entry_265280* end;
    void clear();
};
void Queue_265280::clear() {
    for (;;) {
        unsigned count;
        if ((hulk_uintptr)read <= (hulk_uintptr)write)
            count = ((int)((hulk_uintptr)write - (hulk_uintptr)read)) >> 3;
        else
            count = (((int)((hulk_uintptr)write - (hulk_uintptr)begin)) >> 3) + (((int)((hulk_uintptr)end - (hulk_uintptr)read)) >> 3);
        if (!count) break;
        Item_265280* item = read->item;
        unsigned value = read->value;
        if ((hulk_uintptr)write >= (hulk_uintptr)end) write = read;
        ++read;
        if (read == end) read = begin;
        if (item) {
            item->FUN_00266950(4);
            item->release();
        }
    }
    if (owner) owner->FUN_002666e0();
}
