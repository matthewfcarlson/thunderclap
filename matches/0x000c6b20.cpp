class DynamicCaster {
  public:
    virtual void f();
};
class Obj {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(DynamicCaster*, __int64);
    void Fn(const char*);
};
extern "C" __int64 __cdecl Find(const char*, int, int);
void Obj::Fn(const char* name) {
    DynamicCaster caster;
    v3(&caster, Find(name, 0, 0));
}