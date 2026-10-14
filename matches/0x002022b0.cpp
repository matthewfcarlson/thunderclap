// Same code shape as 0x0002ce30 (propagated; names are from that function)
class Dummy_2022b0 {
  public:
    void Call(void*);
};

class Method1 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void* a, void** b, void* c);

    char pad[0x18];
    void (Dummy_2022b0::*m_fn)(void*);
};

void Method1::vfunc_2(void* a, void** b, void* c) {
    Dummy_2022b0* d = (Dummy_2022b0*)a;
    (d->*m_fn)(*b);
}
