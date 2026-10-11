extern "C" void _ReadWriteBarrier();
extern "C" int __cdecl GetThing() throw();
extern "C" void __cdecl Func(void*) throw();
class Base {
  public:
    Base(int) throw();
    virtual void a();
    char pad[0x24];
};
struct Init0 {
    char m28[8];
};
struct Init1 {
    Init1() throw() {
        m30 = 1000;
        m34 = 1000;
    }
    int m30, m34;
};
class Mix : public Base, public Init0, public Init1 {
  public:
    Mix() throw();
    virtual void a();
    void* p38;
    void* p3c;
    void* p40;
    void* p44;
    int m48;
};
Mix::Mix() throw() : Base(GetThing()) {
    _ReadWriteBarrier();
    void** e = &p3c;
    *e = e;
    p40 = e;
    p44 = e;
    p38 = e;
    m48 = 0;
    Func(m28);
}
