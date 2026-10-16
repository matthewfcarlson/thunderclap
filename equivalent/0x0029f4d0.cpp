// STATUS: equivalent (tools/equiv.py level 3: 2971 inputs, branch coverage 10/10)
// FUN_0029f4d0 @ 0x0029f4d0
// FUN_0029f4d0: find (or take from the free pool) the entry for a key and fill it from a source object
#include "decls/data/game/global.h"

struct Source_29f4d0 {
    char pad00[0x4c];
    int x, y, z;
};

struct Entry_29f4d0 {
    int x, y, z;
    char pad0c[4];
    Source_29f4d0 *source;
    int f14;
    int key;
};

struct Container_29f4d0 {
    char data[0x2c];
    void FUN_00231590(int key, int flags, Entry_29f4d0 *e);
};

struct Finder_29f4d0 {
    char data[0x18];
    void FUN_00231160(Container_29f4d0 *c);
    Entry_29f4d0 *FUN_00231180(int key, int flags);
};


class Cache_29f4d0 {
public:
    char pad00[4];
    Container_29f4d0 container;
    Entry_29f4d0 **pool;
    char pad34[4];
    int poolCount;

    void FUN_0029cb70(int n);
    void FUN_0029f4d0(int key, Source_29f4d0 *src);
};

void Cache_29f4d0::FUN_0029f4d0(int key, Source_29f4d0 *src)
{
    Finder_29f4d0 finder;
    finder.FUN_00231160(&container);
    Entry_29f4d0 *e = finder.FUN_00231180(key, 0);
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
    e->f14 = *(*(int**)&DAT_0052c2b4);
}
