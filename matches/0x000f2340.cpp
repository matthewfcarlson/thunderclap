class DynamicCaster_f2340 {
  public:
    virtual void Cast();
};
class Inventory {
  public:
    virtual void F0();
    virtual void F1();
    virtual void F2();
    virtual int Load(DynamicCaster_f2340*, __int64);
};
extern "C" __int64 __cdecl Lookup(void*);
int __cdecl Target(Inventory* inv, void* item) {
    __int64 id = Lookup(item);
    DynamicCaster_f2340 caster;
    return inv->Load(&caster, id);
}