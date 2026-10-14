void* __cdecl operator new(unsigned int);
extern "C" void _ReadWriteBarrier();
class Root {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    char pad[8];
    Root() throw();
};
class Mid : public Root {
  public:
    int a;
    float b;
    Mid() throw() {
        b = -1.0f;
        a = 0;
    }
};
class CJumpAttackTrack : public Mid {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    int zero;
    float d, e;
    float pi;
    float g, h;
    int j, k, l;
    CJumpAttackTrack() throw() {
        _ReadWriteBarrier();
        d = -1.0f;
        e = -1.0f;
        zero = 0;
        _ReadWriteBarrier();
        j = 0;
        k = 0;
        l = 0;
        g = 10.0f;
        h = 10.0f;
        pi = 1.5707964f;
    }
};
class Factory {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual Root* f5();
};
Root* Factory::f5() {
    return new CJumpAttackTrack;
}