// STATUS: equivalent (tools/equiv.py level 3: 70 inputs, branch coverage 16/16)
// FUN_0029f8c0 @ 0x0029f8c0
#include "decls/data/engine/unknown.h"

struct Rec_29f8c0 {
    int field_00;
    int color;
    char pad[0x18 - 8];
    unsigned flags;
    int field_1c;
};

struct ItemList_29f8c0 {
    char pad0[0x10];
    int limit;
    int count;
    void **items;

    void FUN_002a0fc0(int index, int mode);
    void FUN_002a1180(int index);
};

struct Slots_29f8c0 {
    ItemList_29f8c0 *list;
    Rec_29f8c0 *recs;

    void FUN_0029eda0(int index, void *item);
};

struct Owner_29f8c0;

struct Owner_29f8c0 {
    char pad[0x24];
    int removed;

    Slots_29f8c0 *FUN_0029c450(void *key);
    void FUN_0029f8c0(void *key);
};

void Owner_29f8c0::FUN_0029f8c0(void *key)
{
    if (key == 0)
        return;

    Slots_29f8c0 *s = FUN_0029c450(key);

    for (int i = s->list->count - 1; i >= 0; i--) {
        ItemList_29f8c0 *l = s->list;
        void *item = (i < l->limit) ? l->items[i] : 0;
        if (item != key)
            continue;

        int last = l->count - 1;
        if (i == last) {
            l->FUN_002a0fc0(i, 0);
            s->recs[i].field_00 = 0;
            s->recs[i].color = DAT_004cf730;
            s->recs[i].field_1c = 0;
            s->recs[i].flags = 0;
        } else {
            void *lastItem = (last < l->limit) ? l->items[last] : 0;
            s->FUN_0029eda0(i, lastItem);
            if (s->recs[last].flags & 8)
                s->recs[i].flags |= 8;
            else
                s->recs[i].flags &= ~8u;
            s->list->FUN_002a0fc0(last, 0);
            s->recs[last].field_00 = 0;
            s->recs[last].color = DAT_004cf730;
            s->recs[last].field_1c = 0;
            s->recs[last].flags = 0;
        }
        s->list->FUN_002a1180(last);
        removed++;
    }
}
