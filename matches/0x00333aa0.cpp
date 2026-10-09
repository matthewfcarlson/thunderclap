struct Thing {
    char pad[0xc];
    unsigned int value;
};
class PlayerBink {
    char pad[0x18];
    Thing* mThing;

  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
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
    virtual unsigned int vfunc_15();
};
unsigned int PlayerBink::vfunc_15() {
    if (mThing)
        return mThing->value;
    return 0;
}