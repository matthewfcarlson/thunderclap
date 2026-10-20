#include "compat/ptr.h"
extern "C" char DAT_0042d548[];
typedef unsigned int u32_29b1d0;
struct Base_29b1d0 {
    virtual void a();
    virtual void release();
};
struct Obj_29b1d0 {
    char pad[0x40];
    Base_29b1d0* base;
    char p44[4];
    u32_29b1d0 value;
    char p4c[4];
    unsigned char flag;
};
void cleanup(u32_29b1d0);
void __fastcall finish(Obj_29b1d0*);
void __fastcall target(Obj_29b1d0* self) {
    *(hulk_uintptr*)self = ((hulk_intptr)DAT_0042d548);
    if (self->flag)
        cleanup(self->value);
    self->base->release();
    self->base = 0;
    finish(self);
}