// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 13/14, incomplete)
// FUN_0024b480 @ 0x0024b480
struct Handler_24b480 {
    virtual void v0();
    virtual int State();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
};
struct Slots_24b480 {
    Handler_24b480 *handler;
    int pad4[2];
};
// equiv-conv: FUN_0024b270 ecx
struct Ring_24b480 {
    Slots_24b480 slots[10];
    unsigned char current;
    unsigned char count;
    unsigned char size;
    void FUN_0024b270();
};
struct Machine {
    char pad0[0x40];
    Ring_24b480 ring;
};

// equiv-conv: FUN_0024b480 eax
void FUN_0024b480(Machine *m)
{
    if (m->ring.count == 0)
        return;
    Handler_24b480 *h = m->ring.slots[m->ring.current].handler;
    if (h == 0)
        return;
    if (h->State() == 0) {
        h->v0();
    } else if (h->State() != 1 && h->State() == 3) {
        m->ring.FUN_0024b270();
        return;
    }
    int before;
    int after;
    do {
        before = h->State();
        h->v11();
        after = h->State();
    } while (before != after);
}
