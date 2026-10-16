class Caster {
  public:
    virtual void cast();
};
class Inventory {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void* find(Caster*, __int64);
};
extern __int64 __cdecl getKey(void*);
void* __cdecl FUN_002b2c00(Inventory* inv, void* name) {
    __int64 key = getKey(name);
    Caster caster;
    return inv->find(&caster, key);
}