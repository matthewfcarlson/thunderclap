class DynamicCaster_f20f0 {
  public:
    virtual void a();
};
class Object {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d(DynamicCaster_f20f0*, void*, void*);
};
void FUN_000f20f0(Object* obj, void* x, void* y) {
    DynamicCaster_f20f0 caster;
    obj->d(&caster, x, y);
}