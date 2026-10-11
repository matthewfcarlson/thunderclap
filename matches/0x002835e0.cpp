extern "C" char DAT_0042c514[];
extern "C" void _ReadWriteBarrier();
class Ref {
  public:
    virtual void f0();
    virtual void Release();
};
class CLightQueue {
  public:
    void* vptr;
    char pad04[0x10];
    Ref* m14;
    char pad18[8];
    Ref* m20;
    char pad24[8];
    Ref* m2c;
    char pad30[0x24];
    Ref* m54;
};
void __fastcall FUN_0027afd0(CLightQueue*);
void __fastcall FUN_002835e0(CLightQueue* self) {
    self->vptr = (void*)((int)DAT_0042c514);
    _ReadWriteBarrier();
    if (self->m2c) {
        self->m2c->Release();
        self->m2c = 0;
    }
    if (self->m20) {
        self->m20->Release();
        self->m20 = 0;
    }
    if (self->m54) {
        self->m54->Release();
        self->m54 = 0;
    }
    if (self->m14) {
        self->m14->Release();
        self->m14 = 0;
    }
    FUN_0027afd0(self);
}
