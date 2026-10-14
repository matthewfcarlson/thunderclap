// STATUS: equivalent (tools/equiv.py level 3: 2939 inputs, branch coverage 12/12)
// FUN_001f87e0 @ 0x001f87e0
struct Key64 {
    unsigned int lo;
    unsigned int hi;
};

struct Slot {
    char pad0[0x34];
    int value;              // 0x34
    char pad38[0x58 - 0x38];
};

struct Ref {
    char pad0[0x10];
    int *target;            // 0x10
};

struct Request {
    char pad0[8];
    Key64 key;              // 0x08
};

unsigned __int64 __cdecl FUN_0027b020(Slot *slot);

class SlotTable {
public:
    char pad0[0x458];
    int enabled;            // 0x458
    char pad45c[0x6f4 - 0x45c];
    char slotStorage[0xc68 - 0x6f4];
    int count;              // 0xc68
    bool FUN_001f87e0(Ref *ref, Request *req, unsigned int *outIndex);
};

bool SlotTable::FUN_001f87e0(Ref *ref, Request *req, unsigned int *outIndex)
{
    if (enabled == 0)
        return false;
    for (int i = 0; i < count; i++) {
        Slot *slot = (Slot *)slotStorage + i;
        unsigned int lo = req->key.lo;
        unsigned int hi = req->key.hi;
        unsigned __int64 id = FUN_0027b020(slot);
        if ((unsigned int)id == lo && (unsigned int)(id >> 32) == hi && slot->value == *ref->target) {
            *outIndex = i;
            return true;
        }
    }
    return false;
}
