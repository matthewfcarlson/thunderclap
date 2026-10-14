extern "C" int strcmp(const char*, const char*);
class Entry_268a10 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual char* Name();
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
    virtual Entry_268a10* vfunc_10(const char*);
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    char pad[0x10];
    unsigned int count;
};
Entry_268a10* ControllerXBox::vfunc_10(const char* s) {
    unsigned int i;
    for (i = 0; i < count; i++) {
        Entry_268a10* e = (Entry_268a10*)((char*)this + 0x18 + i * 0x34);
        if (strcmp(s, e->Name()) == 0)
            return (Entry_268a10*)((char*)this + 0x18 + i * 0x34);
    }
    return 0;
}