namespace core {
struct Inner {
    int FUN_00272b60(void* value, unsigned int flags, int zero);
};
struct Item {
    void* FUN_002757f0(void* drive);
};
struct InstanceDrive {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual int vfunc_5();
    void* secondaryVtable;
    int unknown;
    Inner* inner;
    unsigned int flags;
};
} // namespace core
core::Item* __cdecl FUN_00273560(int kind);
int core::InstanceDrive::vfunc_5() {
    core::Item* item = FUN_00273560(12);
    void* value = item ? item->FUN_002757f0(this) : 0;
    return inner->FUN_00272b60(value, flags, 0);
}