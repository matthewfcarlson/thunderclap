// STATUS: equivalent (tools/equiv.py level 3: 354 inputs, branch coverage 10/10)
// FUN_00242ec0 @ 0x00242ec0
struct Link {
    Link *next;
    Link *prev;
};

struct Owner {
    char pad0[0x10];
    Link *head;             // 0x10
    Link *tail;             // 0x14
    char pad18[4];
    unsigned int refs;      // 0x1c
};

struct Node {
    Node *chain;            // 0x0 (next node to release)
    char pad4[4];
    Link *next;             // 0x8
    Link *prev;             // 0xc
    char pad10[8];
    Owner *owner;           // 0x18
};

struct Container {
    char pad0[0x18];
    Node *first;            // 0x18
    int count;              // 0x1c
};

extern char DAT_004e5e40;
extern char DAT_004e5e88;
void __cdecl FUN_00242680(int arg, Owner *owner);
void __cdecl FUN_00247550(void *pool, void *item);

void __cdecl FUN_00242ec0(int arg, Container *list)
{
    Node *node = list->first;
    while (node != 0) {
        Node *current = node;
        Owner *owner = current->owner;
        if (current->prev == 0)
            owner->head = current->next;
        else
            current->prev->next = current->next;
        if (current->next == 0)
            owner->tail = current->prev;
        else
            current->next->prev = current->prev;

        owner = current->owner;
        if (owner->refs > 1) {
            owner->refs--;
        } else {
            FUN_00242680(arg, owner);
            FUN_00247550(&DAT_004e5e88, owner);
        }
        node = current->chain;
        FUN_00247550(&DAT_004e5e40, current);
    }
    list->first = 0;
    list->count = 0;
}
