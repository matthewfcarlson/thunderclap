class Inner {
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
    virtual unsigned int Get();
};
class Helper {
  public:
    void Run(void* out, unsigned int value);
};
class Owner {
  public:
    char pad[0x18];
    Inner* ptr;
    void Target(void* out, Helper* h);
};
void Owner::Target(void* out, Helper* h) {
    if (ptr)
        h->Run(out, ptr->Get());
}