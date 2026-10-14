// STATUS: equivalent (tools/equiv.py level 3: 2756 inputs, branch coverage 9/10, incomplete)
// FUN_00067b00 @ 0x00067b00
// FUN_00067b00 @ 0x00067b00: allocate a handle (serial << 8 | slot) in a ring of 64 slots
struct Name {
    char data[8];
    void FUN_0027b040(const char *s);
    void FUN_0027af70(int v);
};

struct Record {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
    int pad14;
    Name name;              // 0x18
};

extern const char DAT_003f335c[];

class HandlePool {
public:
    unsigned int serial;    // 0x00
    int head;               // 0x04
    unsigned int ids[64];   // 0x08
    Record records[64];     // 0x108
    unsigned int FUN_00067b00(int arg);
};

unsigned int HandlePool::FUN_00067b00(int arg)
{
    int start = head;
    int slot = start;
    do {
        if (ids[slot] == 0)
            break;
        slot = (slot + 1) % 64;
    } while (slot != start);

    Record *r = &records[slot];
    r->f0 = 0;
    r->fc = 0;
    r->f8 = 0;
    r->f4 = 0;
    r->f10 = 0;
    r->name.FUN_0027b040(DAT_003f335c);
    records[slot].name.FUN_0027af70(arg);

    unsigned int id = (serial << 8) | slot;
    ids[slot] = id;
    head = (slot + 1) % 64;
    serial = (serial + 1) % 0xffffff;
    if (serial == 0)
        serial = 1;
    return id;
}
