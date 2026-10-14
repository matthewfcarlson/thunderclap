// STATUS: equivalent (tools/equiv.py level 3: 70 inputs, branch coverage 6/6)
// FUN_00225030 @ 0x00225030
// FUN_00225030: bind to a skeleton and look up the rotation / translation channels of each bone
struct Id {
    int lo;
    int hi;
};

struct Table {
    char pad00[0x10];
    unsigned int count;
    char pad14[0x10];
    Id *ids;
};

struct Pair {
    int trans;
    int rot;
};

struct Channel;

struct Skeleton {
    virtual void AddRef();
    virtual void Release();
    Channel *FUN_00288ad0(int lo, int hi);
};

struct Channel {
    int FUN_00288960(int a, int b);
};

class Binder {
public:
    char pad00[0x10];
    Table *table;
    char pad14[0xc];
    Skeleton *skel;
    Pair pairs[1];

    void FUN_00225030(Skeleton *s);
};

void Binder::FUN_00225030(Skeleton *s)
{
    skel = s;
    s->AddRef();
    unsigned int n = table->count;
    for (unsigned int i = 0; i < n; i++) {
        Channel *ch = s->FUN_00288ad0(table->ids[i].lo, table->ids[i].hi);
        if (ch != 0) {
            pairs[i].rot = ch->FUN_00288960(0x544f52, 0x544f52);
            pairs[i].trans = ch->FUN_00288960(0x4e415254, 0x54434556);
        } else {
            pairs[i].rot = 0;
            pairs[i].trans = 0;
        }
    }
}
