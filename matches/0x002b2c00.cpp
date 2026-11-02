class DynamicCaster_2b2c00 {
  public:
    virtual void cast();
};
class Inventory {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void* find(DynamicCaster_2b2c00*, __int64);
};
extern __int64 __cdecl getKey(void*);
extern "C" void* __cdecl FUN_002b2c00(void * inv, void* name) {
    __int64 key = getKey(name);
    DynamicCaster_2b2c00 caster;
    return ((Inventory *)inv)->find(&caster, key);
}