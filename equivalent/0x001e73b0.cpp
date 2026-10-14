// STATUS: equivalent (tools/equiv.py level 3: 252 inputs, branch coverage 12/12)
// FUN_001e73b0 @ 0x001e73b0
// Walk the 0x800 slots and release the record of every slot that carries the given id.
struct Obj_1e73b0 {
    bool FUN_001d62c0();
};

struct Slot_1e73b0 {
    Obj_1e73b0* obj;
    char pad4[6];
    short rec;
    char padc[0x26 - 0xc];
    short nextId;               // id of the following slot
};

struct Rec_1e73b0 {
    char pad0[0x10];
    unsigned char flags;
    char pad11;
    short link;
};

class Pool_1e73b0 {
public:
    char pad0[0x61e];
    short firstId;
    union {
        Slot_1e73b0 slots[0x800];
        struct {                // the record table starts inside the slot area
            char pad[0x14608 - 0x620];
            Rec_1e73b0 recs[1];
        } tbl;
    };

    void FUN_001e5980(int rec);
    void FUN_001e5bc0(int link);
    void FUN_001e73b0(int id);
};

void Pool_1e73b0::FUN_001e73b0(int id)
{
    short* slotId = &firstId;
    Slot_1e73b0* slot = slots;
    Rec_1e73b0* recs = tbl.recs;
    for (int n = 0x800; n != 0; --n) {
        Rec_1e73b0* rec = &recs[slot->rec];
        if (*slotId == id) {
            bool release = true;
            if (rec->flags & 1) {
                if (slot->obj == 0 || !slot->obj->FUN_001d62c0()) {
                    release = false;
                } else {
                    FUN_001e5980(slot->rec);
                }
            }
            if (release && (rec->flags & 8) == 0) {
                FUN_001e5bc0(rec->link);
            }
        }
        slotId = &slot->nextId;
        ++slot;
    }
}
