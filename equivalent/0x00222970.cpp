// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 8/8)
// FUN_00222970 @ 0x00222970
extern "C" void *__cdecl memmove(void *, const void *, unsigned int);

class Handler {
public:
    virtual void v0();
    virtual void Release();      // slot 1
};

struct Slot {
    Handler *handler;        // 0x00
    float time;              // 0x04
    char active;             // 0x08
    char pad09[0x1f];
};

class SlotList {
public:
    char pad00[0x68];
    unsigned int count;      // 0x68
    Slot slots[1];           // 0x6c
    bool FUN_00222970(Handler *handler, bool remove);
};

// Finds the slot of a handler; either removes it, or marks it inactive.
bool SlotList::FUN_00222970(Handler *handler, bool remove) {
    unsigned int i = 0;
    Slot *slot = slots;
    for (; i < count; i++, slot++) {
        if (slot->handler == handler)
            break;
    }
    if (i >= count)
        return false;
    if (remove) {
        handler->Release();
        int index = slot - slots;
        count--;
        memmove(&slots[index], &slots[index + 1], (count - index) * sizeof(Slot));
        return true;
    }
    slot->time = -1.0f;
    slot->active = 0;
    return true;
}
