class Caster {
  public:
    virtual void Cast();
};
class Inventory {
  public:
    virtual void F0();
    virtual void F1();
    virtual void F2();
    virtual int Load(Caster*, __int64);
};
extern "C" __int64 __cdecl Lookup(void*);
int __cdecl Target(Inventory* inv, void* item) {
    __int64 id = Lookup(item);
    Caster caster;
    return inv->Load(&caster, id);
}