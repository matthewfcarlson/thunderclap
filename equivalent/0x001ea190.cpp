// STATUS: equivalent (tools/equiv.py level 3: 79 inputs, branch coverage 22/24, incomplete)
// FUN_001ea190 @ 0x001ea190
extern char DAT_004c7150[];
extern char DAT_004c7170[];
extern char DAT_004c712c[];
extern int DAT_004c6f4c;
extern void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);
extern unsigned __cdecl FUN_0026fd50(unsigned value, unsigned align);
extern void *__cdecl FUN_0008d710(unsigned size, int tag);

struct Key_1ea190 {
    int a;
    int b;
};

struct Entry_1ea190 {
    int f00;
    void *f04;
    unsigned f08;
    int f0c;
    unsigned f10;
};

struct Pool_1ea190 {
    char pad00[0x19c];
    Entry_1ea190 *entries[200];
    int count;
    Entry_1ea190 *FUN_001e9900(Key_1ea190 *key);
};

extern Pool_1ea190 *DAT_004e3690;

struct Source_1ea190 {
    char pad00[0x10];
    Key_1ea190 key;
    unsigned char flags;
    char pad19[3];
    unsigned size;
};

struct Request {
    char pad00[0x40];
    unsigned bits;
};

struct Link_1ea190 {
    Link_1ea190 *next;
};

struct Item_1ea190 {
    int pad00;
    Link_1ea190 link;
};

struct List_1ea190 {
    char pad00[0xc];
    Link_1ea190 *head;
};

class Collector_1ea190 {
public:
    char pad00[0x20];
    unsigned total;
    char pad24[0x2c - 0x24];
    Entry_1ea190 *used[64];
    int usedCount;
    int FUN_001ea190(Request *req, List_1ea190 *list);
};

int Collector_1ea190::FUN_001ea190(Request *req, List_1ea190 *list)
{
    Item_1ea190 *it = 0;
    if (list->head)
        it = (Item_1ea190 *)((char *)list->head - 4);
    while (it) {
        List_1ea190 *sub = (List_1ea190 *)FUN_00344e74(it, 0, DAT_004c7150, DAT_004c7170, 0);
        if (sub) {
            FUN_001ea190(req, sub);
        } else {
            Source_1ea190 *src = (Source_1ea190 *)FUN_00344e74(it, 0, DAT_004c7150, DAT_004c712c, 0);
            if (src) {
                Key_1ea190 key = src->key;
                Link_1ea190 *keyLink = (Link_1ea190 *)&src->key;
                unsigned size = 0;
                if (!(src->flags & 1)) {
                    unsigned v = (src->size & 0x7fffffff) - 0x800;
                    unsigned align = DAT_004c6f4c * 2;
                    if (v < align)
                        size = align;
                    else
                        size = FUN_0026fd50(v, align);
                }
                Pool_1ea190 *pool = DAT_004e3690;
                Entry_1ea190 *e = pool->FUN_001e9900(&key);
                if (e) {
                    unsigned lvl = (req->bits >> 5) & 0x1f;
                    if (e->f10 > lvl)
                        e->f10 = lvl;
                } else {
                    if (pool->count >= 200) {
                        e = 0;
                    } else {
                        pool->entries[pool->count++] = (Entry_1ea190 *)FUN_0008d710(0x14, 6);
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
        it = it->link.next ? (Item_1ea190 *)((char *)it->link.next - 4) : 0;
    }
    return 0;
}
