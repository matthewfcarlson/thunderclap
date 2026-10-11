extern "C" char DAT_00415b00[];
extern "C" void _ReadWriteBarrier();
class Base {
  public:
    virtual void f0();
    virtual void f1();
};
class Obj {
  public:
    virtual void slot0();
    void tail();
    char pad[0x1c];
    Base* p20;
    Base* p24;
};
void Obj::slot0() {
    *(void**)this = (void*)((int)DAT_00415b00);
    _ReadWriteBarrier();
    if (p24) {
        p24->f1();
        p24 = 0;
    }
    p20->f1();
    tail();
}
