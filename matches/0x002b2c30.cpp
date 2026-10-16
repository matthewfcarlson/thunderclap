typedef unsigned __int64 U64;
U64 __cdecl getValue(void*);
class Caster {
  public:
    virtual void cast();
};
class Obj {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void doIt(Caster*, U64);
};
void __cdecl target(Obj* obj, void* p) {
    U64 v = getValue(p);
    Caster caster;
    obj->doIt(&caster, v);
}