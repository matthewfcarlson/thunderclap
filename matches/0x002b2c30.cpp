typedef unsigned __int64 U64;
U64 __cdecl getValue(void*);
class Caster_2b2c30 {
  public:
    virtual void cast();
};
class Obj {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void doIt(Caster_2b2c30*, U64);
};
void __cdecl target(Obj* obj, void* p) {
    U64 v = getValue(p);
    Caster_2b2c30 caster;
    obj->doIt(&caster, v);
}