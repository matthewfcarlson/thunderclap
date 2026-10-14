extern "C" void _ReadWriteBarrier();
typedef unsigned char byte_832e0;
struct Holder_832e0 {
    virtual void a();
    virtual void release();
};
extern char cow_vtable[];
extern void __cdecl thunk_FUN_00267090(void*);
struct CCow {
    void* vfptr;
    char pad[0x38];
    Holder_832e0* mHolder;
    CCow* vfunc_2(byte_832e0 flags);
    void helper();
};
CCow* CCow::vfunc_2(byte_832e0 flags) {
    vfptr = (void*)cow_vtable;
    _ReadWriteBarrier();
    if (mHolder) {
        mHolder->release();
        mHolder = 0;
    }
    helper();
    if (flags & 1)
        thunk_FUN_00267090(this);
    return this;
}
