extern "C" void _ReadWriteBarrier();
extern void* g_vftable_21aa0[];
extern void* g_base_vftable[];
void operator delete(void*);
class Ref_21aa0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_21aa0 {
  public:
    void* vptr;
    void Fin();
};
class Action : public Base_21aa0 {
  public:
    char pad[0x18];
    Ref_21aa0* m1c;
    char pad2[4];
    Ref_21aa0* m24;
    Action* f2(unsigned char flags);
};
Action* Action::f2(unsigned char flags) {
    vptr = g_vftable_21aa0;
    _ReadWriteBarrier();
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    vptr = g_base_vftable;
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}
