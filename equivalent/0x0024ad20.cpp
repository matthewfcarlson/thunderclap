// STATUS: equivalent (tools/equiv.py level 3: 81 inputs, branch coverage 24/24)
// FUN_0024ad20 @ 0x0024ad20
#include "decls/data/engine/audio.h"

struct Child;

struct List;

struct Sub {
    char pad[0x14];
    char inner;
};

struct Node1 {
    Node1 *next;
    char pad[0x10 - 4];
    Child *children;
};

struct List1 {
    Node1 *first;
    Node1 *last;
};

struct Node2 {
    Node2 *next;
    char pad0[0x3c - 4];
    int value3c;
    int value40;
    char pad1[0x50 - 0x44];
    Sub sub50;
};

struct List2 {
    Node2 *first;
    Node2 *last;
};

struct SNode {
    SNode *next;
    int payload;
};

struct Owner {
    char pad[0x22];
    unsigned short count;
};

struct Pool {
    char pad[1];
};

// equiv-conv: FUN_00249750 esi
void FUN_00249750(Child *c);
void FUN_00248ac0(List1 *list, Node1 *node);
void FUN_00249ec0(List2 *list, Node2 *node);
void FUN_00247550(void *pool, void *block);
void FUN_0024a450(void *list);
void FUN_0024a4a0(void *list);
void FUN_00257f00(void *a, void *b);
void FUN_00242d70(void *a, int b);

struct Registry {
    char pad0[0x18];
    List1 list1;
    char pad1[0x2c - 0x20];
    Owner *owner;
    char pad2[0x3c - 0x30];
    SNode *head;
    SNode *tail;
    void *pool44;
    List2 list2;
    char pad3[0x5c - 0x50];
    Sub sub5c;

    void FUN_0024ad20();
};

void Registry::FUN_0024ad20()
{
    for (;;) {
        Node1 *n = list1.first;
        Node1 *end = (Node1 *)&list1.last;
        if (n == end)
            break;
        while (n->next != end)
            n = n->next;
        Child *c;
        while ((c = n->children) != 0)
            FUN_00249750(c);
        FUN_00248ac0(&list1, n);
        FUN_00247550(((char*)&DAT_004e5ff0), n);
    }

    for (;;) {
        Node2 *n = list2.first;
        Node2 *end = (Node2 *)&list2.last;
        if (n == end)
            break;
        while (n->next != end)
            n = n->next;
        FUN_00249ec0(&list2, n);
        FUN_00247550(((char*)((char*)&DAT_004e6110 + 72)), (void *)n->value40);
        FUN_00247550(((char*)&DAT_004e6110), (void *)n->value3c);
        FUN_0024a450(&n->sub50.inner);
        FUN_0024a4a0(&n->sub50);
        FUN_00247550(((char*)&DAT_004e60c8), n);
    }

    FUN_00257f00(((char*)&DAT_004e5f98), this);

    SNode *s;
    while ((s = head) != 0) {
        FUN_00242d70(pool44, s->payload);
        SNode *prev = 0;
        SNode *cur = head;
        if (cur != s) {
            do {
                prev = cur;
                cur = cur->next;
            } while (cur != s);
        }
        if (prev == 0)
            head = s->next;
        else
            prev->next = s->next;
        if (s->next == 0)
            tail = prev;
        FUN_00247550(((char*)&DAT_004e6080), s);
    }

    owner->count--;
    FUN_0024a450(&sub5c.inner);
    FUN_0024a4a0(&sub5c);
}
