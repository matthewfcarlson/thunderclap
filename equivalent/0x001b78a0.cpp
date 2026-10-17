// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_001b78a0 @ 0x001b78a0
struct Obj {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
};
struct Owner {
    char pad0[12];
    Obj *object;
    char pad1[0x118];
    int state;
    void FUN_001b78a0();
};
void Owner::FUN_001b78a0() {
    if (object) object->slot7();
    Obj *old = object;
    if (old) {
        object = 0;
        old->slot1();
    }
    state = 0;
}