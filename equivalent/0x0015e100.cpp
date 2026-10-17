// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_0015e100 @ 0x0015e100
inline void* operator new(unsigned int, void* p) throw() { return p; }
struct RefObject { virtual void addRef(); virtual void release(); };
struct LocomotionStrafeAction {
    virtual void v0();
    virtual void v1();
    char pad[0x1c-4];
    RefObject *object;
    unsigned int other;
    void FUN_00232660();
};
struct LocomotionStrafe4Action : LocomotionStrafeAction {
    char pad2[0x44-0x24];
    unsigned int value;
    virtual void v0();
    LocomotionStrafe4Action *FUN_0015e100(unsigned int initial, RefObject *replacement);
};
LocomotionStrafe4Action *LocomotionStrafe4Action::FUN_0015e100(unsigned int initial, RefObject *replacement) {
    FUN_00232660();
    new ((void*)this) LocomotionStrafeAction;
    object = 0;
    other = 0;
    if (replacement) replacement->addRef();
    if (object) object->release();
    object = replacement;
    new ((void*)this) LocomotionStrafe4Action;
    value = 0;
    value = initial;
    return this;
}