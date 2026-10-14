extern "C" int strcmp(const char*, const char*);
class Item_268a80 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual const char* get();
};
class ControllerXBox {
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
    virtual ControllerXBox* f15(const char*);
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    char pad[0x424];
};
ControllerXBox* ControllerXBox::f15(const char* s) {
    for (unsigned i = 0; i < 2; i++) {
        Item_268a80* p = (Item_268a80*)((char*)this + 0x428 + i * 16);
        if (strcmp(s, p->get()) == 0)
            return (ControllerXBox*)((char*)this + i * 16 + 0x428);
    }
    return 0;
}
