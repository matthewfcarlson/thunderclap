// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_001df4c0 @ 0x001df4c0
// FUN_001df4c0: is the entry's owner away from the origin
struct V3 {
    float x, y, z;
    float FUN_000111f0();
};

struct Holder {
    char pad00[0x50];
    V3 pos;
};

struct Owner {
    Holder *FUN_001d72e0();
};

struct Entry {
    char pad00[0x18];
    Owner *owner;
    char pad1c[6];
    short slot;
    char pad24[4];
};

struct Slot {
    char pad00[0x10];
    unsigned char flags;
    char pad11[3];
};

char __cdecl FUN_00018960(float v, float a, float eps);

class Manager {
public:
    char pad00[0x608];
    Entry entries[0x800];
    Slot slots[1];

    char FUN_001df4c0(int index);
};

char Manager::FUN_001df4c0(int index)
{
    if (index < 0 || index >= 0x800)
        return 0;
    Entry *e = &entries[index];
    if (!(slots[e->slot].flags & 1))
        return 0;
    if (e->owner == 0)
        return 0;
    if (e->owner->FUN_001d72e0() == 0)
        return 0;
    V3 v = e->owner->FUN_001d72e0()->pos;
    if (FUN_00018960(v.FUN_000111f0(), 0.0f, 1e-5f))
        return 0;
    return 1;
}
