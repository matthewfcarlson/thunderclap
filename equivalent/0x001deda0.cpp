// STATUS: equivalent (tools/equiv.py level 3: 1047 inputs, branch coverage 14/16, incomplete)
// FUN_001deda0 @ 0x001deda0
// FUN_001deda0: find the entry with the given 64-bit key and notify its owner about the slot's flags
struct Entry_1deda0 {
    int keyLo;
    int keyHi;
    char pad08[0xe];
    unsigned short f16;
    char pad18[0xa];
    short slot;
    char pad24[4];
};

struct Slot_1deda0 {
    char pad00[0x10];
    unsigned short flags;
    char pad12[2];
};

struct Key_1deda0 {
    char pad00[8];
    int lo;
    int hi;
};

struct Target_1deda0 {
    char pad00[0x594];
    void FUN_001b5d20(unsigned int a, unsigned int b);
};

class Manager_1deda0 {
public:
    char pad00[0x608];
    Entry_1deda0 entries[0x800];
    Slot_1deda0 slots[1];

    Target_1deda0 *FUN_001b6580();
    void FUN_001deda0(Key_1deda0 *key);
};

void Manager_1deda0::FUN_001deda0(Key_1deda0 *key)
{
    int i;
    for (i = 0; i < 0x800; i++) {
        if (entries[i].keyLo == key->lo && entries[i].keyHi == key->hi)
            break;
    }
    if (i >= 0x800)
        return;
    Entry_1deda0 *e = &entries[i];
    Slot_1deda0 *s = &slots[e->slot];
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
    ((Target_1deda0 *)t)->FUN_001b5d20(e->f16, mode);
}
