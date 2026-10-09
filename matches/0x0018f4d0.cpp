struct Q {
    void Go();
};
struct Z {
    char pad[0x128];
    Q* field;
};
struct Y {
    Z* GetZ();
};
struct X {
    Y* GetY();
};
struct A {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual bool vfunc_3(void*, void*);
    virtual void f4();
    virtual void f5();
    char pad[0x1c];
    X* mThing;
};
bool A::vfunc_3(void*, void*) {
    X* x = mThing;
    Y* y = x->GetY();
    Z* z = y->GetZ();
    Q* q = z->field;
    if (!q)
        return false;
    q->Go();
    return true;
}
