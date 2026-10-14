// STATUS: equivalent (tools/equiv.py level 3: 139 inputs, branch coverage 12/12)
// FUN_002f9690 @ 0x002f9690
// FUN_002f9690: find or claim the slot for an item in a pool of 0x50-byte elements
struct Elem {
    char data[0x50];
};

struct Item {
    char pad00[0x74];
    unsigned int slot;
};

struct Entry {
    Item *owner;
    unsigned int state;
};

struct Pool {
    Elem *elems;
    char pad04[8];
    Entry *begin;
    Entry *end;

    Elem *FUN_002f9690(Item *item);
};

Elem *Pool::FUN_002f9690(Item *item)
{
    if (item == 0)
        return 0;

    unsigned int slot = item->slot;
    if (slot < (unsigned int)(end - begin)) {
        Entry *e = &begin[slot];
        if (e->owner == item) {
            e->state = 0;
            return &elems[slot];
        }
    }

    if (((end - begin) * sizeof(Entry) & 0xfffffff8) == 0)
        return 0;

    Entry *first = begin;
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
