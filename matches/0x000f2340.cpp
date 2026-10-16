class Caster {
  public:
    virtual void Cast();
};
class Inventory {
  public:
    virtual void F0();
    virtual void F1();
    virtual void F2();
    virtual void Load(Caster*, __int64);
};
extern "C" __int64 __cdecl Lookup(void*);
void __cdecl Target(Inventory* inv, void* item) {
    __int64 id = Lookup(item);
    Caster caster;
    inv->Load(&caster, id);
}