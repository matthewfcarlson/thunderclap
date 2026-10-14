struct Q_18f4d0 {
    void Go();
};
struct Z {
    char pad[0x128];
    Q_18f4d0* field;
};
struct Y_18f4d0 {
    Z* GetZ();
};
struct X_18f4d0 {
    Y_18f4d0* GetY();
};
struct A_18f4d0 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual bool vfunc_3(void*, void*);
    virtual void f4();
    virtual void f5();
    char pad[0x1c];
    X_18f4d0* mThing;
};
bool A_18f4d0::vfunc_3(void*, void*) {
    X_18f4d0* x = mThing;
    Y_18f4d0* y = x->GetY();
    Z* z = y->GetZ();
    Q_18f4d0* q = z->field;
    if (!q)
        return false;
    q->Go();
    return true;
}
