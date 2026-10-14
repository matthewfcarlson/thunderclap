// STATUS: equivalent (tools/equiv.py level 3: 1047 inputs, branch coverage 14/16, incomplete)
// FUN_001deda0 @ 0x001deda0
// FUN_001deda0: find the entry with the given 64-bit key and notify its owner about the slot's flags
struct Entry {
    int keyLo;
    int keyHi;
    char pad08[0xe];
    unsigned short f16;
    char pad18[0xa];
    short slot;
    char pad24[4];
};

struct Slot {
    char pad00[0x10];
    unsigned short flags;
    char pad12[2];
};

struct Key {
    char pad00[8];
    int lo;
    int hi;
};

struct Target {
    char pad00[0x594];
    void FUN_001b5d20(unsigned int a, unsigned int b);
};

class Manager {
public:
    char pad00[0x608];
    Entry entries[0x800];
    Slot slots[1];

    Target *FUN_001b6580();
    void FUN_001deda0(Key *key);
};

void Manager::FUN_001deda0(Key *key)
{
    int i;
    for (i = 0; i < 0x800; i++) {
        if (entries[i].keyLo == key->lo && entries[i].keyHi == key->hi)
            break;
    }
    if (i >= 0x800)
        return;
    Entry *e = &entries[i];
    Slot *s = &slots[e->slot];
    if (!(s->flags & 0x300))
        return;
    char *t = (char *)FUN_001b6580() + 0x594;
    if (t == 0)
        return;
    unsigned int flags = s->flags;
    unsigned int mode = 0;
    if (flags & 0x100)
        mode = 1;
    if (flags & 0x200)
        mode += 2;
    ((Target *)t)->FUN_001b5d20(e->f16, mode);
}
