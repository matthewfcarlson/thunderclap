// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_001ddcc0 @ 0x001ddcc0
struct Alignment {
    char pad0[0x198];
    int kind;
};

struct Slot {
    char pad0[0x18];
    Alignment *brain;
    char pad1c[6];
    short id;
    char pad24[4];
};

struct Pool {
    unsigned char flags;
    char pad[19];
};

class Roster {
public:
    char pad0[0x608];
    Slot slots[0x800];
    char pad14608[0x10];
    Pool pools[1];
    int FUN_001dbfe0(int key);
    const char *FUN_001ddcc0(int key);
};

const char *Roster::FUN_001ddcc0(int key)
{
    int idx = FUN_001dbfe0(key);
    if (idx < 0)
        return 0;
    Slot *s = &slots[idx];
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
