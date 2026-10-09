struct Ref { virtual void a(); virtual void b(); };
struct Aux { void helper(); };
struct PartitionDriver {
    virtual void v0(); virtual void v1();
    virtual PartitionDriver* vfunc_2(unsigned char);
    virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
    char pad[12]; Ref* member;
};
extern void* vtable;
void destroy(PartitionDriver*);
PartitionDriver* PartitionDriver::vfunc_2(unsigned char param) {
    *(void**)this = &vtable;
    member->b();
    ((Aux*)this)->helper();
    if (param & 1) destroy(this);
    return this;
}