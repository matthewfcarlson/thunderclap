// STATUS: equivalent (tools/equiv.py level 3: 2049 inputs, branch coverage 7/7)
// FUN_0025e230 @ 0x0025e230
// Register-convention helper: the owner arrives in edi (a link-time-generated convention).
// The original searches for the node's predecessor by walking from the head, but the node it removes
// is always the head (item is derived from the head), so the search never runs and prev is always 0.
// equiv-conv: FUN_0025e230 edi
// equiv-dead: +0x16 not taken, +0x1e taken, +0x1e not taken, +0x22 taken, +0x22 not taken: node is always the head
struct Link {
    Link* next;
};

struct Item {
    int unused[2];
    Link link;
};

struct Pool;
extern Pool DAT_004e7970;
void FUN_00247550(Pool* pool, Item* item);

struct Owner {
    char pad[0x28];
    Link* head;
    Link* tail;
};

void FUN_0025e230(Owner* owner)
{
    for (;;) {
        Link* node = owner->head;
        if (node == 0)
            return;
        Item* item = (Item*)((char*)node - 8);
        if (item == 0)
            return;
        owner->head = node->next;
        if (node->next == 0)
            owner->tail = 0;
        FUN_00247550(&DAT_004e7970, item);
    }
}
