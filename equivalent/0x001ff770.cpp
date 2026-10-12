// STATUS: equivalent (tools/equiv.py level 3: 3039 inputs, branch coverage 31/38, incomplete)
// CTriggerVolumeManager::vfunc_1 @ 0x001ff770
extern "C" int __cdecl strcmp(const char *a, const char *b);
extern "C" int __cdecl strncmp(const char *a, const char *b, unsigned n);
void *__cdecl FUN_00263ea0(unsigned int size);
unsigned __int64 __cdecl FUN_0027b020(const char *name);
extern int DAT_00425168[];

struct Tag {
    char pad0[4];
    char name[1];
};

struct Elem {
    char pad0[4];
    Tag *tag;
    char pad8[4];
    const char *name;
    void FUN_003364c0(const char *attr, int *out);
    void FUN_00336490(const char *attr, char *out);
    const char *FUN_003365b0(const char *attr);
};

struct Item {
    virtual void v0();
    Item *FUN_001fbb30();
    void FUN_001fbd00(Elem *e);
    void FUN_001fc3c0(Elem *e);
};

struct Inner {
    bool FUN_001cd010();
};

struct Parent {
    char pad0[0x2c];
    Inner *inner;
};

struct Unlocks {
    bool FUN_00092860(int index);
};

struct Table {
    Unlocks *FUN_00086340();
};

struct Globals {
    char pad0[0x54];
    Table *table;
};

extern Globals *DAT_004dd700;

struct Bucket {
    int count;
    char *buf;
};

class CTriggerVolumeManager {
public:
    virtual void v0();
    virtual bool v1(Elem *e);
    virtual void v2();
    virtual void v3();

    Parent *parent;
    int itemCount;
    Item *items[0x80];
    char pad20c[8];
    Bucket *buckets[8];
    int curBucket;

    Item *FUN_001fc7f0(const char *name);
    int FUN_001fd390(const char *type);
    void FUN_001fd130(char *slot, int idx);
    Item *FUN_001fc8c0(int lo, int hi);
    Item *FUN_001fcf40();
};

bool CTriggerVolumeManager::v1(Elem *e)
{
    if (parent && parent->inner && parent->inner->FUN_001cd010())
        return true;

    const char *name = e->name;
    if (strcmp(e->tag->name, "Volume") == 0) {
        if (strncmp(name, "hint_", 5) == 0) {
            int unlockIndex;
            e->FUN_003364c0("UnlockableIndex", &unlockIndex);
            if (unlockIndex > 0) {
                if (!DAT_004dd700->table->FUN_00086340()->FUN_00092860(unlockIndex))
                    return false;
            }
        }
        Item *item = FUN_001fc7f0(name);
        if (itemCount >= 0x80)
            return false;
        if (!item) {
            void *mem = FUN_00263ea0(0xd8);
            if (mem)
                item = ((Item *)mem)->FUN_001fbb30();
            else
                item = 0;
            item->v0();
            items[itemCount] = item;
            itemCount++;
        }
        item->FUN_001fbd00(e);
        return true;
    }
    if (strcmp(e->tag->name, "Locator") == 0) {
        char streamed = 0;
        Item *item;
        e->FUN_00336490("IsStreamed", &streamed);
        if (streamed) {
            if (curBucket == -1)
                return true;
            int idx = FUN_001fd390(e->FUN_003365b0("Type"));
            if (idx == -1)
                idx = 0;
            Bucket *b = &buckets[idx][curBucket];
            if (b->count >= DAT_00425168[idx])
                return true;
            item = (Item *)(b->buf + b->count * 64);
            b->count++;
            FUN_001fd130((char *)item, idx);
        } else {
            unsigned __int64 h = FUN_0027b020(name);
            item = FUN_001fc8c0((int)h, (int)(h >> 32));
            if (!item)
                item = FUN_001fcf40();
        }
        if (item)
            item->FUN_001fc3c0(e);
    }
    return true;
}
