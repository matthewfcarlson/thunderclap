// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_000e5f00 @ 0x000e5f00
struct Interface {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8(int);
    virtual void slot9();
    virtual void slot10(int);
};
struct Holder {
    char pad[0x14];
    Interface *object;
};
struct Owner {
    char pad0[0x48];
    Interface *active;
    char pad1[0x998 - 0x4c];
    Holder *holders[3];
    void FUN_000e5f00(unsigned int index);
};
void Owner::FUN_000e5f00(unsigned int index) {
    if (index == 3) {
        active = 0;
        return;
    }
    Holder *selected = index < 3 ? holders[index] : (Holder *)0;
    active = selected->object;
    active->slot8(0);
    active->slot10(2);
}