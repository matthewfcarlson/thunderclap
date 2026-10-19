// STATUS: equivalent (tools/equiv.py level 3: 17909 inputs, branch coverage 3/4, incomplete)
// FUN_003188d0 @ 0x003188d0
struct Item { char pad[0x24]; float key; char rest[0x1c]; };
struct Store { char pad[4]; Item * volatile cursor; };
struct Owner { char pad[8]; Store *store; char rest[0x24]; int count; unsigned char FUN_003188d0(float value); };
struct ThisCall_002f7a90 {
    void FUN_002f7a90(Item *item);
};
unsigned char Owner::FUN_003188d0(float value)
{
    Store *s = store;
    Item *old = s->cursor;
    if (value < old[-1].key) {
        s->cursor = old - 1;
        if ((unsigned int)(old - 1) < (unsigned int)s->cursor)
            ((ThisCall_002f7a90*)(this))->FUN_002f7a90(s->cursor);
        --count;
        return 0;
    }
    return 1;
}