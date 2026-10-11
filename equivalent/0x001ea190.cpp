// STATUS: equivalent (tools/equiv.py level 3: 79 inputs, branch coverage 22/24, incomplete)
// FUN_001ea190 @ 0x001ea190
extern char DAT_004c7150[];
extern char DAT_004c7170[];
extern char DAT_004c712c[];
extern int DAT_004c6f4c;
extern void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);
extern unsigned __cdecl FUN_0026fd50(unsigned value, unsigned align);
extern void *__cdecl FUN_0008d710(unsigned size, int tag);

struct Key {
    int a;
    int b;
};

struct Entry {
    int f00;
    void *f04;
    unsigned f08;
    int f0c;
    unsigned f10;
};

struct Pool {
    char pad00[0x19c];
    Entry *entries[200];
    int count;
    Entry *FUN_001e9900(Key *key);
};

extern Pool *DAT_004e3690;

struct Source {
    char pad00[0x10];
    Key key;
    unsigned char flags;
    char pad19[3];
    unsigned size;
};

struct Request {
    char pad00[0x40];
    unsigned bits;
};

struct Link {
    Link *next;
};

struct Item {
    int pad00;
    Link link;
};

struct List {
    char pad00[0xc];
    Link *head;
};

class Collector {
public:
    char pad00[0x20];
    unsigned total;
    char pad24[0x2c - 0x24];
    Entry *used[64];
    int usedCount;
    int FUN_001ea190(Request *req, List *list);
};

int Collector::FUN_001ea190(Request *req, List *list)
{
    Item *it = 0;
    if (list->head)
        it = (Item *)((char *)list->head - 4);
    while (it) {
        List *sub = (List *)FUN_00344e74(it, 0, DAT_004c7150, DAT_004c7170, 0);
        if (sub) {
            FUN_001ea190(req, sub);
        } else {
            Source *src = (Source *)FUN_00344e74(it, 0, DAT_004c7150, DAT_004c712c, 0);
            if (src) {
                Key key = src->key;
                Link *keyLink = (Link *)&src->key;
                unsigned size = 0;
                if (!(src->flags & 1)) {
                    unsigned v = (src->size & 0x7fffffff) - 0x800;
                    unsigned align = DAT_004c6f4c * 2;
                    if (v < align)
                        size = align;
                    else
                        size = FUN_0026fd50(v, align);
                }
                Pool *pool = DAT_004e3690;
                Entry *e = pool->FUN_001e9900(&key);
                if (e) {
                    unsigned lvl = (req->bits >> 5) & 0x1f;
                    if (e->f10 > lvl)
                        e->f10 = lvl;
                } else {
                    if (pool->count >= 200) {
                        e = 0;
                    } else {
                        pool->entries[pool->count++] = (Entry *)FUN_0008d710(0x14, 6);
                        e = pool->entries[pool->count - 1];
                        if (e) {
                            e->f04 = keyLink;
                            e->f00 = 0;
                            e->f08 = size;
                            e->f0c = 0;
                            e->f10 = (req->bits >> 5) & 0x1f;
                            total += size;
                        }
                    }
                }
                used[usedCount] = e;
                usedCount++;
            }
        }
        it = it->link.next ? (Item *)((char *)it->link.next - 4) : 0;
    }
    return 0;
}
