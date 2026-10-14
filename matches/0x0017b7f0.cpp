extern "C" void __cdecl opdelete(void*);
extern void* const vftable_sym;

class RelObj_17b7f0 {
  public:
    virtual void f0();
    virtual void Release();
};

class Sub28 {
  public:
    void Fn();
};

class BaseCls_17b7f0 {
  public:
    void Dtor();
};

class TeleportRelativeAction {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    TeleportRelativeAction* vfunc_2(unsigned char param);
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();

    char pad[0x18];
    int m1c;
    RelObj_17b7f0* m20;
    char pad28[4];
    Sub28 m28;
};

TeleportRelativeAction* TeleportRelativeAction::vfunc_2(unsigned char param) {
    char* self = (char*)this;
    *(void**)self = (void*)&vftable_sym;
    RelObj_17b7f0** pp = (RelObj_17b7f0**)(self + 0x20);
    RelObj_17b7f0* p = *pp;
    if (p) {
        p->Release();
        *pp = 0;
    }
    int* q1c = (int*)(self + 0x1c);
    int v = *q1c;
    if (v) {
        *q1c = 0;
    }
    ((Sub28*)(self + 0x28))->Fn();
    ((BaseCls_17b7f0*)self)->Dtor();
    if (param & 1) {
        opdelete(self);
    }
    return (TeleportRelativeAction*)self;
}
