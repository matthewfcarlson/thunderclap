// STATUS: equivalent (tools/equiv.py level 3: 50 inputs, branch coverage 12/12)
// FUN_00265280 @ 0x00265280
struct Item {
    virtual void unused();
    virtual void release();
    void FUN_00266950(int);
};
struct Owner { void FUN_002666e0(); };
struct Entry { Item* item; unsigned value; };
struct Queue {
    char pad0[8];
    Owner* owner;
    char padC[8];
    Entry* read;
    Entry* write;
    Entry* begin;
    Entry* end;
    void clear();
};
void Queue::clear() {
    for (;;) {
        unsigned count;
        if ((unsigned)read <= (unsigned)write)
            count = ((int)((unsigned)write - (unsigned)read)) >> 3;
        else
            count = (((int)((unsigned)write - (unsigned)begin)) >> 3) + (((int)((unsigned)end - (unsigned)read)) >> 3);
        if (!count) break;
        Item* item = read->item;
        unsigned value = read->value;
        if ((unsigned)write >= (unsigned)end) write = read;
        ++read;
        if (read == end) read = begin;
        if (item) {
            item->FUN_00266950(4);
            item->release();
        }
    }
    if (owner) owner->FUN_002666e0();
}
