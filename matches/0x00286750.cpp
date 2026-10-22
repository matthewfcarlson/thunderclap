typedef unsigned __int64 U64;
extern U64 __cdecl getValue(void*);
class DynamicCaster_286750 {
  public:
    virtual void f();
    DynamicCaster_286750() {}
};
class Inventory {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual int load(DynamicCaster_286750*, U64);
};
int __cdecl FUN_00286750(Inventory* inv, void* p) {
    U64 v = getValue(p);
    DynamicCaster_286750 caster;
    return inv->load(&caster, v);
}
