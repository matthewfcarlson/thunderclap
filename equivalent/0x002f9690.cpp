// STATUS: equivalent (tools/equiv.py level 3: 139 inputs, branch coverage 12/12)
// FUN_002f9690 @ 0x002f9690
// FUN_002f9690: find or claim the slot for an item in a pool of 0x50-byte elements
struct Elem_2f9690 {
    char data[0x50];
};

struct Item_2f9690 {
    char pad00[0x74];
    unsigned int slot;
};

struct Entry_2f9690 {
    Item_2f9690 *owner;
    unsigned int state;
};

struct Pool_2f9690 {
    Elem_2f9690 *elems;
    char pad04[8];
    Entry_2f9690 *begin;
    Entry_2f9690 *end;

    Elem_2f9690 *FUN_002f9690(Item_2f9690 *item);
};

Elem_2f9690 *Pool_2f9690::FUN_002f9690(Item_2f9690 *item)
{
    if (item == 0)
        return 0;

    unsigned int slot = item->slot;
    if (slot < (unsigned int)(end - begin)) {
        Entry_2f9690 *e = &begin[slot];
        if (e->owner == item) {
            e->state = 0;
            return &elems[slot];
        }
    }

    if (((end - begin) * sizeof(Entry_2f9690) & 0xfffffff8) == 0)
        return 0;

    Entry_2f9690 *first = begin;
    unsigned int i = 0;
    do {
        if (first[i].state > 2) {
            first[i].owner = item;
            item->slot = i;
            begin[i].state = 0;
            return &elems[i];
        }
        i++;
    } while (i != (unsigned int)(end - begin));
    return 0;
}
