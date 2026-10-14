// STATUS: equivalent (tools/equiv.py level 3: 2971 inputs, branch coverage 10/10)
// FUN_0029f4d0 @ 0x0029f4d0
// FUN_0029f4d0: find (or take from the free pool) the entry for a key and fill it from a source object
struct Source {
    char pad00[0x4c];
    int x, y, z;
};

struct Entry {
    int x, y, z;
    char pad0c[4];
    Source *source;
    int f14;
    int key;
};

struct Container {
    char data[0x2c];
    void FUN_00231590(int key, int flags, Entry *e);
};

struct Finder {
    char data[0x18];
    void FUN_00231160(Container *c);
    Entry *FUN_00231180(int key, int flags);
};

extern int *DAT_0052c2b4;

class Cache {
public:
    char pad00[4];
    Container container;
    Entry **pool;
    char pad34[4];
    int poolCount;

    void FUN_0029cb70(int n);
    void FUN_0029f4d0(int key, Source *src);
};

void Cache::FUN_0029f4d0(int key, Source *src)
{
    Finder finder;
    finder.FUN_00231160(&container);
    Entry *e = finder.FUN_00231180(key, 0);
    if (e == 0) {
        if (poolCount == 0) {
            FUN_0029cb70(5);
            if (poolCount == 0)
                FUN_0029cb70(2);
        }
        if (poolCount != 0) {
            poolCount--;
            e = pool[poolCount];
            e->key = key;
        }
        container.FUN_00231590(key, 0, e);
        if (e == 0)
            return;
    }
    e->x = src->x;
    e->y = src->y;
    e->z = src->z;
    e->source = src;
    e->f14 = *DAT_0052c2b4;
}
