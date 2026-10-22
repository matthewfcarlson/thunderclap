typedef unsigned __int64 U64;
U64 __cdecl getValue(void*);
class DynamicCaster_2b2c30 {
  public:
    virtual void cast();
};
class Obj {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void* doIt(DynamicCaster_2b2c30*, U64);
};
void* __cdecl target(Obj* obj, void* p) {
    U64 v = getValue(p);
    DynamicCaster_2b2c30 caster;
    return obj->doIt(&caster, v);
}