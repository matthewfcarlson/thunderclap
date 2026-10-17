struct Ref {
    virtual void addRef();
    virtual void release();
};
extern void* DAT_003f3390[];
extern void* DAT_003f3408[];
struct CJumpAction {
    void** vtable;
    char padding[0x18];
    Ref* reference;
    unsigned value;
    unsigned state[6];
    void FUN_00232660();
    CJumpAction* FUN_00018ca0(unsigned val, Ref* ref);
};
CJumpAction* CJumpAction::FUN_00018ca0(unsigned val, Ref* ref) {
    FUN_00232660();
    vtable = DAT_003f3390;
    reference = 0;
    if (ref)
        ref->addRef();
    if (reference)
        reference->release();
    reference = ref;
    for (int i = 0; i < 6; ++i)
        state[i] = 0;
    value = val;
    vtable = DAT_003f3408;
    return this;
}