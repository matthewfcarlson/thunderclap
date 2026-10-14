// STATUS: equivalent (tools/equiv.py level 3: 58 inputs, branch coverage 20/20)
// FUN_0024a5d0 @ 0x0024a5d0
struct IntrusiveList {
    void *head;
    void *next;
    void *prev;
    void *last;
    int count;
    // empty list: every link points at the sentinel stored in the second slot
    void Init() { head = &next; next = &next; prev = &next; last = &next; count = 0; }
};

struct Pool_24a5d0 {
    char data[0x48];
};

struct ItemLink {
    ItemLink *next;
};

struct Item_24a5d0 {
    char pad00[0x14];
    ItemLink link;           // 0x14
    char pad18[0x38 - 0x18];
    int attr;                // 0x38
};

struct Entry_24a5d0 {
    char pad00[0x10];
    int key;                 // 0x10
};

struct Source_24a5d0 {
    char pad00[0x22];
    unsigned short refCount; // 0x22
    char pad24[0x3c - 0x24];
    ItemLink *itemHead;      // 0x3c
    Entry_24a5d0 *FUN_00257250();
    Entry_24a5d0 *FUN_00257270(Entry_24a5d0 *cur);
};

struct SrcNode {
    char pad00[0x10];
    int f10;
    int f14;
    int f18;
    Item_24a5d0 *owner;             // 0x1c
};

struct KeyNode {
    KeyNode *next;
    void *key;
};

namespace audio {
class StreamPlayerAllocator {
public:
    virtual void v0();
    unsigned char flags;     // 0x04
    StreamPlayerAllocator() {}
};
}

extern char DAT_004e5f98;
extern Pool_24a5d0 DAT_004e5ff0;
extern Pool_24a5d0 DAT_004e6080;
void FUN_00257e80(void *list, void *item);
void *FUN_00247530(Pool_24a5d0 *pool);
void FUN_00249ce0(IntrusiveList *list, SrcNode *node, int *attr);
void *FUN_00242ce0(void *a3, int *key);

class StreamVoice {
public:
    char pad00[8];
    float f08;
    float f0c;
    float f10;
    float f14;
    IntrusiveList nodes;     // 0x18
    Source_24a5d0 *source;          // 0x2c
    int mode;                // 0x30
    float f34;
    int f38;
    KeyNode *keyHead;        // 0x3c
    KeyNode *keyTail;        // 0x40
    void *owner;             // 0x44
    IntrusiveList list48;    // 0x48
    IntrusiveList list5c;    // 0x5c
    IntrusiveList list70;    // 0x70
    int f84;
    int f88;
    int f8c;
    int f90, f94, f98;
    int f9c, fa0, fa4;
    float fa8;
    audio::StreamPlayerAllocator *allocator; // 0xac
    audio::StreamPlayerAllocator ownAllocator; // 0xb0

    StreamVoice(int a0, int a1, Source_24a5d0 *a2, void *a3, int a4, audio::StreamPlayerAllocator *a5);
};

StreamVoice::StreamVoice(int a0, int a1, Source_24a5d0 *a2, void *a3, int a4, audio::StreamPlayerAllocator *a5)
{
    nodes.Init();
    keyHead = 0;
    keyTail = 0;
    list48.Init();
    list5c.Init();
    list70.Init();
    FUN_00257e80(&DAT_004e5f98, this);
    owner = a3;
    source = a2;
    a2->refCount++;
    f84 = a1;
    f88 = a0;
    f8c = a4;
    f08 = 1.0f;
    f0c = 1.0f;
    f10 = 1.0f;
    f14 = 1.0f;
    f34 = 1.0f;
    mode = 2;
    f38 = 0;
    ownAllocator.flags &= 0xfc;
    f9c = 0;
    fa0 = 0;
    fa4 = 0;
    f90 = 0;
    f94 = 0;
    f98 = 0;
    fa8 = 1.0f;
    if (a5)
        allocator = a5;
    else
        allocator = &ownAllocator;

    ItemLink *l = source->itemHead;
    Item_24a5d0 *item = 0;
    if (l)
        item = (Item_24a5d0 *)((char *)l - 0x14);
    while (item) {
        SrcNode *node = (SrcNode *)FUN_00247530(&DAT_004e5ff0);
        if (node) {
            node->f10 = 0;
            node->f14 = 0;
        }
        node->owner = item;
        node->f18 = 0;
        FUN_00249ce0(&nodes, node, &item->attr);
        l = item->link.next;
        if (l)
            item = (Item_24a5d0 *)((char *)l - 0x14);
        else
            item = 0;
    }

    if (a3) {
        Entry_24a5d0 *e = a2->FUN_00257250();
        while (e) {
            void *h = FUN_00242ce0(a3, &e->key);
            KeyNode *kn = (KeyNode *)FUN_00247530(&DAT_004e6080);
            kn->key = h;
            kn->next = 0;
            if (keyTail == 0)
                keyHead = kn;
            else
                keyTail->next = kn;
            keyTail = kn;
            e = a2->FUN_00257270(e);
        }
    }
}
