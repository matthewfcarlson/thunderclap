extern "C" __int64 __cdecl Convert(int);
class Caster {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual int f3();
};
class Obj {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual int f3(Caster*, __int64);
};
int Test(Obj* o, int x) {
    __int64 v = Convert(x);
    Caster c;
    return o->f3(&c, v);
}
