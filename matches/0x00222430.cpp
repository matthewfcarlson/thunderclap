struct Ref_222430 {
    virtual void a();
    virtual void b();
};
struct PartitionDriver_222430 {
    void helper();
};
struct PartitionDriver {
    virtual void v0();
    virtual void v1();
    virtual PartitionDriver* vfunc_2(unsigned char);
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    char pad[12];
    Ref_222430* member;
};
extern void* vtable_222430;
void destroy(PartitionDriver*);
PartitionDriver* PartitionDriver::vfunc_2(unsigned char param) {
    *(void**)this = &vtable_222430;
    member->b();
    ((PartitionDriver_222430*)this)->helper();
    if (param & 1)
        destroy(this);
    return this;
}