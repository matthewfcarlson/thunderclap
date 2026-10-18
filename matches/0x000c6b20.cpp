class DynamicCaster {
  public:
    virtual void f();
};
class Obj {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3(DynamicCaster*, __int64);
    int Fn(const char*);
};
extern "C" __int64 __cdecl Find(const char*, int, int);
int Obj::Fn(const char* name) {
    DynamicCaster caster;
    return v3(&caster, Find(name, 0, 0));
}