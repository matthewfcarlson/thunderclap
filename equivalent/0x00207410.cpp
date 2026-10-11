// STATUS: equivalent (tools/equiv.py level 3: 107 inputs, branch coverage 25/26, incomplete)
// FUN_00207410 @ 0x00207410
extern unsigned char DAT_004c91d8[];

struct Slot {
    void FUN_00266220(int v);
};

struct Node {
    char pad0[0x38];
    Slot *slot;
    void FUN_00204f00();
};

struct Stream {
    int FUN_00266710();
    int FUN_00266700();
    void FUN_00263e90();
};

class Player {
public:
    char pad0[0x578];
    Slot *slots[3];
    int curSlot;
    char pad588[0xaec - 0x588];
    Stream *stream;
    char busy;
    char pad_af1;
    char pending;
    char locked;

    int FUN_00203a80();
    Node *FUN_00204540(int a);
    void FUN_00207130();
    int FUN_00203bb0();
    void FUN_00204720(int v);
    void FUN_002067d0(int v, int w);
    char FUN_00207410();
};

char Player::FUN_00207410()
{
    if (!stream)
        return 0;
    if (stream->FUN_00266710() != 3)
        return 0;

    unsigned char flag;
    if (pending)
        flag = DAT_004c91d8[1];
    else
        flag = locked ? 0 : DAT_004c91d8[0];

    int id = FUN_00203a80();

    if (busy) {
        stream->FUN_00263e90();
        char wasLocked = locked;
        stream = 0;
        if (wasLocked) {
            locked = 0;
            return 0;
        }
        if (flag)
            FUN_00204540(id)->FUN_00204f00();
        busy = 0;
        pending = 0;
        return 0;
    }

    if (!pending && !locked)
        FUN_00207130();

    if (flag) {
        Node *n = FUN_00204540(id);
        int r = stream->FUN_00266700();
        n->slot->FUN_00266220(r);
    } else if (locked) {
        int r = stream->FUN_00266700();
        slots[curSlot]->FUN_00266220(r);
    }

    if (!locked) {
        int r = FUN_00203bb0();
        if (pending) {
            pending = 0;
            FUN_00204720(r);
        } else {
            FUN_002067d0(r, 0);
        }
    }

    stream->FUN_00263e90();
    stream = 0;
    return 1;
}
