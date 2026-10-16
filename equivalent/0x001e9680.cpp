// STATUS: equivalent (tools/equiv.py level 3: 51 inputs, branch coverage 28/28)
// FUN_001e9680 @ 0x001e9680
#include "decls/data/engine/content.h"
#include "decls/data/game/global.h"

void __cdecl FUN_0008d340(void *p);
void __cdecl FUN_0008d330(void *p);

struct Counted_1e9680 {
    char pad0[0xc];
    int refs;
};

class Item_1e9680 {
public:
    virtual void v0();
    virtual void v1();
    virtual void Destroy(int freeMemory);
    char pad04[0x20];
    int users;
    char pad28[4];
    Counted_1e9680 *list[0x40];
    int listCount;
};

struct Node {
    char pad0[0x34];
    void *next;
};

class Entry_1e9680 {
public:
    virtual void v0();
    virtual void v1();
    virtual void Destroy(int freeMemory);
    char pad04[8];
    Node *node;
};

void *__cdecl FUN_00240750();
void __cdecl FUN_002416c0(void *a, Node *node, int flag);
void __cdecl FUN_00243090(void *a, float f);
void __cdecl FUN_00242ca0(void *a, Node **node);

class Manager_1e9680;

struct Renderer_1e9680 {
    void FUN_00265560(Manager_1e9680 *m);
};
void __cdecl FUN_00240eb0();
void __cdecl FUN_00240a10();

class Manager_1e9680 {
public:
    char pad0[8];
    Item_1e9680 *items[100];
    int itemCount;
    void *blocks[200];
    int blockCount;
    Entry_1e9680 *entries[20];
    int entryCount;
    void FUN_001e9680();
};

void Manager_1e9680::FUN_001e9680()
{
    FUN_0008d340((*(void**)&DAT_004e2788));
    for (int i = 0; i < itemCount; i++) {
        Item_1e9680 *item = items[i];
        if (item->users > 0) {
            for (int j = 0; j < item->listCount; j++) {
                Counted_1e9680 *c = item->list[j];
                if (c != 0)
                    c->refs--;
            }
            item->users--;
        }
        if (items[i] != 0)
            items[i]->Destroy(1);
        items[i] = 0;
    }
    itemCount = 0;
    for (int i = 0; i < blockCount; i++) {
        FUN_0008d330(blocks[i]);
        blocks[i] = 0;
    }
    blockCount = 0;
    for (int i = 0; i < entryCount; i++) {
        Entry_1e9680 *e = entries[i];
        void *ctx = FUN_00240750();
        FUN_002416c0(ctx, e->node, 0);
        if (e->node->next != 0) {
            do {
                FUN_00243090(FUN_00240750(), 0.001f);
            } while (e->node->next != 0);
        }
        FUN_00242ca0(FUN_00240750(), &e->node);
        if (entries[i] != 0)
            entries[i]->Destroy(1);
        entries[i] = 0;
    }
    entryCount = 0;
    (*(Renderer_1e9680**)&DAT_00527c58)->FUN_00265560(this);
    FUN_00240eb0();
    FUN_00240a10();
    (*(int*)&DAT_004e3690) = 0;
}
