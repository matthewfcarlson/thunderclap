// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_00272ae0 @ 0x00272ae0
struct Guard_272ae0 {
    virtual void begin();
    virtual void end();
};
struct Provider_272ae0 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual unsigned int getSecond();
    virtual unsigned int getFirst();
};
struct Object {
    char reserved[12];
    Guard_272ae0 guard;
    char unused[0x54 - 0x10];
    unsigned char available;
    char padding[3];
    Provider_272ae0 *provider;
    bool FUN_00272ae0(unsigned int *first, unsigned int *second);
};
bool Object::FUN_00272ae0(unsigned int *first, unsigned int *second) {
    guard.begin();
    if (available) {
        *first = provider->getFirst();
        *second = provider->getSecond();
        guard.end();
        return true;
    }
    guard.end();
    return false;
}