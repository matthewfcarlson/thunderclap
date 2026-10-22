class DynamicCaster_c9ba0 {
  public:
    virtual void cast();
};
class Obj {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual int d(DynamicCaster_c9ba0*, __int64);
};
extern "C" __int64 FUN_0027b020(void*);
int target(Obj* obj, void* input) {
    __int64 p = FUN_0027b020(input);
    DynamicCaster_c9ba0 caster;
    return obj->d(&caster, p);
}