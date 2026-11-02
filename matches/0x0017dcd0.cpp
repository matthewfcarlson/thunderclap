class Caster {
  public:
    virtual void cast();
};
struct Owner {
    void add(void*);
};
extern "C" void* __cdecl find(int, Caster*);
extern "C" void __cdecl FUN_0017dcd0(Owner* owner, int id) {
    Caster caster;
    owner->add(find(id, &caster));
}