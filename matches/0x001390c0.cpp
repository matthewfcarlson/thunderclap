extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
void operator delete(void*);
class Ref {
  public:
    virtual void F0();
    virtual void Release();
};
class Base {
  public:
    void* vptr;
    void Fin();
};
class Action : public Base {
  public:
    char pad[0x18];
    void* m1c;
    Ref* m20;
    Ref* m24;
    Ref* m28;
    Action* f2(unsigned char flags);
};
Action* Action::f2(unsigned char flags) {
    vptr = g_vftable;
    _ReadWriteBarrier();
    if (m28) {
        m28->Release();
        m28 = 0;
    }
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}
