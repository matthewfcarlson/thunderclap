extern "C" char DAT_0042d548[];
typedef unsigned int u32;
struct Base {
    virtual void a();
    virtual void release();
};
struct Obj {
    char pad[0x40];
    Base* base;
    char p44[4];
    u32 value;
    char p4c[4];
    unsigned char flag;
};
void cleanup(u32);
void __fastcall finish(Obj*);
void __fastcall target(Obj* self) {
    *(u32*)self = ((int)DAT_0042d548);
    if (self->flag)
        cleanup(self->value);
    self->base->release();
    self->base = 0;
    finish(self);
}