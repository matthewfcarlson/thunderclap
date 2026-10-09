class ScriptReader {
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
    virtual unsigned long long vfunc_15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    char pad[0x114];
    unsigned int lo;
    unsigned int hi;
};
unsigned long long ScriptReader::vfunc_15() {
    return *(unsigned long long*)&lo;
}