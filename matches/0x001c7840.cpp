struct StoreBase {
    virtual StoreBase* vfunc_0(unsigned char);
    virtual void f1();
    virtual void f2();
    char pad[0x10];
    void* member;
};
extern void __cdecl helper(void*);
extern void* table_1c7840;
StoreBase* StoreBase::vfunc_0(unsigned char flag) {
    *(void**)this = &table_1c7840;
    helper(member);
    if (flag & 1)
        helper(this);
    return this;
}