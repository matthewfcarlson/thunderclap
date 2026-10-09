class Dummy {
  public:
    void Call(void*);
};

class Method1 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void* a, void** b, void* c);

    char pad[0x18];
    void (Dummy::*m_fn)(void*);
};

void Method1::vfunc_2(void* a, void** b, void* c) {
    Dummy* d = (Dummy*)a;
    (d->*m_fn)(*b);
}
