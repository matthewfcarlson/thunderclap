class Ref_333c50 {
  public:
    virtual void Release();
    virtual void AddRef();
};
class PlayerBink {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3(Ref_333c50*, Ref_333c50*);
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    char pad[0x10 - 4];
    Ref_333c50* a;
    Ref_333c50* b;
};
void PlayerBink::f3(Ref_333c50* x, Ref_333c50* y) {
    if (a != x) {
        Ref_333c50* old = a;
        a = x;
        if (x)
            x->Release();
        if (old)
            old->AddRef();
    }
    if (b != y) {
        Ref_333c50* old = b;
        b = y;
        if (y)
            y->Release();
        if (old)
            old->AddRef();
    }
}