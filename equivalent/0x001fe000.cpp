// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 9/10, incomplete)
// FUN_001fe000 @ 0x001fe000
// 8-byte id with the game's copy routine.
struct Id8 {
    int lo, hi;
    Id8(const Id8 &other) throw();
};

// equiv-map: ??0Id8@@QAE@ABU0@@Z = 0x0027af30
// By-value 16-byte name whose copy is built inline (Id8 copy + two bytes).
struct RawName {
    Id8 id;
    unsigned char a, b;
    char pad[6];
    RawName(const RawName &o) : id(o.id), a(o.a), b(o.b) {}
};

// The same 16 bytes, copied through the out-of-line copy constructor FUN_001f8940.
struct Name {
    Id8 id;
    unsigned char a, b;
    char pad[6];
    Name(const Name &other) throw();
};

struct Slot_1fe000 {
    char pad[0xc70];
    short FUN_001f9630(RawName n);
    bool FUN_001f9670(Name n, short value);
};

struct Entry_1fe000 {
    Id8 id;
    unsigned char slot;
    unsigned char b;
};

struct Pool_1fe000 {
    char pad[0x22b8];
    Entry_1fe000 entry;
};

class Mixer {
public:
    void FUN_001fe000(Pool_1fe000 *pool);

    char pad0[0x234];
    char *slots;
};

// equiv-map: ??0Name@@QAE@ABU0@@Z = 0x001f8940
void Mixer::FUN_001fe000(Pool_1fe000 *pool) {
    Entry_1fe000 *e = &pool->entry;
    if (e == 0) {
        return;
    }
    char slot = e->slot;
    if (slot == (char)0xff) {
        return;
    }
    int offset = slot * 0xc70;
    short idx = ((Slot_1fe000 *)(slots + offset))->FUN_001f9630(*(RawName *)e);
    if (idx == -2 || idx == -1 || idx < 0) {
        return;
    }
    ((Slot_1fe000 *)(slots + offset))->FUN_001f9670(*(Name *)e, idx + 1);
}
