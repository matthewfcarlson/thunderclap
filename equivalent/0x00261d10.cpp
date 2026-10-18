// STATUS: equivalent (tools/equiv.py level 3: 2019 inputs, branch coverage 7/7)
// FUN_00261d10 @ 0x00261d10
// The original searches for the node's predecessor by walking from the head, but the node it removes
// is always the head (item is derived from list->head), so the search never runs and prev is always 0.
// equiv-dead: +0x1a not taken, +0x26 taken, +0x26 not taken, +0x2a taken, +0x2a not taken: node is always the head
struct Link {
    Link* next;
};

struct Item {
    int unused;
    Link link;
};

struct List {
    Link* head;
    Link* tail;
};

struct Pool;
extern Pool DAT_004e7a30;
void FUN_00247550(Pool* pool, Item* item);

void FUN_00261d10(List* list)
{
    for (;;) {
        Link* node = list->head;
        if (node == 0)
            return;
        Item* item = (Item*)((char*)node - 4);
        if (item == 0)
            return;
        list->head = node->next;
        if (node->next == 0)
            list->tail = 0;
        FUN_00247550(&DAT_004e7a30, item);
    }
}
