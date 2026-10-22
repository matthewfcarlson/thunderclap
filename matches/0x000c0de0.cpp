class DynamicCaster_c0de0 {
  public:
    virtual void Cast();
};
class Obj {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual int f3(DynamicCaster_c0de0*, __int64);
};
extern __int64 helper(Obj*);
int target(Obj* obj, Obj* value) {
    __int64 a = helper(value);
    DynamicCaster_c0de0 caster;
    return obj->f3(&caster, a);
}