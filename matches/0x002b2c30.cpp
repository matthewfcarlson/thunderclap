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
extern "C" void* __cdecl FUN_002b2c30(void * obj, void* p) {
    U64 v = getValue(p);
    DynamicCaster_2b2c30 caster;
    return ((Obj *)obj)->doIt(&caster, v);
}