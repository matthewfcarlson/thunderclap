// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_001ddcc0 @ 0x001ddcc0
struct Alignment {
    char pad0[0x198];
    int kind;
};

struct Slot_1ddcc0 {
    char pad0[0x18];
    Alignment *brain;
    char pad1c[6];
    short id;
    char pad24[4];
};

struct Pool_1ddcc0 {
    unsigned char flags;
    char pad[19];
};

class CSPManager_1ddcc0 {
public:
    char pad0[0x608];
    Slot_1ddcc0 slots[0x800];
    char pad14608[0x10];
    Pool_1ddcc0 pools[1];
    int FUN_001dbfe0(int key);
    const char *FUN_001ddcc0(int key);
};

const char *CSPManager_1ddcc0::FUN_001ddcc0(int key)
{
    int idx = FUN_001dbfe0(key);
    if (idx < 0)
        return 0;
    Slot_1ddcc0 *s = &slots[idx];
    if ((pools[s->id].flags & 1) == 0)
        return 0;
    if (s->brain == 0)
        return 0;
    switch (s->brain->kind) {
    case 0:
        return "Neutral";
    case 1:
        return "Good";
    case 2:
        return "Bad";
    case 3:
        return "Evil";
    }
    return 0;
}
