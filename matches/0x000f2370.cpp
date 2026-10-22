extern "C" __int64 __cdecl Convert(int);
class DynamicCaster_f2370 {
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
    virtual int f3(DynamicCaster_f2370*, __int64);
};
int Test(Obj* o, int x) {
    __int64 v = Convert(x);
    DynamicCaster_f2370 c;
    return o->f3(&c, v);
}
